#ifndef _BST_H_
#define _BST_H_

#include <iostream>
using std::cout;
using std::endl;
using std::max;

#include <string>
using std::string;

/* Struttura dati utile a memorizzare un nodo in un albero */
struct BNode
{
    int key;      /* chiave del nodo */
    BNode *parent; /* Puntatore al padre */
    BNode *left;   /* Puntatore al figlio sinistro */
    BNode *right;  /* Puntatore al figlio destro */
};

/* Classe per rappresentare gli alberi binari di ricerca */
class Bst
{
    private:
        BNode *root; /* radice dell'albero binario di ricerca */

        /* Methods */

        /* Metodo helper sfruttato dalla preorder */
        void preorder_helper(BNode *node);
        /* Metodo helper sfruttato dalla inorder */
        void inorder_helper(BNode *node);
        /* Metodo helper sfruttato dalla postorder */
        void postorder_helper(BNode *node);
        /* Metodo helper sfruttato dalla tree_height */
        int tree_height_helper(BNode *node);
        /* Metodo helper sfruttato dalla search */
        BNode *search_helper(BNode *node,int key);
        /* Metodo per sostituire un sottoalbero con un altro */
        void transplant(BNode *u, BNode *v);
        /* Metodo helper sfruttato dalla print */
        void print_helper(BNode *node, string indentation, bool last);
    
    public:
        /* Constructor */
        Bst();

        /* Methods */

        /* Visita anticipata: nodo -> left -> right */
        void preorder();
        /* Visita simmetrica: left -> nodo -> right */
        void inorder();
        /* Visita differita: left -> right -> nodo */
        void postorder();
        /* Calcola altezza albero binario di ricerca */
        int tree_height();
        /* Ricerca in un albero binario di ricerca */
        BNode *search(int key);
        /* Ricerca del nodo con chiave minima */
        BNode *minimum(BNode *node);
        /* Ricerca del nodo con chiave massima */
        BNode *maximum(BNode *node);
        /* Trova il successore del dato nodo */
        BNode *successor(BNode* node);
        /* Trova il predecessore di un dato nodo */
        BNode *predecessor(BNode* node);
        /* Inserimento di una chiave in un albero di ricerca binaria */
        void insert(int key);
        /* Cancellazione di un nodo con una data chiave */
        BNode *delete_node(BNode *node);
        /* Stampa dell'albero */
        void print_tree();

        /* Getter */
        BNode *get_root();
};

#endif