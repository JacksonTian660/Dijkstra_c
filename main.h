#include <stdio.h>
/* This is the struct for node, data represents node number, 
next is the pointer to the node, distance is used for 
dijkstra algorithm*/





// this is the number of vertices, will be equal to the first line of the my_graph.txt
unsigned int number_of_vertices;

int i;


// This is for counting the number of edges;
int number_of_edge_sets;

// This is for how many nodes have been visited and how many nodes need to be visited
// int visited[], to_be_visited[];

// This node object will be loop for node to allocate in the dynamic memory



// for visited nodes
int visited[100000]; 




int number_of_visited, number_of_not_visited;





unsigned int startset[1000000], endset[1000000], weightset[1000000];

void dijkstra(int, int);




