#include<iostream>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<unistd.h>
#include<fstream>
#include<arpa/inet.h>
#include<pthread.h>
#include<string.h>
#include<vector>
#include<semaphore.h>
using namespace std;
/*!
 * \brief The seatmatrix class
 */
struct seatmatrix {
    /*!
     * \brief seats[i] - Denotes the status of seat with ID i (whether the seat was booked already or not).
     */
    char seats[50];             // Stores status of seats
};
struct seatmatrix matrix[775];  // 5x5x31 permutations
/*!
 * \brief The accounts class
 */
struct accounts {                // Stores user details
    /*!
     * \brief username - Stores the username of USER. Each User have a unique username, we don't accept username which is already taken by another user.
     */
    char username[100];
    /*!
     * \brief name - Stores the name of USER.
     */
    char name[300];
    /*!
     * \brief contact - Stores the contact of USER.
     */
    char contact[12];
    /*!
     * \brief mail - Stores the mail of USER.
     */
    char mail[100];
    /*!
     * \brief password - Stores the password of USER.
     */
    char password[100];
    /*!
     * \brief v - Stores the Journey Details of USER.
     */
    vector<vector<string>> v;
    /*!
     * \brief seat - Stores the seats booked by the USER.
     */
    vector<vector<int>> seat;
};
vector<accounts> acc;                           // Vector of details of users
bool wait[775];
int server_socket, ctrin[775], ctrout[775];       // Variables for locking mechanism
sem_t in[775], out[775], wrt[775], mutex, rwmutex;  // Semaphores used to achieve mutual exclusion

char search(char username[100]) {                // Checks if username already exists in database
    int n = acc.size();
    for (int i = 0; i < n ; i++) {
        if (strcmp(acc[i].username, username) == 0)
            return '0';
    }
    return '1';
}

char searcha(char username[100], char password[100]) {    // checks if login details are correct
    int n = acc.size();
    for (int i = 0 ; i < n ; i++) {
        if ((strcmp(acc[i].username, username) == 0)&&(strcmp(acc[i].password, password) == 0))
            return '1';
    }
    return '0';
}

