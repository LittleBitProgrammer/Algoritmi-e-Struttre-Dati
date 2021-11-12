#include <iostream>
#include <fstream>
#include <sstream>
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

Graph *GraphGenrator::generate_graph()
{
    using std::cout;
    using std::endl;
    using std::vector;
    using std::ifstream;
    using std::stringstream;

    int node_numbers;
    int edges_number;

    vector<Edge> edges;
    ifstream filereader(filename.c_str());

    if (!filereader.fail())
    {
        filereader >> node_numbers >> edges_number;

        if(node_numbers >= 2 && node_numbers <= 1000 && edges_number >= 1 && edges_number <= 10000)
        {
            for(auto i{0}; i < edges_number && !filereader.eof(); i++)
            {
                Edge edge;

                filereader >> edge.source;
                filereader >> edge.destination;
                filereader >> edge.weight;

                /* Caso in cui la lettura degli interi non sia andata a buon */
                if(filereader.fail())
                {
                    throw std::runtime_error("File contain non numeric value.");
                }

                edges.push_back(edge);
            }
        }
        else
        {
            throw std::invalid_argument("Invalid file data, Please insert in the file value N between 2 and 1000 and P between 1 and 10000");
        }
        filereader.close();

        Graph *graph = new Graph(edges,node_numbers);
        return graph;
    }
    else
    {
        throw std::runtime_error("file does not exists");
    }
}


