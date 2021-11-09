/**
 * @file main.cpp
 * @author Roberto Vecchio (roberto.vecchio001@uniparthenope.it)
 * @brief 
 * @version 0.1
 * @date 2021-11-09
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <vector>
using std::vector;

#include "Graph.h"

int main()
{
    vector<Edge> edges = 
    {
        /*(u,v,w) -> archi da u a v avente peso w */
        {0,1,5},{0,2,3},{1,3,6},{1,2,2},{2,4,4},{2,5,2},{2,3,7},{3,5,1},{3,4,-1},{4,5,-2}
    };

    int node_number{5};
    Graph graph(edges,node_number);

    graph.printGraph();
    
    return 0;
}