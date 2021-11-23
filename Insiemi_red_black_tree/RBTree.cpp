#include <type_traits> /* swap */
#include "RBTree.h"


/*===============================
           ROTATION
================================*/

/* 
Le proprietà degli alberi RB potrebbero essere violate e devono essere ripristinate
mediante modifiche alla struttura dei puntatori mediante rotazioni:
- sinistra
- destra
*/

/* Rotazione a sinistra */
void RBTree::left_rotate(RBNode *x)
{
    /* Identifichiamo il nodo y come il figlio destro di x */
    RBNode *y = x->right;
    /* Il figlio destro di x diventa il figlio sinistro di y */
    x->right = y->left;

    /* Se la right di x non è nulla */
    if(y->left != TNULL)
    {
        /* Aggiorniamo il padre del figlio destro di x precedentemente cambiato */
        y->left->parent = x;
    }
    /* Cambiamo il padre di y con il padre di x */
    y->parent = x->parent;

    /* Se il padre di x è nullo */
    if(x->parent == TNULL)
    {
        /* Allora x era la root, per cui y diventerà la nuova root */
        root = y;
    }
    else if(x == x->parent->left)
    {
        /* se x era il figlio sinistro del padre allora dobbiamo aggiornarlo con il nuovo valore y */
        x->parent->left = y;
    }
    else
    {
        /* Altrimenti era il figlio destro, per cui dobbiamo aggiornarlo con il nuovo valore y */
        x->parent->right = y;
    }

    /* Il nuovo figlio sinistro di y è x */
    y->left = x;
    /* Per cui il nuovo padre di x sarà y */
    x->parent = y;
}

/* Rotazione a destra */
void RBTree::right_rotate(RBNode *x)
{
    /* Identifichiamo il nodo y come il figlio sinistro di x */
    RBNode *y = x->left;
    /* Il figlio sinistro di x diventa il figlio destro di y */
    x->left = y->right;

    /* Se la left di x non è nulla */
    if(y->right != TNULL)
    {
        /* Aggiorniamo il padre del figlio sinistro di x precedentemente cambiato */
        y->right->parent = x;
    }
    /* Cambiamo il padre di y con il padre di x */
    y->parent = x->parent;

    /* Se il padre di x è nullo */
    if(x->parent == TNULL)
    {
        /* Allora x era la root, per cui y diventerà la nuova root */
        root = y;
    }
    else if(x == x->parent->left)
    {
        /* se x era il figlio sinistro del padre allora dobbiamo aggiornarlo con il nuovo valore y */
        x->parent->left = y;
    }
    else
    {
        /* Altrimenti era il figlio destro, per cui dobbiamo aggiornarlo con il nuovo valore y */
        x->parent->right = y;
    }

    /* Il nuovo figlio destro di y è x */
    y->right = x;
    /* Per cui il nuovo padre di x sarà y */
    x->parent = y;
}

/*===============================
           INSERTION
================================*/
/* 
L'inserimento di un nodo in un albero RB è complesso ma viene eseguito in un tempo log n, 
esso prevede i seguenti passi:
- inserimento del nuovo nodo attraverso la procedura standard del BST
- Colorazione del nodo in rosso
- individuazione dei casi

Possiamo infatti avere tre casi differenti aggiungendo un nodo x e comportarci di conseguenza:
- 1°caso: lo zio di x è rosso
- 2°caso: lo zio di x è nero e x è figlio destro
- 3°caso: lo zio di x è nero e x è figlio sinistro

Le istruzioni dei tre casi vengono commentate nella fixup dell'insert.
*/

/* Rispristino di un albero RB dalle violazioni causate dall'inserimento BST */
void RBTree::insert_fixup(RBNode *&root, RBNode *&k)
{
     RBNode *u;
    while (k->parent->color == RED) {
      if (k->parent == k->parent->parent->right) {
        u = k->parent->parent->left;
        if (u->color == RED) {
          u->color = BLACK;
          k->parent->color = BLACK;
          k->parent->parent->color = RED;
          k = k->parent->parent;
        } else {
          if (k == k->parent->left) {
            k = k->parent;
            right_rotate(k);
          }
          k->parent->color = BLACK;
          k->parent->parent->color = RED;
          left_rotate(k->parent->parent);
        }
      } else {
        u = k->parent->parent->right;

        if (u->color == RED) {
          u->color = BLACK;
          k->parent->color = BLACK;
          k->parent->parent->color = RED;
          k = k->parent->parent;
        } else {
          if (k == k->parent->right) {
            k = k->parent;
            left_rotate(k);
          }
          k->parent->color = BLACK;
          k->parent->parent->color = RED;
          right_rotate(k->parent->parent);
        }
      }
      if (k == root) {
        break;
      }
    }
    root->color = BLACK;
}

