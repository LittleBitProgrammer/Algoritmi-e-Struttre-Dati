#include "RBTree.h"
#include "NumSet.h"

int main()
{
    NumSet num1, num2;

    /* Inserimento nodi */
    num1.insert(8);
    num1.insert(18);
    num1.insert(5);
    num1.insert(15);
    //rb.insert(17);
    num1.insert(25);
    num1.insert(40);
    num1.insert(3);
    num1.insert(1);
    num1.insert(80);
    num1.insert(100);
    num1.insert(123);
    num1.insert(110);
    num1.insert(12);
    num1.insert(7);

   // rb.delete_key(17);
    //num1.print_tree();

    pair<pair<RBNode *,RBNode *>,int> triple = num1.split(num1.get_root(),81);

    NumSet num3, num4;
    
    num3.set_root(triple.first.first);
    num4.set_root(triple.first.second);
    num3.print_tree();
    num4.print_tree();

    return 0;
}