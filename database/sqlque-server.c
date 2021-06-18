#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <netinet/in.h>
#include <unistd.h>
#define PORT 8080

void exit_on_failed_fork(pid_t child_id) {
    if (child_id < 0)
        exit(EXIT_FAILURE);
}

void create_directory(char destination_dir[100]) {

    //create dir
    char *argv[] = {"mkdir", "-p", destination_dir, NULL};
    execv("/bin/mkdir", argv);
}

int main(int argc, char const *argv[]) {
    /*SOCKET CONFIGURATION*/
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char *hello = "Hello from server";

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    /*if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {*/
        /*perror("setsockopt");*/
        /*exit(EXIT_FAILURE);*/
    /*}*/

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    /*SOCKET CONFIGURATION END */

    while(1){
        char all_input[10][200];
        char buffer[1024] = {0};
        valread = read(new_socket, buffer, 1024);

        char * splitted_input = strtok(buffer, " ");

        printf(" full %s\n",buffer);
        printf(" splitted\n");

        int counter = 0;
        while(splitted_input != NULL){
            printf(" %s\n",splitted_input);

            strcpy(all_input[counter], splitted_input);
            splitted_input = strtok(NULL, " ");
            counter ++;
        }

        printf(" udah split\n");
        printf("%s -> %ld \n", all_input[0], strlen(all_input[0]));
        printf("%s\n", all_input[1]);

        int execute_child_id = fork();
        exit_on_failed_fork(execute_child_id);

        char database_path[100] = "./databases";

        if(execute_child_id == 0){
            if(strcmp(all_input[0], "create_db") == 0){
                strcat(database_path, "/");
                strcat(database_path,all_input[1]);
                create_directory(database_path);
            }
        }
    }
    return 0;
}
