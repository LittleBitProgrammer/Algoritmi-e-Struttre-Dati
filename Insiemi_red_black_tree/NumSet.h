#ifndef _NUM_SET_H_
#define _NUM_SET_H_

#include <utility> /* Pair*/
using std::pair;

#include "RBTree.h" /* Rappresentazione di un Albero RB */

class NumSet:public RBTree
{
private:
    /* Methods */

    /* Metodo di supporto alla join, utile ad eseguire un merge verso destra dell'albero sinistro */
    RBNode *join_right(RBNode *left_tree, int k, RBNode *right_tree);
    /* Metodo di supporto alla join, utile ad eseguire un merge verso sinistra dell'albero destro */
    RBNode *join_left(RBNode *left_tree, int k, RBNode *right_tree);
    /* 
    Metodo di supporto a diverse operazioni di insiemistica:
    - split
    - split_last
    - join2
    - union
    - intersect
    */
    RBNode *join(RBNode *left_tree, int k, RBNode *right_tree);
   /*
   Metodo di supporto a diverse operazioni di insiemistica:
   - union
   - intersect
   - difference
   */

   /* Metodo di supporto alla join 2 */
   pair<RBTree *,int>split_last(RBTree *tree);
   /* 
   Metodo di supporto a diverse operazioni di insiemistica:
   - union 
   - intersect
   - difference
   */
  pair<RBTree *,int> join2(RBTree *left_tree, RBTree *right_tree);
  /* Metodo helper per l'operazione di unione */
  RBTree *union_helper(RBTree *tree1, RBTree *tree2);
  /* Metodo helper per l'operazione di intersezione */
  RBTree *intersection_helper(RBTree *tree1, RBTree *tree2);
  /* Metodo helper per l'operazione di unione */
  RBTree *difference_helper(RBTree *tree1, RBTree *tree2);

public:
    /* Methods */

    /* Operazione di unione tra due insiemi */
    NumSet *set_union(NumSet *set2);
    /* Operazione di intersezione tra due insiemi */
    NumSet *set_intersection(NumSet *set2);
    /* Operazione di differenza tra insieme attuale e set2 */
    NumSet *set_difference(NumSet *set2);

    /* Getter */
    RBTree *get_rbtree();

    /* Setter */
    //TODO: passare split nella private
    pair<pair<RBNode *,RBNode *>,int> split(RBNode *tree, int key);
    
};


#endif