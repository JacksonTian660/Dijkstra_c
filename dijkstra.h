typedef struct node{
    int data;
    struct node* next;
    int distance;
}node, * node_ptr;

typedef struct edge{
    unsigned int start;
    unsigned int end;
    unsigned int weight;
} edge, *edge_ptr;


node graph_node;

// This pointer is the dynamic pointer for the 
// linkedlist nodes from 0 to number of vertices -1
node_ptr linked_list_ptr;

edge_ptr edge_set_ptr;

// This is used for infinity distance for node
#define INF 2147483647;


// This is used for selecting next node to be visited
int min_distance;

//This is the pointer for unvisited array
int unvisited[100000];


