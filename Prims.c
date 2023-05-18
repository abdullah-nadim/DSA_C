#include <stdio.h>
#include<stdbool.h>

int cost[100][100];

int min_Key(int key[], int visited[],int ver)
{
    int min = 9999, min_index;

    for (int i = 0; i < ver; i++) {
        if (visited[i] == 0 && key[i] < min) {
            min = key[i];
			min_index = i;
        }
    }
    return min_index;
}


int print_MST(int parent[], int ver)
{
    int minCost=0;
	printf("Edge \tWeight\n");
    for (int i = 1; i< ver; i++) {
		printf("%d - %d    %d\n",parent[i],i,cost[i][parent[i]]);

		minCost+=cost[i][parent[i]];
    }
	printf("Total cost is %d",minCost);
}

void find_MST(int ver)
{
    int parent[ver], key[ver];
    int visited[ver];

    for (int i = 0; i< ver; i++) {
        key[i] = 9999;
        visited[i] = 0;
        parent[i]=-1;
    }

    key[0] = 0;


    for (int i = 0; i < ver - 1; i++)
    {

        int j = min_Key(key, visited,ver);

        visited[j] = 1;

        for (int k = 0; k < ver; k++)
        {

            if (cost[j][k]!=0 && visited[k] == 0 && cost[j][k] < key[k])
            {
                parent[k] = j;
                key[k] = cost[j][k];
            }
        }
    }


	print_MST(parent, ver);
}

int main()
{


    int edg,ver,wght,st,en;
    printf("Enter no of vertices:\n");
    scanf("%d", &ver);
    printf("Enter no of edges:\n");
    scanf("%d",&edg);
    for(int i=0; i<edg;i++)
    {
        printf("Enter the start and end vertex of the edges and weight: \n");
        scanf("%d %d %d",&st,&en,&wght);
        cost[st][en]=wght;
        cost[en][st]=wght;
    }

    find_MST(ver);

}
