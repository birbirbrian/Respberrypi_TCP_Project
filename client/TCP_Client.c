#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>

//client


int main(){
    //create a socket

    int network_socket;
    network_socket = socket(AF_INET,SOCK_STREAM,0);

    struct sockaddr_in server_address;
        server_address.sin_family = AF_INET;
        server_address.sin_port = htons(9000);
        server_address.sin_addr.s_addr = INADDR_ANY;

    int connect_status = connect(network_socket, (struct sockaddr *) &server_address, sizeof(server_address));


    //check error with the connection

    if (connect_status == -1){
        printf("There was a connection error \n\n");
    }

    //recieve data from server

    char server_response [256];
    recv(network_socket, &server_response, sizeof(server_response), 0);

    //print out the server response

    printf("The server snet the data : %s\n", server_response);

    //close the socket

    close(network_socket);


    return 0;
}
