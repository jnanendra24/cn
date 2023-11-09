#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int server_socket, client_socket;
    char message[100];

    // Create a socket for the server
    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    // Define the server address
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9002);
    server_address.sin_addr.s_addr = INADDR_ANY;

    // Bind the socket to the specified IP and port
    bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address));

    // Listen for incoming connections
    listen(server_socket, 5);

    printf("Server is listening...\n");

    // Accept a connection from a client
    client_socket = accept(server_socket, NULL, NULL);

    // Receive data from the client
    recv(client_socket, message, sizeof(message), 0);
    printf("Client: %s\n", message);

    // Send a response to the client
    strcpy(message, "Hello from server!");
    send(client_socket, message, sizeof(message), 0);

    // Close the sockets
    close(server_socket);
    close(client_socket);

    return 0;
}