/* Inserimento di una chiave nell'albero RB */
void RBTree::insert(int key)
{
    /* Dichiamo e inizializziamo un nuovo nodo */
    RBNode *node_to_add = new RBNode;
    node_to_add->parent = nullptr;
    node_to_add->key = key;
    node_to_add->left = TNULL;
    node_to_add->right = TNULL;
    node_to_add->color = RED;

    RBNode *y = TNULL;
    RBNode *x = this->root;

    while (x != TNULL) 
    {
        y = x;
        if (node_to_add->key < x->key) 
        {
            x = x->left;
        } 
        else 
        {
            x = x->right;
        }
    }

    node_to_add->parent = y;
    if (y == TNULL) 
    {
      root = node_to_add;
    } 
    else if (node_to_add->key < y->key) 
    {
      y->left = node_to_add;
    } 
    else
    {
      y->right = node_to_add;
    }

    if (node_to_add->parent == TNULL) 
    {
      node_to_add->color = BLACK;
      return;
    }

    if (node_to_add->parent->parent == TNULL) 
    {
      return;
    }

    /* Correggiamo le violazioni sull'albero RB */
    insert_fixup(root, node_to_add);
    
}

/*===============================
            PRINTING
================================*/

/* Metodo di supporto utilizzato dalla print */
void RBTree::print_helper(RBNode *root, string indentation, bool last)
{
    /* Stampa la struttura dell'albero a schermo */
    if(root != TNULL)
    {
        cout << indentation;
        if(last)
        {
            cout << "R----";
            indentation += "     ";
        }
        else
        {
            cout << "L----";
            indentation += "|     ";
        }

        string node_color = root->color? "BLACK" : "RED";
        cout << root->key << "(" << node_color << ")" << endl;

        print_helper(root->left, indentation, false);
        print_helper(root->right, indentation, true);
    }
}

/*===============================
            DELETE
================================*/

/* 
La cancellazione di un nodo in un albero RB è complesso ma viene eseguito in un tempo log n.
L'algoritmo di cancellazione oer alberi RB è costruito sull'algoritmo di cancellazione per 
alberi binari di ricerca, però dopo la cancellazione si deve decidere se è necessario 
ribilanciare o meno.

In particolare le operazioni di ripristino del bilanciamento sono necessarie solo quando il nodo
cancellato/spostato è nero.
*/

/* Metodo di supporto utilizzato dalla delete_key */
void RBTree::delete_helper(RBNode *node, int key)
{
    /* Inizializziamo z a nullptr */
    RBNode *z = TNULL;
    /* Dichiariamo x e y come due nodi */
    RBNode *x, *y;

    /* Prima di cancellare il nodo verifichiamo che il nodo esista */
    while(node != TNULL)
    {
        /* se la chiave coincide con il nodo analizzato */
        if(node->key == key)
        {
            /* assegnamo tale nodo a z */
            z = node;
            break;
        }

        /* Se la chiave è >=  della chiave del nodo vai a destra altrimenti a sinistra */
        if(key >= node->key)
        {
            node = node->right;
        }
        else
        {
            node = node->left;
        }
    }

    /* Se la chiave non è stata trovata, lanciamo un errore */
    if(z == TNULL)
    {
        cout << "Chiave non trovata nell'albero" << endl;
        return;
    }

    /* 
    Se la chiave verrà trovata in un nodo, possiamo  proseguire con l'esecuzione del
    nostro algoritmo.

    Quindi teniamo traccia di z, assegnandola ad y.
    */
   y = z;
   /* Pochè il colore del nodo y potrebbe cambiare, memorizziamolo in una variabile */
   bool y_original_color = y->color;

   /* Se il figlio sinistro di z è nullo */
   if(z->left == TNULL)
   {
       /* Assegnamo ad x il figlio destro di z */
       x = z->right;
       /* Scambiamo z con z->right */
       transplant(z,z->right);
   }
   else if(z->right == TNULL)
   {
       /* 
       Se il figlio destro di z è nullo,
       assegnamo ad x il figlio destro di z
       */
      x = z->left;
      /* Scambiamo z con z->left */
      transplant(z,z->left);
   }
   else
   {
       /* 
       In questo caso z ha entrambi i figli.
       y assumerà il valore del suo successore
       */
      y = minimum(z->right);
      /* Aggiorniamo il colore originale */
      y_original_color = y->color;
      /* Assegnamo ad x il figlio destro di z */
      x = y->right;

      /* Se il padre di y è z*/
      if(y->parent == z)
      {
          /* Aggiorniamo il padre di x */
          x->parent = y;
      }
      else
      {
          /* Scambiamo y con il suo figlio destro ed aggiorniamo i suo collegamenti */
          transplant(y,y->right);
          y->right = z->right;
          y->right->parent = y;
      }
      /* Scambiamo z e y ed aggiorniamo y */
      transplant(z,y);
      y->left = z->left;
      y->left->parent = y;
      y->color = z->color;
   }

   /* Solo nel caso in cui il colore originale sia nero passiamo lanciare la delete fixup */
   if(y_original_color == BLACK)
   {
       delete_fixup(x);
   }
}

