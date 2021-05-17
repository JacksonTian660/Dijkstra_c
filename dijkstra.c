
#include <stdlib.h>
#include <stdio.h>
#include "main.h"
#include "dijkstra.h"

void dijkstra(int starting_node, int end_node){




// .............................................................First Part..............................................................................
    printf("\n................................Part1: initializing...........................\n");

    char line[30];
    FILE *fp;
    
    fp = fopen("my_graph.txt", "r");

    while(fgets(line, 30, fp)!=NULL){
        number_of_edge_sets++;
    }
    printf("Number of edge sets %d\n", number_of_edge_sets);
    rewind(fp);

    // Scan the first line of the txt file to get number of vertices
    fscanf(fp,"%u",&number_of_vertices);
    number_of_not_visited = number_of_vertices;

    // Check the number of Vertices
    // printf("The number of vertices is %u\n", number_of_vertices);

    // dynamically allocate memory for unvisited nodes
    for(i=0;i<number_of_vertices;i++){
        unvisited[i] = 0;  
    }


    // This is the edge set pointer
    edge_set_ptr = (edge_ptr)malloc((sizeof(edge)*number_of_edge_sets+1));


    // loop through the number of edges in the loop pointer to put struct edge in the memory
    int k = 0;
    while (!feof(fp)){
        fscanf(fp,"%u %u %u ",&edge_set_ptr[k].start, &edge_set_ptr[k].end, &edge_set_ptr[k].weight);
        // printf("Node number: %u\t Adjacent Node: %u\t Weight %u\n",edge_set_ptr[k].start, edge_set_ptr[k].end, edge_set_ptr[k].weight);
        k++;
    }

    // Checking for loading documents
    // printf("Node number: %u\t Adjacent Node: %u\t Weight %u\n",edge_set_ptr[0].start, edge_set_ptr[0].end, edge_set_ptr[0].weight);
    // printf("Second line Node number: %u\t Adjacent Node: %u\t Weight %u\n",edge_set_ptr[1].start, edge_set_ptr[1].end, edge_set_ptr[1].weight);
    // printf("Last Line: Node number: %u\t Adjacent Node: %u\t Weight %u\n",edge_set_ptr[k-1].start, edge_set_ptr[k-1].end, edge_set_ptr[k-1].weight);

    //dynamically allocates nodes in the memory
    node_ptr linked_list_ptr = (node_ptr)malloc(sizeof(node)*number_of_vertices);
    for(i=0;i<number_of_vertices;i++){
        graph_node.data = i;
        graph_node.next = NULL;
        graph_node.distance = INF;
        linked_list_ptr[i] = graph_node;
    }

    printf("Last line of Node: %d, %d, %p", linked_list_ptr[number_of_vertices-1].data, linked_list_ptr[number_of_vertices-1].distance, linked_list_ptr[number_of_vertices-1].next);   
    

    fclose(fp);

// ............................................................Second Part..............................................................................





  printf("\n.................................Part2 Processing.............................\n");


    int curr_node, number_of_nodes_in_path;
    number_of_visited = 0;
    int temp[20];

    node_ptr path;
    node newNode;
    

    
    // Set the source node distance to be 0
    linked_list_ptr[starting_node].distance = 0;
    curr_node = starting_node;


    printf("starting node: %d's distance %d\n", starting_node, linked_list_ptr[starting_node].distance);
    // count how many live edges are connected to the current node;
    
    
    while(curr_node!=end_node){

         // Add the starting node to the visited list
        number_of_visited++;
        visited[number_of_visited-1] = curr_node;
        // Remove the unvisited status to visited status, change from 0 to 1;
        unvisited[curr_node] = 1;
        // if (number_of_visited==3)
        // {
        //     break;
        // }
        
        int count = 0;                
        // Updating distance for unvisited nodes
        for(i=0;i<number_of_edge_sets;i++){
            if(edge_set_ptr[i].start==curr_node && !unvisited[edge_set_ptr[i].end]){
                temp[count] = edge_set_ptr[i].end;
                count++;
                if(linked_list_ptr[edge_set_ptr[i].end].distance > edge_set_ptr[i].weight + linked_list_ptr[curr_node].distance){
                    linked_list_ptr[edge_set_ptr[i].end].distance = edge_set_ptr[i].weight + linked_list_ptr[curr_node].distance;
                    
                    // Tracking the node changes distance through which node;
                    path = &linked_list_ptr[edge_set_ptr[i].end];
                    if(path->next == NULL){
                        path->next = &linked_list_ptr[curr_node];
                    }
                    else{
                        newNode.data = linked_list_ptr[curr_node].data;
                        newNode.distance = linked_list_ptr[curr_node].distance;
                        newNode.next = path->next;
                        path->next = &newNode;
                    }
                }
            }
        }

        // Print Connected nodes for checking
        // printf("Connected nodes");
        for(i=0;i<count;i++){
            // printf("Connected Nodes %d\n and the update distance for this node is %d\n",temp[i],linked_list_ptr[temp[i]].distance);
            temp[i] = 0;
        }

        // printf("finish printing adjacent nodes\n");
        // printf(".......................................................................Processing....................................................\n");
        
        // printf("%d %d %d\n",unvisited[6325],unvisited[1881], unvisited[57017]);
        // printf("%d %d %d\n",linked_list_ptr[6325].distance,linked_list_ptr[1881].distance, linked_list_ptr[57017].distance);
        min_distance = INF;
        for(i=0;i<number_of_vertices;i++){
            if(!unvisited[i] && linked_list_ptr[i].distance < min_distance){
                min_distance = linked_list_ptr[i].distance;
                curr_node = i;

                // Checking for new current node
                // printf("New current node is %d\n", i);
            }
        }

        // Printing Result
        if(curr_node == end_node){
            printf("The shortest distance is %u\n",linked_list_ptr[end_node].distance);
    }
    // printf("current status of unvisited list at current node %d: %d\n", curr_node, unvisited[curr_node]);   
    // printf("%d visited: %d\n",number_of_visited,curr_node);
    // printf("There are %d nodes connected to current node %d\n", count, curr_node);

    //     // looking for the next node which has the smallest distance
        
    }



    printf("\nNumber of visited nodes: %d\n",number_of_visited);


    // Document how many nodes to be visited
    // for(i=0;i<number_of_visited;i++){
    //     if(i<number_of_visited-1){
    //         printf("%d-->",visited[i]);
    //     }
    //     else{
    //         printf("%d\n",visited[i]);
    //     }
    // }

    // Check all the nodes distance
    // for(i=0;i<number_of_vertices;i++){
    //     printf("Node%d distance: %d\n",i,linked_list_ptr[i].distance);
    // }

    printf("\n.............................PATH....................................\n");
    node_ptr path_line;
    path_line = &linked_list_ptr[end_node];
    while(path_line->next!=NULL){
        printf("%d->",path_line->data);
        path_line = path_line->next;
    }

    path_line->next = &linked_list_ptr[starting_node];
        printf("%d\n",path_line->data);



}