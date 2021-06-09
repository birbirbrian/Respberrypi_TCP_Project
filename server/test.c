#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>


//server

int main(){

    char server_message[265] = "You have reached the server!";

    //creat a server socket

    int server_socket;
    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    //define the server address

    struct sockaddr_in server_address;

        server_address.sin_family = AF_INET;
        server_address.sin.port = htons(9000);
        server_address.sin_addr.s_addr = "192.168.0.111";

    //bind the socket to our secified IP or port

    printf("size of server_address = %d", sizeof(server_address));


    return 0;
}
