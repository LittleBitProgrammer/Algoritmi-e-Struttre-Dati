#include "NumSet.h"

/*===============================
            METHODS
================================*/

/* Metodo di supporto alla join, utile ad eseguire un merge verso destra dell'albero sinistro */
RBNode *NumSet::join_right(RBNode *left_tree, int k, RBNode *right_tree)
{
    /* Calcoliamo la Black Height dei corrispettivi alberi passati in input */
    auto left_tree_bh = black_height(left_tree);
    auto right_tree_bh = black_height(right_tree);

    /* Se la Black Height dei due alberi coincide */
    if(left_tree_bh == right_tree_bh)
    {
        /* Costruiamo un nuovo nodo da inserire come radice */
        auto *root = new RBNode;
        root->key = k;
        root->color = RED;
        root->left =  left_tree;
        root->right = right_tree;
        root->parent = left_tree->parent;

        if(root->left != get_tnull())
        {
            root->left->parent = root;
        }

        if(root->right != get_tnull())
        {
            root->right->parent = root;
        }

        /* Ritorniamo il nuovo albero */
        return root;
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
        auto *t_first = new RBNode;

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
       t_first->parent = left_tree->parent;
       t_first->left = l_first;
       t_first->right = join_right(r_first,k,right_tree);

       if(t_first->right != get_tnull() && t_first->right->parent == nullptr)
       {
           t_first->right->parent = t_first;
       }

        /*
        Se il nodo costruito è nero e se il corrispettivo figlio destro
        e nipote destro hanno colore rosso
        */
       if((c_first == BLACK) && (t_first->right->color == RED) && (t_first->right->right->color == RED))
       {
            /* Cambiamo il colore del nipote destro a nero */
            t_first->right->right->color = BLACK;

            /* Ruotiamo T' a sinistra */
            left_rotate(t_first);

            /* Ritorna il nuovo albero*/
            return t_first->parent;
       }
       else
       {
           /* Ritorna il nuovo albero */
            return t_first;
       }
    }
}

/* Metodo di supporto alla join, utile ad eseguire un merge verso sinistra dell'albero destro */
RBNode *NumSet::join_left(RBNode *left_tree, int k, RBNode *right_tree)
{
    /* Calcoliamo la Black Height dei corrispettivi alberi passati in input */
    auto left_tree_bh = black_height(left_tree);
    auto right_tree_bh = black_height(right_tree);

    /* Se la Black Height dei due alberi coincide */
    if(right_tree_bh == left_tree_bh)
    {
        /* Costruiamo un nuovo nodo da inserire come radice */
        auto *root = new RBNode;
        root->key = k;
        root->color = RED;
        root->left =  left_tree;
        root->right = right_tree;
        root->parent = right_tree->parent;

        if(root->left != get_tnull())
        {
            root->left->parent = root;
        }

        if(root->right != get_tnull())
        {
            root->right->parent = root;
        }

        /* Ritorniamo il nuovo albero */
        return root;
    }
    else
    {
        /*
        Se non è uguale dobbiamo scendere lungo il lato destro dell'albero sinistro
        fino a quando non troviamo un nodo con la stessa altezza
        */

       /* Costruiamo un nuovo nodo RB: L' */
        RBNode *l_first = right_tree->left;
        /* Costruiamo un nuovo nodo RB: R' */
        RBNode *r_first = right_tree->right;
        /* Costruiamo un nuovo nodo da inserire come radice del nuovo albero da costruire */
        auto *t_first = new RBNode;

        /*
        Prendiamo come nuova key, la chiave della radice dell'albero sinistro
        che chiameremo: k'
        */
        int k_first = right_tree->key;
        /*
        Prendiamo come nuovo colore, il colore della radice dell'albero sinistro
        che chiameremo: c'
        */
        bool c_first = right_tree->color;

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
       t_first->parent = right_tree->parent;
       t_first->right = r_first;
       t_first->left = join_left(left_tree,k,l_first);

        if(t_first->left != get_tnull() && t_first->left->parent == nullptr)
        {
            t_first->right->parent = t_first;
        }

       /*
        Se il nodo costruito è nero e se il corrispettivo figlio sinistro
        e nipote sinistro hanno colore rosso
       */
       if((c_first == BLACK) && (t_first->left->color == RED) && (t_first->left->left->color == RED))
       {
            /* Cambiamo il colore del nipote sinistro a nero */
            t_first->left->left->color = BLACK;
            /* Ruotiamo T' a sinistra */
            right_rotate(t_first);

            /* Ritorna il nuovo albero*/
            return t_first->parent;
       }
       else
       {
            /* Ritorna il nuovo albero */
            return t_first;
       }
    }
}

