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
    num1.print_tree();

    cout << "\nPREORDER = " << endl;
    num1.preorder();
    cout << "\nINORDER = " << endl;
    num1.inorder();
    cout << "\nPOSTORDER = " << endl;
    num1.postorder();

    RBNode *searched = num1.search(15);
    cout << "\nNodo cercato con chiave = " << searched->key;

    cout << "\nSuccessore di 15 = " << num1.successor((num1.search(15)))->key << endl;
    cout << "\nPredecessore di 15 = " << num1.predecessor((num1.search(15)))->key << endl;

    cout << "\nALTEZZA = " << num1.tree_height() << endl;
    cout << "\nALTEZZA NERA = " << num1.black_height(num1.get_root()) << endl;

    num2.insert(124);
    cout << "\nAlbero 2:" << endl;
    num2.print_tree();

    cout << "ALTEZZA NERA ALBERO 2 = " << num2.black_height(num2.get_root()) << endl;

    pair<pair<RBNode *,RBNode *>,int> triple = num1.split(num1.get_root(),81);

    NumSet num3, num4;
    
    num3.set_root(triple.first.first);
    num4.set_root(triple.first.second);
    num3.print_tree();
    num4.print_tree();

    NumSet num5;

    num5.insert(123);
    num5.insert(100);
    num5.insert(110);

    num5.print_tree();
    return 0;
}