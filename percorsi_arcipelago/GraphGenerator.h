#ifndef _GRAPH_GENERATOR_H_
#define _GRAPH_GENERATOR_H_

#include <string>
using std::string;

#include "Graph.h"

class GraphGenrator
{
    private:
        string filename;
    public:
        /* Costruttore */
        GraphGenrator(string filename);

        /* Getter */
        string get_filename();

        /* Setter */
        void set_filename(string file_name);

        /* Methods */
        Graph generate_graph();
};

#endif