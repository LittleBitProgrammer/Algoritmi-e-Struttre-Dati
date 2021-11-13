#ifndef _BST_H_
#define _BST_H_

#include <iostream>
using std::cout;
using std::endl;
using std::max;

#include <string>
using std::string;

/* Struttura dati utile a memorizzare un nodo in un albero */
struct Node
{
    int key;      /* chiave del nodo */
    Node *parent; /* Puntatore al padre */
    Node *left;   /* Puntatore al figlio sinistro */
    Node *right;  /* Puntatore al figlio destro */
};

/* Classe per rappresentare gli alberi binari di ricerca */
class Bst
{
    private:
        Node *root; /* radice dell'albero binario di ricerca */

        /* Methods */

        /* Metodo helper sfruttato dalla preorder */
        void preorder_helper(Node *node);
        /* Metodo helper sfruttato dalla inorder */
        void inorder_helper(Node *node);
        /* Metodo helper sfruttato dalla postorder */
        void postorder_helper(Node *node);
        /* Metodo helper sfruttato dalla tree_height */
        int tree_height_helper(Node *node);
        /* Metodo helper sfruttato dalla search */
        Node *search_helper(Node *node,int key);
        /* Metodo per sostituire un sottoalbero con un altro */
        void transplant(Node *u, Node *v);
        /* Metodo helper sfruttato dalla print */
        void print_helper(Node *node, string indentation, bool last);
    
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
        Node *search(int key);
        /* Ricerca del nodo con chiave minima */
        Node *minimum(Node *node);
        /* Ricerca del nodo con chiave massima */
        Node *maximum(Node *node);
        /* Trova il successore del dato nodo */
        Node *successor(Node* node);
        /* Trova il predecessore di un dato nodo */
        Node *predecessor(Node* node);
        /* Inserimento di una chiave in un albero di ricerca binaria */
        void insert(int key);
        /* Cancellazione di un nodo con una data chiave */
        Node *delete_node(Node *node);
        /* Stampa dell'albero */
        void print_tree();

        /* Getter */
        Node *get_root();
};

#endif