/* Ripristino delle violazioni dovute alla cancellazione di un nodo nell'albero RB */
void RBTree::delete_fixup(RBNode *x)
{
   RBNode *w;

   /* 
   Eseguiremo un ciclo while fintanto che il nodo è diverso dalla radice e fino a quando 
   il suo colore sarà nero 
   */ 
  while((x != root) && x->color == BLACK)
  {
      /* 
      Prima di tutto dobbiamo capire se x è figlio sinistro o destro, così da applicare
      regole attinenti al ramo in cui si trovano.

      Logicamente le applicazioni di un ramo, esempio il sinistro, saranno le speculari del
      suo opposto, ovvero il destro.
      */
     if(x == x->parent->left)
     {
         /* Figlio sinistro */

         /* Assegnamo a w il fratello di x */
         w = x->parent->right;
         if(w->color == RED)
         {
             /* Caso 1: il fratello w di x è rosso */
             w->color = BLACK;
             x->parent->color = RED;
             left_rotate(x->parent);
             w = x->parent->right;
         }
         if((w->left->color == BLACK) && (w->right->color == BLACK))
         {
             /* Caso 2: il fratello w di x è nero ed entrambi i suoi figli sono neri */
             w->color = RED;
             x = x->parent;
         }
         else
         {
             if(w->right->color == BLACK)
             {
                /* 
                Caso 3: il fratello w di x è nero, il figlio sinistro di w è rosso e il 
                figlio destro di w è nero
                */
               w->left->color = BLACK;
               w->color = RED;
               right_rotate(w);
               w = x->parent->right;
             }
             /* Caso 4: il fratello w di x è nero e il figlio destro di w è rosso */
             w->color = x->parent->color;
             x->parent->color = BLACK;
             w->right->color = BLACK;
             left_rotate(x->parent);
             x = root;
         }
     }
     else
     {
         /* Figlio destro */

         /* Assegnamo a w il fratello di x */
         w = x->parent->left;
         if(w->color == RED)
         {
             /* Caso 1: il fratello w di x è rosso */
             w->color = BLACK;
             x->parent->color = RED;
             right_rotate(x->parent);
             w = x->parent->left;
         }
         if((w->right->color == BLACK) && (w->right->color == BLACK))
         {
             /* Caso 2: il fratello w di x è nero ed entrambi i suoi figli sono neri */
             w->color = RED;
             x = x->parent;
         }
         else
         {
             if(w->left->color == BLACK)
             {
                /* 
                Caso 3: il fratello w di x è nero, il figlio sinistro di w è rosso e il 
                figlio destro di w è nero
                */
               w->right->color = BLACK;
               w->color = RED;
               left_rotate(w);
               w = x->parent->left;
             }
             /* Caso 4: il fratello w di x è nero e il figlio destro di w è rosso */
             w->color = x->parent->color;
             x->parent->color = BLACK;
             w->left->color = BLACK;
             right_rotate(x->parent);
             x = root;
         }
     }
  }
  /* Assegnamo ad x il colore nero */
  x->color = BLACK;
}

/* Cancellazione di un nodo con una data chiave */
void RBTree::delete_key(int key)
{
    delete_helper(root,key);
}

RBTree::RBTree()
{
    TNULL = new RBNode;
    TNULL->color = BLACK;
    TNULL->left = nullptr;
    TNULL->right = nullptr;
    TNULL->parent = nullptr;
    root = TNULL;
}

