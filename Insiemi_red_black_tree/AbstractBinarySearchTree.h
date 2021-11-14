#ifndef _ABSTRACT_BINARY_SEARCH_TREE_H_
#define _ABSTRACT_BINARY_SEARCH_TREE_H_

#include <iostream>
using std::cout;
using std::endl;
using std::max;

#include<string>
using std::string;

#include <type_traits>
using std::is_base_of;

/* Enum dei differenti colori che possono assumere i nodi degli alberi red black */
enum Color{RED,BLACK};

/* 
Struttura dati utile a memorizzare un nodo in un albero binario, il quale deve contenere:
- puntatore al padre
- puntatore al figlio sinistro
- puntatore al figlio destro
- chiave
 */
struct Node
{
    int key;      /* chiave del nodo */
    Node *parent; /* Puntatore al padre */
    Node *left;   /* Puntatore al figlio sinistro */
    Node *right;  /* Puntatore al figlio destro */
};

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
struct RBNode:Node
{
    bool color;
};

template<typename T>
class AbstractBinarySearchTree
{
    /* Assicuriamoci che la classe generica sia un derivato di node */
    static_assert(is_base_of<Node,T>::value);

    private:
        /* Methods */

        /* Metodo helper sfruttato dalla preorder */
        void preorder_helper(T *node);
        /* Metodo helper sfruttato dalla inorder */
        void inorder_helper(T *node);
        /* Metodo helper sfruttato dalla postorder */
        void postorder_helper(T *node);
        /* Metodo helper sfruttato dalla tree_height */
        int tree_height_helper(T *node);
        /* Metodo helper sfruttato dalla search */
        T *search_helper(T *node,int key);

    protected:
        T *root;

        /* Pure virtual function */

        /* Metodo helper sfruttato dalla print */
        virtual void print_helper(T *node, string indentation, bool last) = 0;

    public:
        /* Constructor */
        AbstractBinarySearchTree();

        /* Methods*/

        /* Visita anticipata: nodo -> left -> right */
        void preorder();
        /* Visita simmetrica: left -> nodo -> right */
        void inorder();
        /* Visita differita: left -> right -> nodo */
        void postorder();
        /* Calcola altezza albero binario di ricerca */
        int tree_height();
        /* Ricerca in un albero binario di ricerca */
        T *search(int key);
        /* Ricerca del nodo con chiave minima */
        T *minimum(T *node);
        /* Ricerca del nodo con chiave massima */
        T *maximum(T *node);
        /* Trova il successore del dato nodo */
        T *successor(T* node);
        /* Trova il predecessore di un dato nodo */
        T *predecessor(T* node);
        /* Stampa dell'albero */
        void print_tree();

        /* Getter */
        T *get_root();

        /* Pure virtual function */

        /* Inserimento di una chiave in un albero di ricerca binaria */
        virtual void insert(int key) = 0;
        /* Cancellazione di un nodo con una data chiave */
        virtual T *delete_node(T *node) = 0;
};

template<typename T>
AbstractBinarySearchTree<T>::AbstractBinarySearchTree()
{
    root = nullptr;
}

/* Metodo helper sfruttato dalla preorder */
template<typename T>
void AbstractBinarySearchTree<T>::preorder_helper(T *node)
{
    if(node != nullptr)
    {
        cout << node->key << " ";     /* visita nodo */
        preorder_helper(node->left);  /* visita figlio sinistro */
        preorder_helper(node->right); /* visita figlio destro */
    }
}

/* Metodo helper sfruttato dalla inorder */
template<typename T>
void AbstractBinarySearchTree<T>::inorder_helper(T *node)
{
    if(node != nullptr)
    {
        inorder_helper(node->left);  /* Visita figlio sinistro*/
        cout << node->key << " ";    /* Visita nodo */
        inorder_helper(node->right); /* Visita figlio destro */
    }
}

/* Metodo helper sfruttato dalla postorder */
template<typename T>
void AbstractBinarySearchTree<T>::postorder_helper(T *node)
{
    if(node != nullptr)
    {
        postorder_helper(node->left);  /* Visita figlio sinistro*/
        postorder_helper(node->right); /* Visita figlio destro */
        cout << node->key << " ";      /* Visita nodo */
    }
}

