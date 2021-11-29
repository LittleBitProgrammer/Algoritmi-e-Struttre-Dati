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

    /* Constructors */
    RBNode(int key)
    {
        this->key = key;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
        color = RED;
    }

    RBNode(){}
};

class RBTree:public AbstractBinarySearchTree<RBNode>
{
    private:
        /* Attributes */
        static RBNode *TNULL;

        /* Methods */

        /* Rispristino di un albero RB dalle violazioni causate dall'inserimento BST */
        void insert_fixup(RBNode *&root, RBNode *&node_to_add);
        /* Metodo di supporto utilizzato dalla print */
        void print_helper(RBNode *root, string idnentation, bool last);
        /* Metodo di supporto utilizzato dalla delete_key */
        void delete_helper(RBNode *node_to_delete, int key);
        /* Ripristino delle violazioni dovute alla cancellazione di un nodo nell'albero RB */
        void delete_fixup(RBNode *x);
        /* Metodo helper sfruttato dalla preorder */
        void preorder_helper(RBNode *node);
        /* Metodo helper sfruttato dalla inorder */
        void inorder_helper(RBNode *node);
        /* Metodo helper sfruttato dalla postorder */
        void postorder_helper(RBNode *node);
        /* Metodo helper sfruttato dalla search */
        RBNode *search_helper(RBNode *node,int key);
        /* Metodo helper sfruttato dalla tree_height */
        int tree_height_helper(RBNode *node);

    protected:
        /* Rotazione a sinistra */
        void left_rotate(RBNode *x);
        /* Rotazione a destra */
        void right_rotate(RBNode *y);
    public:
        /* Constructor */
        RBTree();

        /* Methods */
        /* Inserimento di una chiave nell'albero RB */
        void insert(int key);
        /* Cancellazione di un nodo con una data chiave */
        void delete_key(int key);
        /* Ricerca del nodo con chiave minima */
        RBNode *minimum(RBNode *node);
        /* Ricerca del nodo con chiave massima */
        RBNode *maximum(RBNode *node);
        /* Trova il successore del dato nodo */
        RBNode *successor(RBNode* node);
        /* Trova il predecessore di un dato nodo */
        RBNode *predecessor(RBNode* node);
        /* Calcola l'altezza nera di un dato nodo x */
        int black_height(RBNode *node);

        /* Setter */
        void set_root(RBNode *root) override;

        /* Getter */
        RBNode *get_tnull();
};

#endif