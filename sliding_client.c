#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
int main()
{
    int client_socket, len, choice;
    char str[20], err[20];
    client_socket = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(5000);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    connect(client_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));
    while (1)
    {
        read(client_socket, str, 20);
        if (!strcmp(str, "exit"))
        {
            printf("Exiting\n");
            break;
        }
        printf("\n\nReceived : %s \n1.Do u want to report an error(1-Yes 0-No) : ", str);
        scanf("%d", &choice);
        if (!choice)
            write(client_socket, "-1", sizeof("-1"));
        else
        {
            printf("Enter the sequence no of the frame where error has occured : ");
            scanf("%s", err);
            write(client_socket, err, sizeof(err));
        }
        printf("\n");
    }
}