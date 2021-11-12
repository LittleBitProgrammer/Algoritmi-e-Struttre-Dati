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
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <string>
using std::string;

#include "GraphGenerator.h"
#include "Graph.h"

int main()
{
    string filename;

    cout << "Enter the file name: " << endl;
    cin >> filename;

    GraphGenrator graph_gen(filename);

    Graph *my_graph = graph_gen.generate_graph();
    my_graph->printGraph();
    
    return 0;
}