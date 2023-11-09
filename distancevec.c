#include <stdio.h>
struct node
{
    unsigned dist[50];
    unsigned from[50];
} rt[10];
void main()
{
    int graph[50][50], n,count;
    printf("enter no.of vertices: ");
    scanf("%d", &n);
    printf("enter cost matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
            graph[i][i] = 0;
            rt[i].dist[j] = graph[i][j];
            rt[i].from[j] = j;
        }
    }
    do
    {
        count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    if (rt[i].dist[j] > graph[i][k] + rt[k].dist[j])
                    {
                        rt[i].dist[j] = rt[i].dist[k] + rt[k].dist[j];
                        rt[i].from[j] = k;
                        count++;
                    }
                }
            }
        }
    } while (count != 0);
    for(int i=0;i<n;i++){
        printf("for router %d\n",i+1);
        printf("Node | via | distance\n");
        for(int j=0;j<n;j++){
            printf("%5d|%5d|%5d\n",j+1,rt[i].from[j]+1,rt[i].dist[j]);
        }
        printf("\n\n");
    }
}