/* Metodo helper sfruttato dalla tree_height */
template<typename T>
int AbstractBinarySearchTree<T>::tree_height_helper(T *node)
{
    if(node != nullptr)
    {
        return 1 + max(tree_height_helper(node->right),tree_height_helper(node->left));
    }
    else
    {
        return 0;
    }
}

/* Metodo helper sfruttato dalla search */
template<typename T>
T *AbstractBinarySearchTree<T>::search_helper(T *node, int key)
{
    /* Se il nodo è nullo o se la chiave ricercata coincide con la chiave del nodo */
    if(node == nullptr || key == node->key)
    {
        /* Ritorna il nodo */
        return node;
    }

    /* 
    Se la chiave è minore di quella del nodo attuale allora dobbiamo proseguire 
    la ricerca con il figlio sinistro viste le proprietà dell'albero binario di ricerca
    */
    if(key < node->key)
    {
        return search_helper(node->left,key);
    }
    else
    {
        /* 
        Altrimenti la chiave sarà maggiore di quella del nodo attuale, per cui dovremo
        proseguire la ricerca con il figlio destro viste le proprietà dell'ABR
        */
       return search_helper(node->right,key);
    }
}

/* Ricerca del nodo con chiave minima */
template<typename T>
T *AbstractBinarySearchTree<T>::minimum(T *node)
{
    /* 
    Per le proprietà dell'ABR avremo un valore minore rispetto alla chiave del nodo corrente
    nel corrispettivo figlio sinistro, peranto basterà iterare fino a quando esiste un figlio 
    sinistro per trovare il valore minimo presente nell'ABR
    */
    while(node->left != nullptr)
    {
        node = node->left;
    }

    return node;
}

/* Ricerca del nodo con chiave massima */
template<typename T>
T *AbstractBinarySearchTree<T>::maximum(T *node)
{
    /* 
    Per le proprietà dell'ABR avremo un valore maggiore rispetto alla chiave del nodo corrente
    nel corrispettivo figlio destro, peranto basterà iterare fino a quando esiste un figlio 
    destro per trovare il valore massimo presente nell'ABR
    */
   while(node->right != nullptr)
   {
       node = node->right;
   }

   return node;
}

/* Trova il successore del dato nodo */
template<typename T>
T *AbstractBinarySearchTree<T>::successor(T *node)
{
    /* Se il nodo ha un figlio destro allora il successore è il minimo del sottoalbero destro */
    if(node->right != nullptr)
    {
        return minimum(node->right);
    }

    /* 
    Altrimenti il successore è il primo antenato del nodo tale che il nodo si trovi nel 
    sottoalbero sinistro
    */
   T *y = node->parent;
   while(y != nullptr && node == y->right)
   {
       node = y;
       y = y->parent;
   }

   return y;
}

/* Trova il predecessore di un dato nodo */
template<typename T>
T *AbstractBinarySearchTree<T>::predecessor(T *node)
{
    /* Se il nodo ha un figlio sinistro allora il successore è il massimo del sottoalbero sinistro */
    if(node->left != nullptr)
    {
        return maximum(node->left);
    }

    /* 
    Altrimenti il successore è il primo antenato del nodo tale che il nodo si trovi nel 
    sottoalbero destro
    */
   T *y = node->parent;
   while(y != nullptr && node == y->left)
   {
       node = y;
       y = y->parent;
   }

   return y;
}

/* Getter della rooot */
template<typename T>
T *AbstractBinarySearchTree<T>::get_root()
{
    return this->root;
}

/* Visita anticipata: nodo -> left -> right */
template<typename T>
void AbstractBinarySearchTree<T>::preorder()
{
    preorder_helper(root);
}

/* Visita simmetrica: left -> nodo -> right */
template<typename T>
void AbstractBinarySearchTree<T>::inorder()
{
    inorder_helper(root);
}

/* Visita differita: left -> right -> nodo */
template<typename T>
void AbstractBinarySearchTree<T>::postorder()
{
    postorder_helper(root);
}

/* Calcola altezza albero binario di ricerca */
template<typename T>
int AbstractBinarySearchTree<T>::tree_height()
{
    return tree_height_helper(root);
}

/* Ricerca in un albero binario di ricerca */
template<typename T>
T *AbstractBinarySearchTree<T>::search(int key)
{
    return search_helper(root,key);
}

/* Stampa dell'albero */
template<typename T>
void AbstractBinarySearchTree<T>::print_tree()
{
    print_helper(root,"",true);
}

#endif