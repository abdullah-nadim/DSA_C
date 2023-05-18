#include <stdio.h>
int graph[100][100];
void dfs(int ver,int edge)
{
    int stack[10],visit[10];
    int v,top=0;
    printf("\nEnter the initial vertex to start the DFS traversal with: ");
    scanf("%d", &v);
    printf("\nThe DFS traversal on the given graph is : \n");
    printf("%d\t",v);

    for(int i=1;i<ver;i++)
    {
        for(int j=ver;j>=0;j--)
        {
            if(graph[v][j]==1&& visit[j]!=1)
            {
                visit[j]=1;
                stack[top]=j;
                top++;
            }
        }
        v=stack[--top];
        printf("%d\t",v);
    }
}


int main()
{
    int edg,ver,st,en;
    printf("Enter no of vertices:\n");
    scanf("%d",&ver);
    printf("Enter no of edges:");
    scanf("%d",&edg);
    for(int i=0; i<edg;i++)
    {
        printf("Enter the start and end vertex of the edges: \n");
        scanf("%d %d",&st,&en);
        graph[st][en]=1;
    }
    dfs(ver,edg);
}
