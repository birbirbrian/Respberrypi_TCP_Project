#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>

//server

int main(){

    char server_message[265] = "You have reached the server!";

    //creat a server socket

    int server_socket;
    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1){
        printf("Fail to create a socket.");
    }

    //define the server address

    struct sockaddr_in server_address;

        server_address.sin_family = AF_INET;
        server_address.sin_port = htons(9000);
        server_address.sin_addr.s_addr = INADDR_ANY;

    //bind the socket to our secified IP or port

    bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address));


    listen(server_socket, 5);

    while(1){

        int client_socket;
        client_socket = accept(server_socket,NULL, NULL);

        //send the message
        send(client_socket, server_message, sizeof(server_message), 0);
    }



    //close the soclet

    close(server_socket);

    return 0;
}
