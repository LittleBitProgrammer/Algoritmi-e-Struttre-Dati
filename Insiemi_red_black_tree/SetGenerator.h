//
// Created by Roberto Vecchio on 25/11/21.
//

#ifndef _SET_GENERATOR_H
#define _SET_GENERATOR_H

#include <string>
using std::string;

#include <vector>
using std::vector;

#include "NumSet.h"

class SetGenerator
{
private:
    string filename;
public:
    /* Costruttore */
    SetGenerator(string filename);

    /* Getter */
    string get_filename();

    /* Setter */
    void set_filename(string file_name);

    /* Methods */
    vector<NumSet> generate_sets();
};


#endif //_SET_GENERATOR_H
