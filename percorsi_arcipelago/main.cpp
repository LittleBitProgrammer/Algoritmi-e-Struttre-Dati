/**
 * @file main.cpp
 * @author Roberto Vecchio (roberto.vecchio001@uniparthenope.it)
 * @brief 
 * @version 0.1
 * @date 2021-11-09
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
using std::cout;
using std::endl;

#include "GraphaNui.h"

int main()
{
    try
    {
        GraphaNui *graphanui = GraphaNui::get_instace();
        graphanui->get_archipelago()->display_adj_list();
        graphanui->maximize_tourism(1);
    }
    catch(const std::exception& e)
    {
        cout << e.what() << endl;
    }
    
    return 0;
}