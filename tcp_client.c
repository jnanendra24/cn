#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int client_socket;
    char message[100];

    // Create a socket for the client
    client_socket = socket(AF_INET, SOCK_STREAM, 0);

    // Define the server address
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9002);
    server_address.sin_addr.s_addr = INADDR_ANY;

    // Connect to the server
    int connection_status = connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address));
    if (connection_status == -1) {
        printf("Error connecting to the server.\n");
        exit(1);
    }

    // Send a message to the server
    strcpy(message, "Hello from client!");
    send(client_socket, message, sizeof(message), 0);

    // Receive a response from the server
    recv(client_socket, message, sizeof(message), 0);
    printf("Server: %s\n", message);

    // Close the socket
    close(client_socket);

    return 0;
}