/*
    Metodo di supporto a diverse operazioni di insiemistica:
    - split
    - split_last
    - join2
    - union
    - intersect
*/
RBNode *NumSet::join(RBNode *left_tree, int k, RBNode *right_tree)
{
    /*
    Per la join di due alberi RB possono esserci quattro casi:
    - bh[left_tree] > bh[right_tree]
    - bh[right_tree] > bh[left_tree]
    - bh[left_tree] = bh[right_tree] con tl e tr neri
    - bh[left_tree] = bh[right_tree] con tl e tr non entrambi neri

    Per eseguire una join quindi dobbiamo prima individuare in quale dei tre casi ci troviamo
    */

   /* Calcoliamo la Black height dei due alberi */
   int left_tree_bh = RBTree::black_height(left_tree);
   int right_tree_bh = RBTree::black_height(right_tree);

   /* Caso 1: bh[left_tree] > bh[right_tree] */
   if(left_tree_bh > right_tree_bh)
   {
        /*
        Se la black height dell'albero di sinistra è maggiore di quella dell'albero di destra
        allora costruiremo un nuovo albero dato dalla join_right, che chiameremo T'
        */
        RBNode *t_first = join_right(left_tree,k,right_tree);
        /* Verifichiamo che le proprietà dell'albero RB siano rispettate */
        if((t_first->color == RED) && (t_first->right->color == RED))
        {
            /* Fix del colore sulla radice */
            t_first->color = BLACK;
        }

        /* Ritorniamo il nuovo albero */
        return t_first;
   }
   else if(right_tree_bh > left_tree_bh)
   {
        /* Caso 2: bh[right_tree] > bh[left_tree] */

        /*
        Se la black height dell'albero di destra è maggiore di quella dell'albero di sinistra
        allora costruiremo un nuovo albero dato dalla join_left, che chiameremo T'
        */
        RBNode *t_first = join_left(left_tree,k,right_tree);
        /* Verifichiamo che le proprietà dell'albero RB siano rispettate */
        if((t_first->color == RED) && (t_first->left->color == RED))
        {
            /* Fix del colore sulla radice */
            t_first->color = BLACK;
        }

        /* Ritorniamo il nuovo albero */
        return t_first;
   }
   else if((left_tree->color == BLACK) && (right_tree->color == BLACK))
   {
        /* Caso 3: bh[left_tree] = bh[right_tree] con tl e tr neri*/

        /* Creiamo un nuovo nodo che farà da radice per entrambi gli alberi */
        auto *root = new RBNode;
        root->key = k;
        root->color = RED;
        root->left = left_tree;
        root->right = right_tree;
        root->parent = get_tnull();

        /* Ritorniamo la radice */
        return root;
   }
   else
   {
       /* Caso 4: bh[left_tree] = bh[right_tree] con tl e tr non entrambi neri */

       /* Creiamo un nuovo nodo che farà da radice per entrambi gli alberi */
        auto *root = new RBNode;
        root->key = k;
        root->color = BLACK;
        root->left = left_tree;
        root->right = right_tree;
        root->parent = get_tnull();

        /* Ritorniamo la radice */
        return root;
   }
}

