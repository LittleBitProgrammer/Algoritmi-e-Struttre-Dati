#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <string>
using std::string;

#include "GraphaNui.h"
#include "GraphGenerator.h" /* Generatore di grafi */

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