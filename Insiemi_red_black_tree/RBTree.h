#ifndef _RB_TREE_H_
#define _RB_TREE_H_

#include "AbstractBinarySearchTree.h"

/* Enum dei differenti colori che possono assumere i nodi degli alberi red black */
enum Color{RED,BLACK};

/* 
Struttura dati utile a memorizzare un nodo in un albero Red Black, il quale deve contenere:
- puntatore al padre
- puntatore al figlio sinistro
- puntatore al figlio destro
- chiave
- colore (rosso,nero)

Pertanto ereditiamo gli attributi da Node per rappresentare un nuovo nodo più specifico che 
aggiunge il colore tra le proprie informazioni
 */
struct RBNode
{
    int key;      /* chiave del nodo */
    RBNode *parent; /* Puntatore al padre */
    RBNode *left;   /* Puntatore al figlio sinistro */
    RBNode *right;  /* Puntatore al figlio destro */
    bool color;

    /* Constructor */
    RBNode(int key)
    {
        this->key = key;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
        color = RED;
    }
};

class RBTree:public AbstractBinarySearchTree<RBNode>
{
    private:
        /* Methods */

        /* Inserimento di un nodo in un BST */
        RBNode *bst_insert_helper(RBNode *root, RBNode *node_to_add);    
        /* Rispristino di un albero RB dalle violazioni causate dall'inserimento BST */
        void insert_fixup(RBNode *root, RBNode *node_to_add);
        /* Metodo di supporto utilizzato dalla print */
        void print_helper(RBNode *root, string idnentation, bool last);
        
    public:
        /* Methods */
        
        /* Rotazione a sinistra */
        void left_rotate(RBNode *x);
        /* Rotazione a destra */
        void right_rotate(RBNode *y);
        /* Inserimento di una chiave nell'albero RB */
        void insert(int key);
        /* Stampa dell'albero RB */;
        void print();
};

#endif