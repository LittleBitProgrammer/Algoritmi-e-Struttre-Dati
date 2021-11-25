//
// Created by Roberto Vecchio on 25/11/21.
//
#include <fstream>
using std::ifstream;

#include <sstream>
using std::stringstream;

#include "SetGenerator.h"

/* Costruttore GraphGenerator */
SetGenerator::SetGenerator(string filename):filename{filename}{}

string SetGenerator::get_filename()
{
    return this->filename;
}

void SetGenerator::set_filename(string filename)
{
    this->filename = filename;
}

vector<NumSet> SetGenerator::generate_sets()
{
    vector<NumSet> sets;
    ifstream filereader(filename.c_str());
    string row;

    if (!filereader.fail())
    {
        while (std::getline(filereader,row))
        {
            stringstream ss(row);
            NumSet numSet;

            int number_set;
            while(ss >> number_set)
            {
               numSet.insert(number_set);
            }
            sets.push_back(numSet);
        }
        return sets;
    }
    else
    {
        throw std::runtime_error("file does not exists");
    }
}
