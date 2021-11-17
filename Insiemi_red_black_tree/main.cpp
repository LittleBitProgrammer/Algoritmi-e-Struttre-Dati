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
    rb.insert(100);
    rb.insert(123);
    rb.insert(110);
    rb.insert(12);
    rb.insert(7);

    rb.delete_node(17);
    rb.print();

    cout << "\nPREORDER = " << endl;
    rb.preorder();
    cout << "\nINORDER = " << endl;
    rb.inorder();
    cout << "\nPOSTORDER = " << endl;
    rb.postorder();

    RBNode *searched = rb.search(15);
    cout << "\nNodo cercato con chiave = " << searched->key;

    cout << "\nSuccessore di 15 = " << rb.successor((rb.search(15)))->key << endl;
    cout << "\nPredecessore di 15 = " << rb.predecessor((rb.search(15)))->key << endl;

    cout << "\nALTEZZA = " << rb.tree_height() << endl;
    cout << "\nALTEZZA NERA = " << rb.black_height(rb.get_root()) << endl;


    return 0;
}