int find_profile(char username[100]) {    // Finds the index of corresponding user
    int n = acc.size();
    for (int i = 0; i < n ; i++) {
        if (strcmp(acc[i].username, username) == 0)
            return i;
    }
}
int finddestination(char origin[50], char destination[50], char date_time[20]) {   // Finds the index of corresponding seat matrix
    char datea[3];
    datea[0] = date_time[8];
    if (date_time[9] != ' ')
        datea[1] = date_time[9];
    int date = atoi(datea)-1, i, j;
    if (origin[0] == 'M')               //  If origin is Mumbai
        i = 0;
    else if (origin[0] == 'D')          //  If origin is Delhi
        i = 1;
    else if (origin[0] == 'C')          //  If origin is Chennai
        i = 2;
    else if (origin[0] == 'K')          //  If origin is Kolkata
        i = 3;
    else                                //  If origin is Banglore
        i = 4;
    if (destination[0] == 'M')          //  If destination is Mumbai
        j = 0;
    else if (destination[0] == 'D')     //  If destination is Delhi
        j = 1;
    else if (destination[0] == 'C')     //  If destination is Chennai
        j = 2;
    else if (destination[0] == 'K')     //  If destination is Kolkata
        j = 3;
    else                                //  If destination is Bangalore
        j = 4;
    return i*5*31+j*31+date;
}
void *client(void *arg) {
    listen(server_socket, 1);                               // listen for only 1 client socket
    int client_socket;
    client_socket = accept(server_socket, NULL, NULL);      // accepting a connection from client socket
    if (client_socket < 0) {
        cout << "ERROR in accepting client\n";
        exit(0);
    } else {
        cout << "Client connected\n";
    }
    char current_user[100];                                 // Variables to store the details of current user
    vector<int> current_user_seats;
    vector<string> vector;
    pthread_t t;
    int i = 1, date;
    pthread_create(&t, NULL, client, (void *)&i);               // Another thread for other client
    int newdata1 = 1, newdata2 = 1, newdata3 = 1, newdata4 = 1, newdata5 = 1;
    char book[50];
    while (1) {
        if (i == 1) {                                               // i=1 implies client is in dialog 1
            while (1) {
                char username[100], password[100];
                newdata1 = recv(client_socket, &username, 100, 0);  // recieve login usernmame
                newdata2 = recv(client_socket, &password, 100, 0);  // recieve login password
                strncpy(current_user, username, 100);
                if (newdata2 > 0) {                                          // newdata2=0 implies client is disconnected
                    if ((username[0] == '#')&&(password[0] == '#')) {       // checking if create new account is chosen
                        i = 0;
                        break;
                    }
                    if (searcha(username, password) == '1') {        // Checking if login details are correct
                        send(client_socket, "1\n", 4, 0);          // Sending keyword to client corresponding to correct login details
                        i = 3;                                    // Go to third dialog part of code
                        break;
                    } else {
                        send(client_socket, "0\n", 4, 0);          // Sending keyword to client corresponding to wrong login details
                    }
                } else {
                    break;                                      // Client is disconnected
                }
            }
        }
        if (newdata2 <= 0) {
            break;
        }
        if (i == 0) {                                               // Create new account option is chosen
            while (1) {
                char usernamea[100], contact[12], mail[100], password[100], name[300];
                usernamea[0] = contact[0] = mail[0] = password[0] = '\0';
                newdata1 = recv(client_socket, &usernamea, 100, 0);  // recieves username
                newdata2 = recv(client_socket, &contact, 12, 0);     // recieves contact no
                newdata3 = recv(client_socket, &mail, 100, 0);       // recieves mail id
                newdata4 = recv(client_socket, &password, 100, 0);   // recieves password
                newdata5 = recv(client_socket, &name, 300, 0);       // recievs name
                if (newdata5 <= 0)                                 // Checking if client is disconnected
                    break;
                if ((usernamea[0] == '#')&&(contact[0] == '#')&&(mail[0] == '#')&&(password[0] == '#')&&(name[0 ]== '#')) {      // checking if back option is chosen
                    i = 1;
                    break;
                }
                if (search(usernamea) == '1') {                         // checking if username already exists
                    sem_wait(&rwmutex);                             // Lock for writing part
                    acc.push_back(accounts());                      // Creating new user in database
                    strcpy(acc[acc.size()-1].username, usernamea);   // Copying all user details
                    strcpy(acc[acc.size()-1].password, password);
                    strcpy(acc[acc.size()-1].contact, contact);
                    strcpy(acc[acc.size()-1].mail, mail);
                    strcpy(acc[acc.size()-1].name, name);
                    strncpy(current_user, usernamea, 100);
                    sem_post(&rwmutex);                             // Release lock after writing
                    send(client_socket, "1\n", 4, 0);                  // Sending keyword to client corresponding to successfull account creation
                    i = 3;                                            // Go for Journey Details Dialog
                    break;
                } else {
                    send(client_socket, "0\n", 4, 0);                  // Sending keyword to client corresponding to username already taken
                }
            }
        }
        if (newdata5 <= 0)
            break;                                                  // client is disconnected
        if (i == 1)
            continue;
        if (i == 3) {
            char origin[50], destination[50], date_time[20];
            newdata1 = recv(client_socket, &origin, 50, 0);         // Recieves origin place of train
            newdata2 = recv(client_socket, &destination, 50, 0);    // Recieves destination place of train
            newdata3 = recv(client_socket, &date_time, 20, 0);      // Recieves date and time of train
            if (newdata3 > 0) {                                     // Checking if client is disconnected
                if ((origin[0] == '#') && (destination[0] == '#') && (date_time[0] == '#')) {    // Checking if logout is chosen
                    i = 1;
                    continue;
                } else {
                    vector.clear();
                    int index = find_profile(current_user);
                    vector.push_back(origin);
                    vector.push_back(destination);
                    vector.push_back(date_time);                    // Storing the journey details of current user
                    date = finddestination(origin, destination, date_time);     // Finds index of seat matrix for chosen
                    i = 4;
                }
            } else {
                break;
            }
        }
        if (newdata3 <= 0)
            break;
        while (i == 4) {
            sem_wait(&in[date]);                        // Algorithm for reader thread to avoid conflicts with writer thread
            ctrin[date]++;
            sem_post(&in[date]);
            send(client_socket, &(matrix[date].seats), 50, 0);
            sem_wait(&out[date]);
            ctrout[date]++;
            if ((wait[date] == 1)&&(ctrin[date] == ctrout[date]))
                sem_post(&wrt[date]);
            sem_post(&out[date]);
            newdata1 = recv(client_socket, &book, 50, 0);    // Recieves selected seats to be booked
            if (newdata1 <= 0)                             // Checking if client is disconnected
                break;
            if (book[0] == '#') {                           // Checking if logout is chosen
                i = 1;
                continue;
            }
            if (book[0] == 'z') {                           // Checking if back is chosen
                i = 3;
                continue;
            }
            int s = 0;
            sem_wait(&in[date]);                    // Algorithm for writer thread to achieve mutual exclusion
            sem_wait(&out[date]);
            if (ctrin[date] == ctrout[date]) {
                sem_post(&out[date]);
            } else {
                wait[date] = 1;
                sem_post(&out[date]);
                sem_wait(&wrt[date]);
                wait[date] = 0;
            }
            while ((book[s] != '\n')&&(matrix[date].seats[book[s]-48] == '0'))   // Checking if selected seats are empty
                s++;
            if (book[s] == '\n') {                                            // All selected seats are available
                s = 0;
                while (book[s] != '\n') {
                    matrix[date].seats[book[s]-48] = '1';                     // Booking seats
                    current_user_seats.push_back(book[s]-47);                  // Storing the booked seats of current user
                    s++;
                }
                sem_post(&in[date]);
                send(client_socket, "w\n", 4, 0);                              // w is the keyword corresponding to booking is successfull
                i = 5;                                                           // Go to payment section
            } else {
                sem_post(&in[date]);
                send(client_socket, "v\n", 4, 0);                              // v is the keyword corresponding to booking failed
            }
        }
        if (newdata1 <= 0)
            break;
        if (i == 5) {
            char j[4];
            newdata1 = recv(client_socket, &j, 4, 0);
            if (newdata1 <=0 )                             // Checking if client is disconnected
                break;
            i = 4;
            if (j[0] == 'x')  {                             // x is the keyword corresponding to confirm payment
                int index = find_profile(current_user);
                acc[index].seat.push_back(current_user_seats);      // Copying the current user details to the account details of the user, if the booking is confirmed
                acc[index].v.push_back(vector);
                current_user_seats.clear();
                continue;
            }
            if (j[0] == 'y') {                              // y is the keyword corresponding to back 
                current_user_seats.clear();
                int s = 0;
                sem_wait(&in[date]);                    // Algorithm for writer thread to achieve mutual exclusion
                sem_wait(&out[date]);
                if (ctrin[date] == ctrout[date]) {
                    sem_post(&out[date]);
                } else {
                    wait[date] = 1;
                    sem_post(&out[date]);
                    sem_wait(&wrt[date]);
                    wait[date] = 0;
                }
                while (book[s] != '\n') {
                    matrix[date].seats[book[s]-48] = '0';                     // Cancelling seats as session is timed out
                    s++;
                }
                sem_post(&in[date]);
            }
        }
    }
    pthread_exit(NULL);
}
int main() {
    int exit = 0;
    server_socket = socket(AF_INET, SOCK_STREAM, 0);                                          // socket for server created
    if (server_socket < 0)
        cout << "ERROR opening serversocket\n";
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9000);                                                    // Port of server
    server_address.sin_addr.s_addr = inet_addr("192.168.126.172");                                              // Address of server
    cout << "Server socket is " << server_socket << "\n";
    int k = bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address));   // binding the server socket to the ports
    pthread_t t;
    sem_init(&mutex, 0, 1);                                                                    // Initialising semaphores
    sem_init(&rwmutex, 0, 1);
    ifstream fin_s,fin_d;
    fin_d.open("details.txt");
    if (!fin_d){                // If file is not present, create one
        ofstream fout;
        fout.open("details.txt");
        fout.close();
        fin_d.open("details.txt");
    }
    char ch;
    string line;
    fin_d >> ch;
    while(!fin_d.eof())                     // Reading the data from data-base (details.txt)
    {
        fin_d >> line;
        acc.push_back(accounts());
        fin_d >> line;
        line+='\n';
        strcpy(acc[acc.size()-1].username, line.c_str());
        fin_d >> line;
        line+='\n';
        strcpy(acc[acc.size()-1].password, line.c_str());
        fin_d >> line;
        strcpy(acc[acc.size()-1].name, line.c_str());
        fin_d >> line;
        strcpy(acc[acc.size()-1].contact, line.c_str());
        fin_d >> line;
        strcpy(acc[acc.size()-1].mail, line.c_str());
        fin_d >> ch;
        while(ch != '(' && !fin_d.eof()) {
            vector<char> v1;
            vector<char> v2;
            vector<char> v3;
            vector<string> final_vector;
            while(ch != '-') {
                v1.push_back(ch);
                fin_d >> ch;
            }
            fin_d >> ch;
            string temp1(v1.begin(), v1.end());
            final_vector.push_back(temp1);
            while(ch != '-') {
                v2.push_back(ch);
                fin_d >> ch;
            }
            fin_d >> ch;
            string temp2(v2.begin(), v2.end());
            final_vector.push_back(temp2);
            int var = 0;
            while(ch != '-') {
                if((var != 3)&&(var != 6))
                    v3.push_back(ch);
                else if(var == 3) {
                    v3.push_back(' ');
                    v3.push_back(ch);
                }
                else {
                    v3.push_back(' ');
                    v3.push_back(ch);
                    char qwa[8];
                    var=0;
                    do {
                        fin_d >> qwa[var];
                        var++;
                    }
                    while(qwa[var-1] != '-');
                    if(var == 5) {
                        v3.push_back(' ');
                        for(int i = 0; i < 4; i++)
                            v3.push_back(qwa[i]);
                    }
                    else {
                        v3.push_back(qwa[0]);
                        v3.push_back(' ');
                        for(int i = 1; i < 5; i++)
                            v3.push_back(qwa[i]);
                    }
                    break;
                }
                fin_d >> ch;
                var++;
            }
            fin_d >> ch;
            string temp3(v3.begin(), v3.end());
            final_vector.push_back(temp3);
            acc[acc.size()-1].v.push_back(final_vector);
            vector <int> temp;
            while(ch != '+' && !fin_d.eof()) {
                vector<char> v;
                while(ch != '-')
                {
                    v.push_back(ch);
                    fin_d >> ch;
                }
                string s(v.begin(), v.end());
                temp.push_back(stoi(s));
                fin_d >> ch;
            }
            fin_d >> ch;
            acc[acc.size()-1].seat.push_back(temp);
        }
    }
    fin_d.close();
    fin_s.open("seats.txt");
    if(!fin_s){                     // If file is not present, create one
        ofstream fout;
        fout.open("seats.txt");
        for (int i = 0; i < 775; i++)
            fout<<"000000000000000000000000000000000000000000000000\n";         // Initializing the seat matrix
        fout.close();
        fin_s.open("seats.txt");
    }
    for (int i = 0; i < 775; i++) {
        string line;
        getline(fin_s, line);                                                                 // Reading the previous seat_matrix from the file
        strcpy(matrix[i].seats, line.c_str());
        wait[i] = 0;
        sem_init(&in[i], 0, 1);                                                               // Initialising semaphores
        sem_init(&out[i], 0, 1);
        sem_init(&wrt[i], 0, 0);
    }
    fin_s.close();
    pthread_create(&t, NULL, client,NULL);                                               // Creating thread for client
    scanf("%d", &exit);
    if(exit == 1)
    {
        ofstream fout_d,fout_s;                                                                // Opening the files to write the present data
        fout_d.open("details.txt");
        for (int i = 0; i < acc.size() ; i++) {                                                   // Writing the updated_details of every user
            fout_d << "(" << i+1 << ")"<<endl;
            fout_d << acc[i].username;
            fout_d << acc[i].password;
            fout_d << acc[i].name << endl;
            fout_d << acc[i].contact << endl;
            fout_d << acc[i].mail << endl;
            for (int j = 0; j < acc[i].v.size() ; j++) {
                fout_d << acc[i].v[j][0] << "-" << acc[i].v[j][1] << "-" << acc[i].v[j][2] << "-";
                for (int  k = 0; k < acc[i].seat[j].size(); k++) {
                    fout_d << acc[i].seat[j][k] << "-";
                }
                fout_d << "+" << endl;
            }
            fout_d << endl;
        }
        fout_s.open("seats.txt");
        for (int i = 0; i < 775 ; i++)                                                        // Writing the updated seat_matrix to the file
            fout_s << matrix[i].seats << endl;
        fout_d.close();
        fout_s.close();
        return 0;
    }
    return 0;
}
