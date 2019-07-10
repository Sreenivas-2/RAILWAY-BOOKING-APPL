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
int key,success_count,fail_count,r;
sem_t mutex,a,b,c;
void *client(void *thread){
        int k=*(int *)thread;
        sem_wait(&a);
        int network_socket = socket(AF_INET, SOCK_STREAM, 0);
        sem_post(&a);
        if (network_socket < 0)
            cout << "ERROR opening clientsocket\n";
        struct sockaddr_in server_address;
        server_address.sin_family = AF_INET;
        server_address.sin_port = htons(9000);
        server_address.sin_addr.s_addr = INADDR_ANY;
        sem_wait(&b);
        int connect_socket = connect(network_socket, (struct sockaddr*)&server_address, sizeof(server_address));    // Connect to the server
        sem_post(&b);
        if (connect_socket == -1) {
            cout << "Error connecting socket\n";
            exit(1);
        }
        while(key==0)
            ;
        send(network_socket, "23\n", 50, 0);
        char confirm[4];
        recv(network_socket, &confirm, 4, 0);
        if(confirm[0]=='0'){
            sem_wait(&mutex);
            fail_count++;
            sem_post(&mutex);
        }
        else{
            sem_wait(&mutex);
            success_count++;
            sem_post(&mutex);
        }
        sem_wait(&c);
        key++;
        sem_post(&c);
        return NULL;
}
int main(){
    pthread_t t[1000];
    int k=1;
    sem_init(&mutex,0,1);
    sem_init(&a,0,1);
    sem_init(&b,0,1);
    sem_init(&c,0,1);
    for(int i=0;i<1000;i++)
        pthread_create(&t[0], NULL, client, (void *)&k);
    key=1;
    while(key!=1001)
        ;
    if((success_count==1)&&(fail_count==999))
        cout<<"Successfull\n"<<"Success_count:"<<success_count<<" fail_count:"<<fail_count<<"\n";
    else
        cout<<"Failed\n"<<"Success_count:"<<success_count<<" fail_count:"<<fail_count<<"\n";
    return 0;
}
