#include "Bst.h"

/* Cancellazione di un nodo con una data chiave */
Node *Bst::delete_node(Node *node)
{
    /* Se il nodo da cancellare non ha figlio sinistro */
    if(node->left == nullptr)
    {
        /* Rimpiazziamo il nodo da eleminare con il suo figlio destro */
        transplant(node,node->right);
    }
    else if(node->right == nullptr)
    {
        /* 
        Se il nodo da cancellare non ha figlio destro, rimpiazziamo il nodo da eliminare
        con il suo figlio sinistro
        */
       transplant(node,node->left);
    }
    else
    {
        /* 
        In questo caso il nodo da eliminare avrà entrambi i figli.
        Troviamo il successore del nodo:
        */
       Node *y = minimum(node->right);

       /* Se il nodo da eliminare non è il padre del successore */
       if(y->parent != node)
       {
           /* Scambia il successore con il figlio sinistro del successore stesso */
           transplant(y, y->right);
           /* il nuovo figlio destro di y sarà il figlio sinistro del nodo da eliminare */
           y->right = node->right;
           /* Dobbiamo ora aggiornare il padre del figlio destro */
           y->right->parent = y;
       }
       /* Scambiamo il nodo da eliminare con y */
       transplant(node,y);
       /*Aggiorniamo il figlio sinistro di y */
       y->left = node->left;
       /* Dobbiamo ora aggiornare il padre del figlio sinistro */
       y->left->parent = y;
    }

    return node;
}

/* Metodo helper sfruttato dalla print */
void Bst::print_helper(Node *node, string indentation, bool last)
{
    if(node != nullptr)
    {
        cout << indentation;
        if(last)
        {
            cout << "└────";
            indentation += "     ";
        }
        else
        {
            cout<<"├────";
		    indentation += "|    ";
        }

        cout << node->key << endl;

        print_helper(node->left, indentation, false);
        print_helper(node->right, indentation, true);
    }
}

/* Inserimento di una chiave in un albero di ricerca binaria */
void Bst::insert(int key)
{
    /* Costruiamo un nuovo nodo con la chiave passata come argomento */
    Node *node_to_add = new Node;
    node_to_add->parent = nullptr;
    node_to_add->left = nullptr;
    node_to_add->right =  nullptr;
    node_to_add->key = key;

    /* Dichiariamo un puntatore a nodo e inizializziamolo a nullptr */
    Node *y = nullptr;

    /* Prendiamo la root ed assegnamola ad x */
    Node *x = root;

    while(x != nullptr)
    {
        /* Teniamo traccia del padre del nodo da aggiungere */
        y = x;

        if(node_to_add->key < x->key)
        {
            x = x->left;
        }
        else
        {
            x = x->right;
        }
    }

    /* y è il padre del nodo da aggiungere */
    node_to_add->parent = y;

    /* Se il nodo da aggiungenre ha il padre nullo allore il nodo da aggiungere è la radice */
    if(y == nullptr)
    {
        this->root = node_to_add;
    }
    else if(node_to_add->key < y->key)
    {
        /* 
        Se il nodo da agiungere ha la chiave minore di quella del padre, allora sarà il suo figlio
        sinistro
        */
        y->left = node_to_add;
    }
    else
    {
       /* 
        Altrimenti il nodo da agiungere ha la chiave maggiore di quella del padre, 
        allora sarà il suo figlio destro
        */ 
       y->right = node_to_add;
    }
}