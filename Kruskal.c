#include <stdio.h>
#include<stdbool.h>

int V,E;
int parent[100];
int cost [1000][10000];
int find(int i)
{

	while (parent[i] != i)
        i = parent[i];
    return i;
}

void union1(int i, int j)
{
	int a = find(i);
	int b = find(j);
	parent[a] = b;
}

void kruskalMST()
{
	int mincost = 0;
	int edge_count = 0;
	while (edge_count < V - 1)
    {
		int min = 9999, a = -1, b = -1;
		for (int i = 0; i < V; i++) {
			for (int j = 0; j < V; j++)
            {
				if (find(i) != find(j) && cost[i][j] < min)
				{
					min = cost[i][j];
					a = i;
					b = j;
				}
			}
		}

		union1(a, b);
		int temp = edge_count++;
        printf("Edge %d: (%d %d ) cost: %d\n",temp,a,b,min);
		mincost += min;
	}
	printf("Minimum cost= %d",mincost);
}

int main()
{
    int wght,st,en;
    printf("Enter no of vertices:\n");
    scanf("%d", &V);
    printf("Enter no of edges:\n");
    scanf("%d",&E);
    for(int i=0;i<V;i++)
    {
        for(int j=0; j<V; j++)
        {
            cost[i][j]= 9999;
        }
    }
    for(int i=0; i<E;i++)
    {
        printf("Enter the start and end vertex of the edges and weight: \n");
        scanf("%d %d %d",&st,&en,&wght);
        cost[st][en]=wght;
        cost[en][st]=wght;
    }
    for (int i = 0; i < V; i++)
        parent[i] = i;
	kruskalMST();
	return 0;
}
