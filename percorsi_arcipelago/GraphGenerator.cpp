#include <iostream>
#include <fstream>
#include <vector>
#include "GraphGenerator.h"

/* Costruttore GraphGenerator */
GraphGenrator::GraphGenrator(string filename):filename{filename}{}

string GraphGenrator::get_filename()
{
    return this->filename;
}

void GraphGenrator::set_filename(string filename)
{
    this->filename = filename;
}

Graph GraphGenrator::generate_graph()
{
    using std::cout;
    using std::endl;
    using std::vector;
    using std::ifstream;

    int node_numbers;
    int edges_number;

    vector<Edge> edges;
    ifstream filereader(filename.c_str());

    if (!filereader.fail())
    {
        filereader >> node_numbers >> edges_number;
        edges.resize(edges_number);

        for(auto i{0}; i < edges_number; i++)
        {
            Edge edge;

            filereader >> edge.source;
            filereader >> edge.destination;
            filereader >> edge.weight;

            edges.push_back(edge);
        }
    }
    else
    {
        cout << "Il file non e' stato aperto con successo" << endl;
    }
    
    filereader.close()
}


