#include<stdio.h>
#include<stdbool.h>
#include<limits.h>
int V;
int minDistance(int dist[],bool visited[]){
    int minVertex = 0;
    for(int i=1;i<V;i++){
        if(dist[i] < dist[minVertex] && !visited[i]){
            minVertex = i;
        }
    }
    return minVertex;
}
void dijkstra(int graph[V][V],int source){
    int dist[V],i;
    bool visited[V];

    for(i=0;i<V;i++){
        dist[i] = INT_MAX;
        visited[i] = false;
    }
    dist[source] = 0;

    for(i=0;i<V-1;i++){
        int u = minDistance(dist,visited);
        visited[u] = true;

        for(int v =0;v<V;v++){
            if(!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]){
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    printf("vertex | distance from src\n");
    for(int i=0;i<V;i++){
        printf("%d      | %d\n",i,dist[i]);
    }
}
void main(){
    int graph[50][50],source;
    printf("enter no.of Vertices: ");
    scanf("%d",&V);
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            scanf("%d",&graph[i][j]);
        }
    }
    printf("enter source: ");
    scanf("%d",&source);
    dijkstra(graph,source);
}
