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
print_stack(void)
{
	struct node *ptr = head;
	while (ptr) {
		printf("%d ", *(int *)(ptr->data));
		ptr = ptr->next;
	}
}


static void
dfs (int **adj_matrix, int *visited, int vsource)
{
	int ret_val = 0;
	int node;
	int i;
	char ch;

	//data = get_new_node(&vsource);
	//ret_val = insert_node(&head, (void *)data); 
	visited[vsource] = 1;
	for (i = 0; i < count_nodes; i++) {
		if (i == vsource)
			continue;
		if (visited[i] || !adj_matrix[vsource][i])
			continue;
		//data = get_new_node(&i);
		//printf("Inserting node %d\n", i);
		//insert_node(&head, (void *)data);
		//visited[i] = 2;
		dfs(adj_matrix, visited, i);
        } 
	data = get_new_node(&vsource);
	ret_val = insert_node(&head, (void *)data); 
	//node = delete_node(&head, &tail);
	//printf("Node %d\n", vsource);
	/*
	while ((node = delete_node(&head, &tail)) != -1) {
		if (visited[node] == 1)
		//if (visited[node])
			continue;
		printf("node: %d\n", node);
		for (i = 0; i < count_nodes; i++) {
			if (i == node)
				continue;
			if (visited[i] || !adj_matrix[node][i])
				continue;
			data = get_new_node(&i);
			//printf("Inserting node %d\n", i);
			insert_node_rear(&head, &tail, (void *)data);
			visited[i] = 2;
		}	
		visited[node] = 1;
		printf("%d ", node + 1);
		//scanf(" %c", &ch);
	}*/
}


int 
main (int argc, char *argv[])
{
	int **adj_matrix = NULL;
	int i, j;
	int *visited  = NULL;    /* if visited[i] is 1 then it is visited, if it is 2 then it is discovered, if 0 then not yet discovered */

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
	printf("\nEnter the source node from where to start the DFS\n");
	scanf(" %d", &source);
	printf("\nAdjacency Matrix\n");
        for (i = 0; i < count_nodes; i++) {
                for (j = 0; j < count_nodes; j++) {
                        printf("%d ", adj_matrix[i][j]);
                }
		printf("\n");
        }
	//visited[source] = 1;
	//printf("\nDFS traversal : %d ", source + 1);
	//printf("\nDFS traversal : %d ", source);
	dfs(adj_matrix, visited, source); 
	for (i = 0; i < count_nodes; i++) {
		if (!visited[i])
			dfs(adj_matrix, visited, i); 
	}
	print_stack();

	return 0;
}
