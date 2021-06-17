#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#define PORT 8080

int createSocket(){
    int network_socket;
    if ((network_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }
    return network_socket;
}

void sqlCmdCreate(int network_socket){
    char package[300]={0};
    char command[20]={0};
    scanf(" %s", command);

    if(strcmp(command, "DATABASE") == 0){
        char dbName[255]={0};
        scanf(" %s", dbName);

        strcpy(package, "create_db ");
        strcat(package, dbName);


        send(network_socket , package , strlen(package) , 0);
    }
}

int main(int argc, char const *argv[]) {

    /*SOCKET CONFIGURATION*/
    struct sockaddr_in address;

    int network_socket = createSocket();
    int valread;

    struct sockaddr_in serv_addr;

    memset(&serv_addr, '0', sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    if (connect(network_socket, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }

    /*SOCKET CONFIGURATION END*/

    while(1){
        char command[20]={0};
        command[0] = '\0';
        scanf(" %s", command);

        if(strcmp(command, "CREATE") == 0){
            sqlCmdCreate(network_socket);
            continue;
        }

        send(network_socket , "failed" , strlen("failed") , 0);
    }

    /*send(network_socket , hello , strlen(hello) , 0 );*/
    /*printf("Hello message sent\n");*/
    /*valread = read( network_socket , buffer, 1024);*/
    /*printf("%s\n",buffer );*/
    return 0;
}

