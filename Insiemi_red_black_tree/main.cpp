#include "RBTree.h"

int main()
{
    RBTree rb;

    /* Inserimento nodi */
    rb.insert(8);
    rb.insert(18);
    rb.insert(5);
    rb.insert(15);
    rb.insert(17);
    rb.insert(25);
    rb.insert(40);
    rb.insert(3);
    rb.insert(1);
    rb.insert(80);
    //rb.delete_node(17);

    rb.print();

    return 0;
}