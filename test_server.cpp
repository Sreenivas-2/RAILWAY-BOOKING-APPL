#include<iostream>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include <unistd.h>
#include<arpa/inet.h>
#include<pthread.h>
#include<string.h>
#include<vector>
#include<semaphore.h>
using namespace std;
int wait,ctrin,ctrout,server_socket;
sem_t in, out, wrt;  // Semaphores used to achieve mutual exclusion
char seats[50]="000000000000000000000000000000000000000000000000\n";
void *client(void *threadid) {
    listen(server_socket, 1);                               // listen for only 1 client socket
    int client_socket;
    client_socket = accept(server_socket, NULL, NULL);      // accepting a connection from client socket
    if (client_socket < 0) {
        cout << "ERROR in accepting client\n";
        exit(0);
    }
    pthread_t t;
    int i = 1;
    pthread_create(&t, NULL, client, (void *)&i);
    char book[50];
    recv(client_socket, &book, 50, 0);
    int s = 0;
    sem_wait(&in);                    
    sem_wait(&out);
    if (ctrin == ctrout) {
        sem_post(&out);
    } else {
        wait = 1;
        sem_post(&out);
        sem_wait(&wrt);
        wait = 0;
    }
    while ((book[s] != '\n')&&(seats[book[s]-48] == '0'))   // Checking if selected seats are empty
        s++;
    if (book[s] == '\n') {                                            // All selected seats are available
        s = 0;
        while (book[s] != '\n') {
            seats[book[s]-48] = '1';                     // Booking seats
            s++;
        }
        sem_post(&in);
        send(client_socket, "1\n", 4, 0);
    } else {
        sem_post(&in);
        send(client_socket, "0\n", 4, 0);
    }
    pthread_exit(NULL);
}
int main() {
    server_socket = socket(AF_INET, SOCK_STREAM, 0);                                          // socket for server created
    if (server_socket < 0)
        cout << "ERROR opening serversocket\n";
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9000);                                                    // Port of server
    server_address.sin_addr.s_addr = INADDR_ANY;                                              // Address of server
    cout << "Server socket is " << server_socket << "\n";
    int k = bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address));   // binding the server socket to the ports
    pthread_t t;
    int i=1;
    wait = 0;
    sem_init(&in, 0, 1);                                                               // Initialising semaphores
    sem_init(&out, 0, 1);
    sem_init(&wrt, 0, 0);
    pthread_create(&t, NULL, client, (void *)&i);                                             // Creating thread for client
    pthread_exit(NULL);
    return 0;
}
