#include "NumSet.h"

/*===============================
           CONSTRUCTOR
================================*/
NumSet::NumSet(RBTree *rb_tree):rb_tree{rb_tree}{}

NumSet::NumSet():NumSet{new RBTree}{}

/*===============================
           Destructor
================================*/

NumSet::~NumSet()
{
    delete rb_tree;
}

/*===============================
            METHODS
================================*/

/* Metodo di supporto alla join, utile ad eseguire un merge verso destra dell'albero sinistro */
RBTree *NumSet::join_right(RBNode *left_tree, int k, RBNode *right_tree)
{
    /* Calcoliamo la Black Height dei corrispettivi alberi passati in input */
    auto left_tree_bh = rb_tree->black_height(left_tree);
    auto right_tree_bh = rb_tree->black_height(right_tree);

    /* Se la Black Height dei due alberi coincide */
    if(left_tree_bh == right_tree_bh)
    {
        /* Costruiamo un nuovo albero RB */
        RBTree *rbt = new RBTree;

        /* Costruiamo un nuovo nodo da inserire come radice */
        RBNode *root = new RBNode;
        root->key = k;
        root->color = RED;
        root->left =  left_tree;
        root->right = right_tree;
        root->parent = nullptr;

        /* Inseriamo il nuovo nodo nell'albero RB */
        rbt->set_root(root);

        /* Ritorniamo il nuovo albero */
        return rbt;
    }
    else
    {
        /* 
        Se non è uguale dobbiamo scendere lungo il lato destro dell'albero sinistro 
        fino a quando non troviamo un nodo con la stessa altezza
        */

        /* Costruiamo un nuovo nodo RB: L' */
        RBNode *l_first = left_tree->left;
        /* Costruiamo un nuovo nodo RB: R' */
        RBNode *r_first = left_tree->right;
        /* Costruiamo un nuovo nodo da inserire come radice del nuovo albero da costruire */
        RBNode *t_first = new RBNode;

        /* 
        Prendiamo come nuova key, la chiave della radice dell'albero sinistro 
        che chiameremo: k' 
        */
        int k_first = left_tree->key;
        /* 
        Prendiamo come nuovo colore, il colore della radice dell'albero sinistro 
        che chiameremo: c' 
        */
       bool c_first = left_tree->color;

       /* 
       Creiamo ora un nuovo nodo avente:
       - chiave k'
       - colore c' 
       - figlio sinistro: L'
       - figlio destro: join_right(R',k,tree_right)

       Chiameremo tale nodo T'
       */
       t_first->key = k_first;
       t_first->color = c_first;
       t_first->parent = nullptr;
       t_first->left = l_first;
       t_first->right = join_right(r_first,k,right_tree)->get_root();

        /* 
        Se il nodo costruito è nero e se il corrispettivo figlio destro
        e nipote destro hanno colore rosso 
        */
       if((c_first == BLACK) && (t_first->right->color == RED) && (t_first->right->right->color == RED))
       {
            /* Cambiamo il colore del nipote destro a nero */
            t_first->right->right->color = BLACK;
            /* Ruotiamo T' a sinistra */
            RBTree *T_first = new RBTree;
            T_first->set_root(t_first);
            T_first->left_rotate(T_first->get_root());

            /* Ritorn a il nuovo albero*/
            return T_first;
       }
       else
       {
           /* Costruiamo l'abero da ritornare */
            RBTree *T_first = new RBTree;
            T_first->set_root(t_first);

            /* Ritorn a il nuovo albero*/
            return T_first;
       }
    }
}

/* Getter */
RBTree *NumSet::get_rbtree()
{
    return this->rb_tree;
}

/* Setter */
void NumSet::set_rbtree(RBTree *rb_tree)
{
    this->rb_tree = rb_tree;
}