#include "NumSet.h"

/*===============================
           CONSTRUCTOR
================================*/
NumSet::NumSet()
{
    this->rb_tree = new RBTree;
}

/*===============================
           Destructor
================================*/

NumSet::~NumSet()
{
    delete rb_tree;
}