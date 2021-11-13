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

/* Struttura per gli item nella lista di adiacenza */
struct Node
{
    int id;     /* Id del nodo */
    int cost;   /* Costo per spostarsi a questo nodo */
    int key;    /* Chiave del nodo */
    Node *next; /* Puntatore al prossimo nodo */
};

// Struttura per memorizzare un arco (orientato, pesato)
struct Edge
{
    int source;
    int destination;
    int weight;
};

class Graph
{
    private:
        int nodes_number; /* Numero di nodi nel grafo */
        Node **head_list; /* Lista di adiacenza come array di puntatori */

        /* Methods */
        Node *generate_adj_node(int id, int cost, int key, Node* head);
    public:
        /* Costruttori */
        Graph(std::vector<Edge> edges, int edges_number, int nodes_number);

        /* Distruttore */
        ~Graph();

        /* Getter */
        int get_nodes_number();
        Node **get_head_list();

        /* Setter */
        void set_head_list(Node **head_list);
        
        /* Methods */
        void display_adj_nodes(Node* pointer,int i);
        void display_adj_list();
        std::vector<Node *> get_adj_nodes(int i);
};

#endif