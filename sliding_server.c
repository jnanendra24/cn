#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#define SIZE 4
int main()
{
    int server_socket, client_socket, len, i, j, status;
    char str[20], frame[20], temp[20], ack[20];
    struct sockaddr_in saddr, caddr;

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0)
        perror("Error");
    bzero(&saddr, sizeof(saddr));
    saddr.sin_family = AF_INET;
    saddr.sin_addr.s_addr = htonl(INADDR_ANY);
    saddr.sin_port = htons(5000);
    bind(server_socket, (struct sockaddr *)&saddr, sizeof(saddr));

    listen(server_socket, 5);
    printf("server listening!..");

    client_socket = accept(server_socket, NULL, NULL);
    printf("Enter the text to send : ");
    scanf("%s", str);
    i = 0;
    while (i < strlen(str))
    {
        memset(frame, 0, 20);
        strncpy(frame, str + i, SIZE);
        len = strlen(frame);
        for (j = 0; j < len; j++)
        {
            sprintf(temp, "%d", i + j);
            strcat(frame, temp);
        }
        printf("Frame transmitted : %s\n", frame);
        write(client_socket, frame, sizeof(frame));
        read(client_socket, ack, 20);
        sscanf(ack, "%d", &status);

        if (status == -1)
        {
            printf("-Transmission is successful. \n");
            i = i + SIZE;
        }
        else
        {
            printf("-Received error in %d. \n", status);
            i = status;
        }
        printf("\n");
    }

    write(client_socket, "exit", sizeof("exit"));
    printf("Exiting\n");
    sleep(2);
    close(client_socket);
    close(server_socket);
}