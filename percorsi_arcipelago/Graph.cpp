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

Graph::Graph(std::vector<Edge> edges, int edges_number, int nodes_number):
    nodes_number{nodes_number}
{
    head_list.resize(nodes_number);

    /* Inizializziamo il puntatore a head per ogni nodo a nullptr */
    for(auto i{0}; i < nodes_number; i++)
    {
        head_list.at(i) = nullptr;
    }

    /* Utilizziamo gli archi per costruire la lista di adiacenza */
    for(auto i{0}; i < edges_number; i++)
    {
        int source{edges.at(i).source};
        int destination{edges.at(i).destination};
        int weight{edges.at(i).weight};

        Node *new_node{generate_adj_node(destination,weight,head_list.at(source))};

        /* Puntatore ad head come nuovo nodo */
        head_list.at(source) = new_node;
    }
}

Node *Graph::generate_adj_node(int id, int cost, Node* head)
{
    /* Allochiamo un nuovo nodo */
    Node *adj_node = new Node;

    /* Costruiamo il nodo con i valori passati in input */
    adj_node->id = id;
    adj_node->cost = cost;
    adj_node->next = head;

    /* Ritorniamo il nuovo nodo */
    return adj_node;
}

/*
Dobbiamo implementare un distruttore personalizzato in quanto la nostra classe alloca 
dinamicamente alcuni puntatori presenti nella lista di adiacenza e la lista di adiacenza stessa
*/
Graph::~Graph()
{
     /* Iteriamo ogni nodo */
     for(auto i{0}; i < nodes_number; i++)
     {
         delete[] head_list.at(i);
     }  
}

int Graph::get_nodes_number()
{
    return this->nodes_number;
}

std::vector<Node *>Graph::get_head_list()
{
    return this->head_list;
}

void Graph::set_head_list(std::vector<Node *>head_list)
{
    this->head_list = head_list;
}

/* Stampa tutti i nodi adiacenti a quello passato in input */
void Graph::display_adj_nodes(Node* pointer,int i)
{
    /* fintanto che l'elemento ha un suo successivo */
    while(pointer != nullptr)
    {
        std::cout << "(" << i << ", " << pointer->id << ", " << pointer->cost << ") ";
        pointer = pointer->next;
    }

    std::cout << std::endl;
}

std::vector<Node *> Graph::get_adj_nodes(int i)
{
    Node *pointer{head_list.at(i)};
    std::vector<Node *> adj_nodes;

    while (pointer != nullptr)
    {
        adj_nodes.push_back(pointer);
        pointer = pointer->next;
    }
    
    return adj_nodes;
}

void Graph::display_adj_list()
{
    std::cout << "Lista di adiacenza del grafo" << std::endl;
    std::cout << "(indice sorgente, indice destinazione, peso arco)" << std::endl;

    /* Iteriamo ogni nodo */
    for(auto i{0}; i < nodes_number; i++)
    {
        /* Stampa i nodi adiacenti al nodo corrente */
        display_adj_nodes(head_list[i],i);
    }
}