#include <stdio.h>
int XOR(int a, int b)
{
    if (a == b)
        return 0;
    else
        return 1;
}
void main()
{
    int data[100], div[50], dl, dil, i, j;
    int newdata[100], crc[50];
    printf("enter data length: ");
    scanf("%d", &dl);
    printf("enter data: ");
    for (i = 0; i < dl; i++)
    {
        scanf("%d", &data[i]);
    }
    printf("enter divisor length: ");
    scanf("%d", &dil);
    printf("enter divisor: ");
    for (i = 0; i < dil; i++)
    {
        scanf("%d", &div[i]);
    }
    for (i = 0; i < dl + dil - 1; i++)
    {
        (i < dl) ? (newdata[i] = data[i]) : (newdata[i] = 0);
    }
    for (j = 0; j <= dl; j++)
    {
        for (i = 0; i < dil; i++)
        {
            crc[i] = newdata[i + j];
            if (crc[0] == 1)
            {
                newdata[i + j] = XOR(newdata[i + j], div[i]);
            }
            else
            {
                newdata[i + j] = XOR(newdata[i + j], 0);
            }
        }
    }
    printf("the crc is: ");
    for (i = 0; i < dil - 1; i++)
    {
        printf("%d ", crc[i]);
    }
    int recv[100], rem[50];
    int error = 0;
    printf("\n enter received data: ");
    for (i = 0; i < (dl + dil - 1); i++)
    {
        scanf("%d", &recv[i]);
    }
    for (j = 0; j <= dl; j++)
    {
        for (i = 0; i < dil; i++)
        {
            rem[i] = recv[i + j];
            if (rem[0] == 1)
            {
                recv[i + j] = XOR(recv[i + j], div[i]);
            }
            else
            {
                recv[i + j] = XOR(recv[i + j], 0);
            }
        }
    }
    for (i = 0; i < dil - 1; i++)
    {
        if (rem[i] != 0)
        {
            error = 1;
        }
    }
    if (error == 1)
    {
        printf("there is error in the data received");
    }
    else
    {
        printf("no error");
    }
}