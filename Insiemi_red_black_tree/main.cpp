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
    cout << "Successore radice = " << bst.successor(bst.get_root())->key << endl;
    cout << "Predecessore radice = " << bst.predecessor(bst.get_root())->key << endl;
    cout << "Cancelliamo nodo con chiave 70" << endl;

    Node *searched = bst.search(70);
    bst.delete_node(searched);
    bst.print_tree();

    cout << "\n\n\n";

    cout << "Visita preorder: " << endl;
    bst.preorder();
    cout << endl;

    cout << "Visita inorder: " << endl;
    bst.inorder();
    cout << endl;

    cout << "Visita postorder: " << endl;
    bst.postorder();
    cout << endl;
    
    return 0;
}