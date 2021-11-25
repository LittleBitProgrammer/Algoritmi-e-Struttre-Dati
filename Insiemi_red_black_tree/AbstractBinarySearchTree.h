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

template<typename T>
class AbstractBinarySearchTree
{
    protected:
        T *root;

        /* Methods */

        /* Metodo per sostituire un sottoalbero con un altro */
        void transplant(T *u, T *v);
        /* Pure virtual function */

        /* Metodo helper sfruttato dalla print */
        virtual void print_helper(T *node, string indentation, bool last) = 0;
        /* Metodo helper sfruttato dalla preorder */
        virtual void preorder_helper(T *node) = 0;
        /* Metodo helper sfruttato dalla inorder */
        virtual void inorder_helper(T *node) = 0;
        /* Metodo helper sfruttato dalla postorder */
        virtual void postorder_helper(T *node) = 0;
        /* Metodo helper sfruttato dalla search */
        virtual T *search_helper(T *node,int key) = 0;
        /* Metodo helper sfruttato dalla tree_height */
        virtual int tree_height_helper(T *node) = 0;

    public:
        /* Constructor */
        AbstractBinarySearchTree();
        /* Destructor */
        virtual ~AbstractBinarySearchTree() = 0;

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
        /* Stampa dell'albero */
        void print_tree();

        /* Getter */
        T *get_root();

        /* Setter */
        void set_root(T *root);

        /* Pure virtual function */

        /* Inserimento di una chiave in un albero di ricerca binaria */
        virtual void insert(int key) = 0;
        /* Cancellazione di un nodo con una data chiave */
        virtual void delete_key(int key) = 0;
        /* Ricerca del nodo con chiave minima */
        virtual T *minimum(T *node) = 0;
        /* Ricerca del nodo con chiave massima */
        virtual T *maximum(T *node) = 0;
        /* Trova il successore del dato nodo */
        virtual T *successor(T* node) = 0;
        /* Trova il predecessore di un dato nodo */
        virtual T *predecessor(T* node) = 0;
};

template<typename T>
AbstractBinarySearchTree<T>::AbstractBinarySearchTree()
{
    root = nullptr;
}

/* Getter della rooot */
template<typename T>
T *AbstractBinarySearchTree<T>::get_root()
{
    return this->root;
}

/* Setter della rooot */
template<typename T>
void AbstractBinarySearchTree<T>::set_root(T *root)
{
    this->root = root;
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

/* Metodo per sostituire un sottoalbero con un altro */
template<typename T>
void AbstractBinarySearchTree<T>::transplant(T *u, T *v)
{
    /* Se il padre di u è nullo allora la nuova root è v */
    if(u->parent == nullptr)
    {
        this->root = v;
    }
    else if (u == u->parent->left)
    {
        /* Se u è il figlio sinistro del padre allora il nuovo figlio sinistro del padre è v */
        u->parent->left = v;
    }
    else
    {
        /* Altrimenti il fliglio destro del padre  di u sarà v */
        u->parent->right = v;
    }

    if(v != nullptr)
    {
        v->parent = u->parent;
    }
}
template<typename T>
AbstractBinarySearchTree<T>::~AbstractBinarySearchTree<T>() = default;;

#endif