/* Ricerca del nodo con chiave minima */
RBNode *RBTree::minimum(RBNode *node)
{
    /* 
    Per le proprietà dell'ABR avremo un valore minore rispetto alla chiave del nodo corrente
    nel corrispettivo figlio sinistro, peranto basterà iterare fino a quando esiste un figlio 
    sinistro per trovare il valore minimo presente nell'ABR
    */
    while(node->left != TNULL)
    {
        node = node->left;
    }

    return node;
}

/* Ricerca del nodo con chiave massima */
RBNode *RBTree::maximum(RBNode *node)
{
    /* 
    Per le proprietà dell'ABR avremo un valore maggiore rispetto alla chiave del nodo corrente
    nel corrispettivo figlio destro, peranto basterà iterare fino a quando esiste un figlio 
    destro per trovare il valore massimo presente nell'ABR
    */
   while(node->right != TNULL)
   {
       node = node->right;
   }

   return node;
}

/* Metodo helper sfruttato dalla preorder */
void RBTree::preorder_helper(RBNode *node)
{
    if(node != TNULL)
    {
        cout << node->key << " ";     /* visita nodo */
        preorder_helper(node->left);  /* visita figlio sinistro */
        preorder_helper(node->right); /* visita figlio destro */
    }
}

/* Metodo helper sfruttato dalla inorder */
void RBTree::inorder_helper(RBNode *node)
{
    if(node != TNULL)
    {
        inorder_helper(node->left);  /* Visita figlio sinistro*/
        cout << node->key << " ";    /* Visita nodo */
        inorder_helper(node->right); /* Visita figlio destro */
    }
}

/* Metodo helper sfruttato dalla postorder */
void RBTree::postorder_helper(RBNode *node)
{
    if(node != TNULL)
    {
        postorder_helper(node->left);  /* Visita figlio sinistro*/
        postorder_helper(node->right); /* Visita figlio destro */
        cout << node->key << " ";      /* Visita nodo */
    }
}

/* Trova il successore del dato nodo */
RBNode *RBTree::successor(RBNode *node)
{
    /* Se il nodo ha un figlio destro allora il successore è il minimo del sottoalbero destro */
    if(node->right != TNULL)
    {
        return minimum(node->right);
    }

    /* 
    Altrimenti il successore è il primo antenato del nodo tale che il nodo si trovi nel 
    sottoalbero sinistro
    */
   RBNode *y = node->parent;
   while(y != TNULL && node == y->right)
   {
       node = y;
       y = y->parent;
   }

   return y;
}

/* Trova il predecessore di un dato nodo */
RBNode *RBTree::predecessor(RBNode *node)
{
    /* Se il nodo ha un figlio sinistro allora il successore è il massimo del sottoalbero sinistro */
    if(node->left != TNULL)
    {
        return maximum(node->left);
    }

    /* 
    Altrimenti il successore è il primo antenato del nodo tale che il nodo si trovi nel 
    sottoalbero destro
    */
   RBNode *y = node->parent;
   while(y != TNULL && node == y->left)
   {
       node = y;
       y = y->parent;
   }

   return y;
}

/* Metodo helper sfruttato dalla search */
RBNode *RBTree::search_helper(RBNode *node, int key)
{
    /* Se il nodo è nullo o se la chiave ricercata coincide con la chiave del nodo */
    if(node == TNULL || key == node->key)
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

/* Metodo helper sfruttato dalla tree_height */
int RBTree::tree_height_helper(RBNode *node)
{
    if(node != TNULL)
    {
        return 1 + max(tree_height_helper(node->right),tree_height_helper(node->left));
    }
    else
    {
        return 0;
    }
}

/* Calcola l'altezza nera di un dato nodo x */
int RBTree::black_height(RBNode *node)
{
    if(node == TNULL)
    {
        return 0;
    }
    else
    {
        /* calcoliamo l'altezza del sotto-ramo di sinistra */
        int left_black_height = black_height(node->left);

        /* calcoliamo l'altezza del sotto-ramo di destra */
        int right_black_height = black_height(node->right);

        int add = node->color == BLACK ? 1 : 0;

        /* Se i due  sotto-ramo sono diversi allora mostriamo un errore */
        if(left_black_height != right_black_height)
        {
            throw std::runtime_error("the tree does not respect the properties of Red Black Trees");
        }

        /* Se sono uguali, basterà tornare l'altezza di un solo sottoramo */
        return left_black_height + add;
    }
}

/* Setter */
void RBTree::set_root(RBNode *root)
{
    root->parent = TNULL;
    this->root = root;
}

/* Getter */
RBNode *RBTree::get_tnull()
{
    return this->TNULL;
}