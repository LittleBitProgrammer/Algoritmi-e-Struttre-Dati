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
    if(x->right != nullptr)
    {
        /* Aggiorniamo il padre del figlio destro di x precedentemente cambiato */
        x->right->parent = x;
    }
    /* Cambiamo il padre di y con il padre di x */
    y->parent = x->parent;

    /* Se il padre di x è nullo */
    if(x->parent == nullptr)
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
    if(x->left != nullptr)
    {
        /* Aggiorniamo il padre del figlio sinistro di x precedentemente cambiato */
        x->left->parent = x;
    }
    /* Cambiamo il padre di y con il padre di x */
    y->parent = x->parent;

    /* Se il padre di x è nullo */
    if(x->parent == nullptr)
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

/* Inserimento di un nodo in un BST */
RBNode *RBTree::bst_insert_helper(RBNode *root, RBNode *node_to_add)
{
    /* Se l'albero è vuoto, allora il nuovo nodo inserito è la radice */
    if(root == nullptr)
    {
        return node_to_add;
    }

    /* 
    Altrimenti scorriamo in giu l'albero:
    - Se il valore del nodo da aggiungere è minore di quello della root ci rechiamo a sinsitra
    - Altrimenti a destra
    */
   if(node_to_add->key < root->key)
   {
       root->left = bst_insert_helper(root->left, node_to_add);
       root->left->parent = root;
   }
   else
   {
       root->right = bst_insert_helper(root->right, node_to_add);
       root->right->parent = root;
   }
   
   /* Ritorniamo la root */
   return root;
}  

/* Rispristino di un albero RB dalle violazioni causate dall'inserimento BST */
void RBTree::insert_fixup(RBNode *root, RBNode *x)
{
    /* 
    Il colore rosso viene assegnato durante la costruzione del nodo, pertanto qui 
    non abbiamo bisogno di colorare il nodo.

    Dichiariamo ora il nodo uncle(zio), il quale sarà utile durante l'iterazione.
    */
   RBNode *uncle = nullptr;

   /*
   Il processo verrà iterato dal basso verso l'alto, pertanto
   continuerà fintanto che il nodo è rosso e fintanto che la x non diventa la root 
   (ad fine iterazione la x analizzata diventerà il padre della vecchia x "parent[x]"). 
   */

  while((x != root) && (x->parent->color == RED))
  {
      if(x->parent == x->parent->parent->left)
      {
          /* Se il padre di x è il figlio sinistro del nonno di x*/
          /* Lo zio di x sarà il figlio destro del nonno di x */
          uncle = x->parent->parent->right;

          /* Caso 1: lo zio di x è rosso, allora abbiamo bisogno di ricolorare i nodi */
          if(uncle != nullptr && uncle->color == RED)
          {
              /* Coloriamo il padre di x e lo zio di x di nero */
              x->parent->color = BLACK;
              uncle->color = BLACK;
              /* Coloriamo il nonno di x di rosso */
              x->parent->parent->color = RED;

              /* Il nuovo x diventerà il padre di x */
              x = x->parent;
          }
          else
          {
            /* 
            Caso 2: lo zio di x è nero e x è figlio destro del padre 
            Sarà necessaria una rotazione sinistra per trasformare il caso 2 nel caso 3
            */
            if(x == x->parent->right)
            {
                /* Ruotiamo a sinistra x*/
                left_rotate(x);
                /* Il nuovo x diventerà il padre di x */
                x = x->parent;
            }

            /* 
            Caso 3: lo zio di x è nero e x è figlio sinistro del padre,
            in questo caso eseguiamo alcuni cambi di colore e eseguiamo una rotazioneverso
            destra
            */
            right_rotate(x->parent);
            x->parent->color = BLACK;
            x->parent->parent->color = RED;
            x = x->parent;
          }
      }
      else
      {
        /* Caso speculare */
        /* Lo zio di x sarà il figlio sinistro del nonno di x */
        uncle = x->parent->parent->left;

        /* Caso 1: lo zio di x è rosso, allora abbiamo bisogno di ricolorare i nodi */
        if(uncle != nullptr && uncle->color == RED)
        {
            /* Coloriamo il padre di x e lo zio di x di nero */
            x->parent->color = BLACK;
            uncle->color = BLACK;
            /* Coloriamo il nonno di x di rosso */
            x->parent->parent->color = RED;

            /* Il nuovo x diventerà il padre di x */
            x = x->parent;
        }
        else
        {
            /* 
            Caso 2: lo zio di x è nero e x è figlio sinistro del padre 
            Sarà necessaria una rotazione destra per trasformare il caso 2 nel caso 3
            */ 
            if(x == x->parent->left)
            {
                /* Ruotiamo a destra x*/
                right_rotate(x);
                /* Il nuovo x diventerà il padre di x */
                x = x->parent;
            }

            /* 
            Caso 3: lo zio di x è nero e x è figlio destro del padre,
            in questo caso eseguiamo alcuni cambi di colore e eseguiamo una rotazione verso
            sinsitra
            */
            left_rotate(x->parent);
            x->parent->color = BLACK;
            x->parent->parent->color = RED;
            x = x->parent;
        }
      }
  }
}

/* Inserimento di una chiave nell'albero RB */
void RBTree::insert(int key)
{
    /* Dichiamo e inizializziamo un nuovo nodo */
    RBNode *node_to_add = new RBNode(key);

    /* Lanciamo un insert BST */
    root = bst_insert_helper(root,node_to_add);

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
    if(root != nullptr)
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

/* Stampa dell'albero RB */;
void RBTree::print()
{
    if(root != nullptr)
    {
        print_helper(this->root, "", true);
    }
}