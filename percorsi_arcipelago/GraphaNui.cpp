#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include "GraphaNui.h"
#include "GraphGenerator.h" /* Generatore di grafi */

//TODO::OMOLOGARE IMPORT 

GraphaNui *GraphaNui::instance = nullptr;

GraphaNui *GraphaNui::get_instace()
{

    if (instance == nullptr)
    {
        string filename;

        cout << "Inserire il nome del file: ";
        cin >> filename;

        instance = new GraphaNui(filename);
    }

    return instance;
}

GraphaNui::GraphaNui(string filename)
{
    GraphGenrator graph_gen(filename);
    archipelago_grapha_nui = graph_gen.generate_graph();
}

Graph *GraphaNui::get_archipelago()
{
    return this->archipelago_grapha_nui;
}

void GraphaNui::set_archipelago(Graph *archipelago_grapha_nui)
{
    this->archipelago_grapha_nui = archipelago_grapha_nui;
}

void GraphaNui::topological_order(stack<int> &tolpological_stack, bool visited[], int node)
{
    /* Marca nodo corrente come visitato */
    visited[node] = true;

    /* lanciamo la topological per ogni adiacenza non ancora visitata */
    for(auto v:archipelago_grapha_nui->get_adj_nodes(node))
    {
        if (!visited[v->id])
        {
            topological_order(tolpological_stack,visited,v->id);
        }
    }

    /* Push del nodo corrente nello stack atto a memorizzare l'ordine topologico */
    tolpological_stack.push(node);
}

void GraphaNui::maximize_tourism(int source)
{
    /* Numero di nodi nel grafo */
    int nodes_number{archipelago_grapha_nui->get_nodes_number()};

    /* Creiamo uno stack di interi, utile a memorizzare l'ordine topologico */
    stack<int> topological_stack;
    /* Creiamo un array delle distanze con grandezza pari al numero di nodi */
    int dist[nodes_number];
    /*Creiamo un array di booleani, utile a memorizzare le visite dei nodi */
    bool *visited = new bool[nodes_number];

    /* Marchiamo tutti i vertici come non visitati */
    for(auto i{0}; i < nodes_number; i++)
    {
        visited[i]= false;
    }

    /* Lanciamo la topological order */
    for (auto i{0}; i < nodes_number; i++)
    {
        if(!visited[i])
        {
            topological_order(topological_stack, visited, i);
        }
    }

    /* 
       inizializziamo la distanza di tutti i vertici a -infinito tranne quella della sorgente, 
       posta a 0
    */
   for(auto i{0}; i < nodes_number; i++)
   {
       dist[i] = INT_MIN;
   }
   dist[source] = 0;

   /* Iteriamo i vertici nell'ordine topologico fino a quando lo stack non si svuota */
   while(!topological_stack.empty())
   {
       /* Estriamo il nodo in cima allo stack */
       int u = topological_stack.top();
       topological_stack.pop();

       /* Aggiorniamo le distanze per ogni nodo adiacente */
       if(dist[u] != INT_MIN)
       {
           for(auto v:archipelago_grapha_nui->get_adj_nodes(u))
           {
               if(dist[v->id] < dist[u] + v->cost)
               {
                   dist[v->id] = dist[u] + v->cost;
               }
           }
       }
   }

   for(auto i{0}; i < nodes_number; i++)
    {
        if(dist[i] == INT_MIN)
        {
            cout << source << " -> " << i << " = " << "\u221E" << endl;
        }
        else
        {
            cout << source << " -> " << i << " = " << dist[i] << endl;
        }
    }

    /* Deallochiamo visited */
}