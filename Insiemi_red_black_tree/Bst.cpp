#include "Bst.h"

Bst::Bst()
{
    root = nullptr; /* Radice a puntatore nullo */
}

/* Metodo helper sfruttato dalla preorder */
void Bst::preorder_helper(Node *node)
{
    if(node != nullptr)
    {
        cout << node->key << " ";     /* visita nodo */
        preorder_helper(node->left);  /* visita figlio sinistro */
        preorder_helper(node->right); /* visita figlio destro */
    }
}

/* Metodo helper sfruttato dalla inorder */
void Bst::inorder_helper(Node *node)
{
    if(node != nullptr)
    {
        inorder_helper(node->left);  /* Visita figlio sinistro*/
        cout << node->key << " ";    /* Visita nodo */
        inorder_helper(node->right); /* Visita figlio destro */
    }
}

/* Metodo helper sfruttato dalla postorder */
void Bst::postorder_helper(Node *node)
{
    if(node != nullptr)
    {
        postorder_helper(node->left);  /* Visita figlio sinistro*/
        postorder_helper(node->right); /* Visita figlio destro */
        cout << node->key << " ";      /* Visita nodo */
    }
}

/* Metodo helper sfruttato dalla tree_height */
int Bst::tree_height_helper(Node *node)
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
Node *Bst::search_helper(Node *node, int key)
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
Node *Bst::minimum(Node *node)
{
    Node *x;

    /* 
    Per le proprietà dell'ABR avremo un valore minore rispetto alla chiave del nodo corrente
    nel corrispettivo figlio sinistro, peranto basterà iterare fino a quando esiste un figlio 
    sinistro per trovare il valore minimo presente nell'ABR
    */
    while(node->left != nullptr)
    {
        x = node->left;
    }

    return x;
}

/* Ricerca del nodo con chiave massima */
Node *Bst::maximum(Node *node)
{
    Node *x;

    /* 
    Per le proprietà dell'ABR avremo un valore maggiore rispetto alla chiave del nodo corrente
    nel corrispettivo figlio destro, peranto basterà iterare fino a quando esiste un figlio 
    destro per trovare il valore massimo presente nell'ABR
    */
   while(node->right != nullptr)
   {
       x = node->right;
   }

   return x;
}

/* Trova il successore del dato nodo */
Node *Bst::successor(Node *node)
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
   Node *y = node->parent;
   while(y != nullptr && node == y->right)
   {
       node = y;
       y = y->parent;
   }

   return y;
}

/* Trova il predecessore di un dato nodo */
Node *Bst::predecessor(Node *node)
{
    /* Se il nodo ha un figlio sinistro allora il successore è il massimo del sottoalbero sinistro */
    if(node->left != nullptr)
    {
        return maximum(node->right);
    }

    /* 
    Altrimenti il successore è il primo antenato del nodo tale che il nodo si trovi nel 
    sottoalbero destro
    */
   Node *y = node->parent;
   while(y != nullptr && node == y->left)
   {
       node = y;
       y = y->parent;
   }

   return y;
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

/* Getter della rooot */
Node *Bst::get_root()
{
    return this->root;
}

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

/* Metodo per sostituire un sottoalbero con un altro */
void Bst::transplant(Node *u, Node *v)
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

/* Metodo helper sfruttato dalla print */
void Bst::print_helper(Node *node, string indentation, bool last)
{
    //TODO::commentare questo metodo
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

/* Visita anticipata: nodo -> left -> right */
void Bst::preorder()
{
    preorder_helper(root);
}

/* Visita simmetrica: left -> nodo -> right */
void Bst::inorder()
{
    inorder_helper(root);
}

/* Visita differita: left -> right -> nodo */
void Bst::postorder()
{
    postorder_helper(root);
}

/* Calcola altezza albero binario di ricerca */
int Bst::tree_height()
{
    return tree_height_helper(root);
}

/* Ricerca in un albero binario di ricerca */
Node *Bst::search(int key)
{
    return search_helper(root,key);
}

/* Stampa dell'albero */
void Bst::print_tree()
{
    print_helper(root,"",true);
}