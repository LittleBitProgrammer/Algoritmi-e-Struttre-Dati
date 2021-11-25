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
    RBNode *join_left(RBNode *left_tree, int k, RBNode *right_tree);
    /* Metodo di supporto alla join, utile ad eseguire un merge verso sinistra dell'albero destro */
    RBNode *join_right(RBNode *left_tree, int k, RBNode *right_tree);
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
   pair<pair<RBNode *,RBNode *>,int> split(RBNode *tree, int key);
   /* Metodo di supporto alla join 2 */
   pair<RBNode *,int>split_last(RBNode *tree);
   /* 
   Metodo di supporto a diverse operazioni di insiemistica:
   - union 
   - intersect
   - difference
   */
  RBNode *join2(RBNode *left_tree, RBNode *right_tree);
  /* Metodo helper per l'operazione di unione */
  RBNode *union_helper(RBNode *set1, RBNode *set2);
  /* Metodo helper per l'operazione di intersezione */

  /* Metodo helper per l'operazione di unione */
  RBNode *difference_helper(RBNode *tree1, RBNode *tree2);

public:
    /* Methods */

    /* Operazione di unione tra due insiemi */
    NumSet *set_union(NumSet *set1, NumSet *set2);
    /* Operazione di intersezione tra due insiemi */
    NumSet *set_intersection(NumSet *set2);
    /* Operazione di differenza tra insieme attuale e set2 */
    NumSet *set_difference(NumSet *set2);

    RBNode *intersection_helper(RBNode *tree1, RBNode *tree2);
};


#endif