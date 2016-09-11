#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

static int source;
static struct node *head = NULL;
static struct node *tail = NULL;
static int *data = NULL;
static int count_nodes = 0;

static int *
get_new_node (int *value)
{
	int *data = NULL;

	data = (int *) malloc (sizeof(int));
	*data = *value;
	return data;
}


static void
bfs (int **adj_matrix, int *visited)
{
	int ret_val = 0;
	int node;
	int i;
	char ch;

	data = get_new_node(&source);
	ret_val = insert_node_rear(&head, &tail, (void *)data); 
	while ((node = delete_node(&head, &tail)) != -1) {
		if (visited[node])
			continue;
		//printf("node: %d\n", node);
		for (i = 0; i < count_nodes; i++) {
			if (visited[i] || !adj_matrix[node][i])
				continue;
			data = get_new_node(&i);
			//printf("Inserting node %d\n", i);
			insert_node_rear(&head, &tail, (void *)data);
		}	
		visited[node] = 1;
		printf("%d ", node + 1);
		//scanf(" %c", &ch);
	}
}


int 
main (int argc, char *argv[])
{
	int **adj_matrix = NULL;
	int i, j;
	int *visited  = NULL;

	printf("\nEnter the number of nodes in the graph\n");
	scanf(" %d", &count_nodes);
	adj_matrix = (int **) calloc(count_nodes, sizeof(int *));
	for (i = 0; i < count_nodes; i++) {
		adj_matrix[i] = (int *) calloc(count_nodes, sizeof(int));
	}
	visited = (int *) calloc(count_nodes, sizeof(int));
	printf("\nEnter the elements of the adjacency matrix\n");
	for (i = 0; i < count_nodes; i++) {
		for (j = 0; j < count_nodes; j++) {
			scanf(" %d", &adj_matrix[i][j]);
		}
	}
	printf("\nEnter the source node from where to start the BFS\n");
	scanf(" %d", &source);
	printf("\nAdjacency Matrix\n");
        for (i = 0; i < count_nodes; i++) {
                for (j = 0; j < count_nodes; j++) {
                        printf("%d ", adj_matrix[i][j]);
                }
		printf("\n");
        }
	//visited[source] = 1;
	printf("\nBFS traversal : %d ", source + 1);
	bfs(adj_matrix, visited); 

	return 0;
}
