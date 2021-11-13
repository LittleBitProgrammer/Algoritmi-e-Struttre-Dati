#include "Bst.h"

int main()
{
    Bst bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(23);
    bst.insert(35);
    bst.insert(11);
    bst.insert(25);
    bst.insert(31);
    bst.insert(42);
    bst.insert(80);
    bst.insert(73);
    bst.insert(85);

    bst.print_tree();

    cout << "\nAltezza ABR = " << bst.tree_height() << endl;
    cout << "Minimo ABR = " << bst.minimum(bst.get_root())->key << endl;
    cout << "Massimo ABR = " << bst.maximum(bst.get_root())->key << endl;
    
    return 0;
}