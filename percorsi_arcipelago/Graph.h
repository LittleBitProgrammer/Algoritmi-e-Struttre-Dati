/**
 * @file Graph.h
 * @author Roberto Vecchio (roberto.vecchio001@studenti.uniparthenope.it)
 * @brief 
 * @version 0.1
 * @date 2021-11-09
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <utility>
#include <vector>

// Modo coinciso per dichiarare un pair di interi
typedef std::pair<int,int>Pair;

// Struttura dati per memorizzare un arco (orientato, pesato)
struct Edge
{
    int source;
    int destination;
    int weight;
};

class Graph
{
    private:
        std::vector<std::vector<Pair>> adj_list;
    public:
        Graph(std::vector<Edge> const &edges, int node_number);

        /* Getter */
        std::vector<std::vector<Pair>> get_adj_list();

        /* Setter */
        void set_adj_list(std::vector<std::vector<Pair>> adj_list);

        /* Methods*/
        void printGraph();
};

#endif