#ifndef _GRAPHANUI_H_
#define _GRAPHANUI_H_

#include <string>
using std::string;

#include "Graph.h"

/* Signleton class*/
class GraphaNui
{
    private:
        Graph archipelago_grapha_nui;
        static GraphaNui *instance; /* Puntatore ad istanza */

        /* Costruttore privato per Singleton */
        GraphaNui(string filename);

    public:
        /* Metodo utile a ritornare istanza del singleton */
        static GraphaNui *get_instace();

        /* Getter */
        Graph get_archipelago();

        /* Setter */
        void set_archipelago(Graph &archipelago_grapha_nui);

        /* Methods */
        void maximize_tourism(int source);
};

#endif