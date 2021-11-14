#ifndef _BST_H_
#define _BST_H_

#include "AbstractBinarySearchTree.h"

/* Classe per rappresentare gli alberi binari di ricerca */
class Bst:public AbstractBinarySearchTree<Node>
{   
    protected:
        /* Override */

        /* Metodo helper sfruttato dalla print */
        void print_helper(Node *node, string indentation, bool last);
    
    public:
        /* Override */

        /* Inserimento di una chiave in un albero di ricerca binaria */
        void insert(int key);
        /* Cancellazione di un nodo con una data chiave */
        Node *delete_node(Node *node);
};

#endif