/**
 * @file Graph.cpp
 * @author Roberto Vecchio(roberto.vecchio001@studenti.uniparthenope.it)
 * @brief 
 * @version 0.1
 * @date 2021-11-09
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include "Graph.h"

Graph::Graph(std::vector<Edge> const &edges, int node_number)
{
    // Reimpostiamo la grandezza del vettore per contenere "node_number" elementi di tipo vector<Edge>
    adj_list.resize(node_number);

    // Aggiungiamo archi al grafo orientato, pesato
    for(auto &edge: edges)
    {
        int source = edge.source;
        int destination = edge.destination;
        int weight = edge.weight;

        // inseriamo alla fine 
        adj_list[source].push_back(std::make_pair(destination,weight));
    }
}

// Funzione per stampare la lista di adiacenza
void Graph::printGraph()
{
    using std::cout;
    using std::endl;

    for(auto u{0}; u < adj_list.size(); u++)
    {
        // Stampiamo tutti i nodi adiacenti del dato vertice
        for(Pair v: adj_list[u])
        {
            cout << "( " << u << ", " << v.first << ", " << v.second << ") ";
        }
        cout << endl;
    }
}

void Graph::set_adj_list(std::vector<std::vector<Pair>> adj_list)
{
    this->adj_list = adj_list;
}

std::vector<std::vector<Pair>> Graph::get_adj_list()
{
    return this->adj_list;
}