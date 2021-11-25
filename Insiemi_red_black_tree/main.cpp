#include "RBTree.h"
#include "NumSet.h"

int main()
{
    NumSet num1, num2, num3;

    /* Inserimento nodi */
    num1.insert(8);
    num1.insert(18);
    num1.insert(5);
    num1.insert(15);
    num1.insert(25);
    num1.insert(40);
    num1.insert(3);

    num2.insert(18);
    num2.insert(25);
    num2.insert(1);
    num2.insert(80);
    num2.insert(100);
    num2.insert(123);
    num2.insert(110);
    num2.insert(12);
    num2.insert(7);

    num1.print_tree();
    num2.print_tree();


    num1.inorder();
    cout << endl;
    num2.inorder();
    cout << endl;

    num3.set_root(num3.difference_helper(num1.get_root(),num2.get_root()));
    num3.print_tree();

    num3.inorder();

    return 0;
}