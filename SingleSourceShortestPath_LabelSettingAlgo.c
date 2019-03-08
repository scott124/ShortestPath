#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
// #################################
// Perpose: Find shortest path of a vertix v to others vertix who all belong to a graph G
// Howto  : Build shortest path tree from v
// 
// Algo
//      A. Add start point into shortest path tree, and only start point conatin in at this moment.
//      B. Repeat following step V-1 times
//          a. Find a vertix b not in shortest path tree and close to start point
//          b. Add b into shortest path tree.
#define SIZE 9
int w[SIZE][SIZE]; // adjacency matrix record weight
int dist[SIZE];    // shortest path from v to others
int parent[SIZE];  // record parent of each vertixs of shortest path tree
bool visit[SIZE];  // record whether vertix v is in shortest path tree

void init()
{
    for (int i=0; i<SIZE; i++) visit[i] = false;

    printf("Reading map... \n");

    int tmp;
    for (int i=0; i<SIZE; i++)
        for (int j=0; j<SIZE; j++) {
            scanf("%d", &tmp);
            w[i][j] = (tmp == 0)?1e9:tmp; 
        }

    printf("done\n\n\n");
}
void labelSetting(int source)
{
    dist[source]   = 0;
    parent[source] = source;
    visit[source]  = true;

    // Add others V-1 vertixes into shortest path tree
    for (int i=0; i<SIZE-1; i++)  
    {
        int a = -1, b = -1, min = 1e9;

        // Find a vertix alerady in shortest path tree
        for (int k=0; k<SIZE; k++)
            if (visit[k]) 
            {

                // Find a vertix not in shortest path tree
                for (int j=0; j<SIZE; j++)
                    if (!visit[j])
                        if (dist[k] + w[k][j] < min)
                        {
                            a = k;
                            b = j;
                            min = dist[k] + w[k][j];
                        }
            }

        // All found
        if (a == -1 || b == -1) break;

        dist[b] = min;          // shortest path from soure to b
        parent[b] = a;          // b extend from a
        visit[b] = true;        // add to visit

    }
}
void showTestDate()
{
    for (int i=0; i<SIZE; i++) {
        for (int j=0; j<SIZE; j++) 
            printf("%d ", w[i][j]);
        printf("\n");
    }
    printf("\n");
}
void showDist(int root)
{
    printf("Shortest path from %d to others\n", root+1);

    for (int i=0; i<SIZE; i++)
        printf("%d ", dist[i]);
    printf("\n");
}
int main(int argc, char ** argv)
{
    int source = 0;
    init();
    labelSetting(source);
    showDist(source);

    return 0;
}