/*
Metodo di supporto a diverse operazioni di insiemistica:
- union
- intersect
- difference
*/
pair<pair<RBNode *,RBNode *>,int> NumSet::split(RBNode *tree, int key)
{
    /* Caso nodo foglia */
    if(tree == get_tnull())
    {
        /* Creiamo il nostro pair */
        pair<pair<RBNode *,RBNode *>,int> triple{{tree,tree},0};

        /* Ritorniamo la nostra tripla */
        return triple;
    }
    else
    {
        /* Creiamo il nostro pair */
        pair<pair<RBNode *,RBNode *>,int> triple{{tree->left,tree->right},tree->key};

        /* Se la chiave è uguale alla tree key */
        if(key == triple.second)
        {
            triple.second = 1;
            return triple;
        }
        else if (key < triple.second)
        {
            /* caso in cui la chiave è minore della tree key */

            /* Ricaviamo una nuova tripla dalla split ricorsiva */
            pair<pair<RBNode *,RBNode *>,int> triple2 = split(triple.first.first,key);

            /* Creiamo un nuovo pair */
            pair<pair<RBNode *,RBNode *>,int> triple3 = {{triple2.first.first,join(triple2.first.second,triple.second,triple.first.second)},triple2.second};

            /* Ritorniamo l'ultima tripla creata */
            return triple3;
        }
        else
        {
            /* Ricaviamo una nuova tripla dalla split ricorsiva */
            pair<pair<RBNode *,RBNode *>,int> triple2 = split(triple.first.second,key);

            /* Creiamo un nuovo pair */
            pair<pair<RBNode *,RBNode *>,int> triple3 = {{join(triple.first.first,triple.second,triple2.first.first),triple2.first.second},triple2.second};

            return triple3;
        }
    }
}

/* Operazione di unione tra due insiemi */
RBNode *NumSet::union_helper(RBNode *set1, RBNode *set2)
{
    if (set1 == get_tnull())
    {
        return set2;
    }
    else if (set2 == get_tnull())
    {
        return set1;
    }
    else
    {
        std::pair<std::pair<RBNode *, RBNode *>, int> triple2 {{set2->left,set2->right}, set2->key};
        auto triple = split(set1, triple2.second);

        auto tree_left = union_helper(triple.first.first, triple2.first.first);
        auto tree_right = union_helper(triple.first.second, triple2.first.second);

        return join(tree_left, triple2.second, tree_right);
    }
}

RBNode *NumSet::intersection_helper(RBNode *set1, RBNode *set2)
{
    if (set1 == get_tnull() || set2 == get_tnull())
    {
        return get_tnull();
    }
    else
    {
        std::pair<std::pair<RBNode *, RBNode *>, int> triple2 {{set2->left,set2->right}, set2->key};
        auto triple = split(set1, triple2.second);

        auto tree_left = intersection_helper(triple.first.first,triple2.first.first);
        auto tree_right = intersection_helper(triple.first.second,triple2.first.second);

        return (triple.second) ? join(tree_left,triple2.second,tree_right) : join2(tree_left,tree_right);
    }
}

pair<RBNode *,int> NumSet::split_last(RBNode *tree)
{
    std::pair<std::pair<RBNode *, RBNode*>, int> triple {{tree->left,tree->right},tree->key};

    if(triple.first.second == get_tnull())
    {
        std::pair<RBNode *,int> couple {triple.first.first,triple.second};
        return couple;
    }
    else
    {
        auto couple = split_last(triple.first.second);
        std::pair<RBNode *, int> couple2 {join(triple.first.first,triple.second,couple.first),couple.second};

        return couple2;
    }
}

RBNode *NumSet::join2(RBNode *left_tree, RBNode *right_tree)
{
    if (left_tree == get_tnull())
    {
        return right_tree;
    }
    else
    {
        auto couple = split_last(left_tree);
        return join(couple.first,couple.second,right_tree);
    }
}