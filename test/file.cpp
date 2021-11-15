
/** C++ implementation for
   Red-Black Tree Insertion
   This code is adopted from
   the code provided by
   Dinesh Khandelwal in comments **/
#include <iostream>
#include <queue>
using namespace std;
 
enum Color {RED, BLACK};
 
struct Node
{
    int data;
    bool color;
    Node *left, *right, *parent;
 
    // Constructor
    Node(int data)
    {
       this->data = data;
       left = right = parent = NULL;
       this->color = RED;
    }
};
 
// Class to represent Red-Black Tree
class RBTree
{
private:
    Node *root;
protected:
    void rotateLeft(Node *&, Node *&);
    void rotateRight(Node *&, Node *&);
    void fixViolation(Node *&, Node *&);
public:
    // Constructor
    RBTree() { root = NULL; }
    void insert(const int &n);
    void inorder();
    void levelOrder();
    void print();
    void print_helper(Node *root, string idnentation, bool last);
};
 
// A recursive function to do inorder traversal
void inorderHelper(Node *root)
{
    if (root == NULL)
        return;
 
    inorderHelper(root->left);
    cout << root->data << "  ";
    inorderHelper(root->right);
}
 
/* A utility function to insert
    a new node with given key
   in BST */
Node* BSTInsert(Node* root, Node *pt)
{
    /* If the tree is empty, return a new node */
    if (root == NULL)
       return pt;
 
    /* Otherwise, recur down the tree */
    if (pt->data < root->data)
    {
        root->left  = BSTInsert(root->left, pt);
        root->left->parent = root;
    }
    else if (pt->data > root->data)
    {
        root->right = BSTInsert(root->right, pt);
        root->right->parent = root;
    }
 
    /* return the (unchanged) node pointer */
    return root;
}
 
// Utility function to do level order traversal
void levelOrderHelper(Node *root)
{
    if (root == NULL)
        return;
 
    std::queue<Node *> q;
    q.push(root);
 
    while (!q.empty())
    {
        Node *temp = q.front();
        cout << temp->data << "  ";
        q.pop();
 
        if (temp->left != NULL)
            q.push(temp->left);
 
        if (temp->right != NULL)
            q.push(temp->right);
    }
}
 
void RBTree::rotateLeft(Node *&root, Node *&pt)
{
    Node *pt_right = pt->right;
 
    pt->right = pt_right->left;
 
    if (pt->right != NULL)
        pt->right->parent = pt;
 
    pt_right->parent = pt->parent;
 
    if (pt->parent == NULL)
        root = pt_right;
 
    else if (pt == pt->parent->left)
        pt->parent->left = pt_right;
 
    else
        pt->parent->right = pt_right;
 
    pt_right->left = pt;
    pt->parent = pt_right;
}
 
void RBTree::rotateRight(Node *&root, Node *&pt)
{
    Node *pt_left = pt->left;
 
    pt->left = pt_left->right;
 
    if (pt->left != NULL)
        pt->left->parent = pt;
 
    pt_left->parent = pt->parent;
 
    if (pt->parent == NULL)
        root = pt_left;
 
    else if (pt == pt->parent->left)
        pt->parent->left = pt_left;
 
    else
        pt->parent->right = pt_left;
 
    pt_left->right = pt;
    pt->parent = pt_left;
}
 
// This function fixes violations
// caused by BST insertion
void RBTree::fixViolation(Node *&root, Node *&x)
{
    /* 
    Il colore rosso viene assegnato durante la costruzione del nodo, pertanto qui 
    non abbiamo bisogno di colorare il nodo.

    Dichiariamo ora il nodo uncle(zio), il quale sarà utile durante l'iterazione.
    */
    Node *uncle = nullptr;

    /* Dichiariamo il nodo parent(padre) e grand parent(nonno) utili durante l'iterazione */
    Node *parent = nullptr;
    Node *grand_parent = nullptr;

    /*
    Il processo verrà iterato dal basso verso l'alto, pertanto
    continuerà fintanto che il nodo è rosso e fintanto che la x non diventa la root 
    (ad fine iterazione la x analizzata diventerà il padre della vecchia x "parent[x]"). 
    */

    while((x != root) && (x->color != BLACK) && (x->parent->color == RED))
    {
        /* Inizializziamo il parent ed il grand_parent del nodo */
        parent = x->parent;
        grand_parent = x->parent->parent;

        if(parent == grand_parent->left)
        {
            /* Se il padre di x è il figlio sinistro del nonno di x*/
            /* Lo zio di x sarà il figlio destro del nonno di x */
            uncle = grand_parent->right;

            /* Caso 1: lo zio di x è rosso, allora abbiamo bisogno di ricolorare i nodi */
            if((uncle != nullptr) && (uncle->color == RED))
            {
                /* Coloriamo il nonno di x di rosso */
                grand_parent->color = RED;

                /* Coloriamo il padre di x e lo zio di x di nero */
                parent->color = BLACK;
                uncle->color = BLACK;

                /* Il nuovo x diventerà il nonno di x */
                x = grand_parent;
            }
            else
            {
                /* 
                Caso 2: lo zio di x è nero e x è figlio destro del padre 
                Sarà necessaria una rotazione sinistra per trasformare il caso 2 nel caso 3
                */
                if(x == parent->right)
                {
                    /* Ruotiamo a sinistra x*/
                    rotateLeft(root, parent);
                    /* Il nuovo x diventerà il padre di x */
                    x = parent;
                    parent = x->parent;
                }

                /* 
                Caso 3: lo zio di x è nero e x è figlio sinistro del padre,
                in questo caso eseguiamo alcuni cambi di colore e eseguiamo una rotazioneverso
                destra
                */
                rotateRight(root,grand_parent);
                std::swap(parent->color, grand_parent->color);
                x = parent;
            }
        }
        else
        {
            /* Caso speculare */
            /* Lo zio di x sarà il figlio sinistro del nonno di x */
            uncle = grand_parent->left;

            /* Caso 1: lo zio di x è rosso, allora abbiamo bisogno di ricolorare i nodi */
            if((uncle != nullptr) && (uncle->color == RED))
            {
                /* Coloriamo il nonno di x di rosso */
                grand_parent->color = RED;

                /* Coloriamo il padre di x e lo zio di x di nero */
                parent->color = BLACK;
                uncle->color = BLACK;

                /* Il nuovo x diventerà il padre di x */
                x = grand_parent;
            }
            else
            {
                /* 
                Caso 2: lo zio di x è nero e x è figlio sinistro del padre 
                Sarà necessaria una rotazione destra per trasformare il caso 2 nel caso 3
                */ 
                if(x == parent->left)
                {
                    /* Ruotiamo a destra x*/
                    rotateRight(root,parent);
                    /* Il nuovo x diventerà il padre di x */
                    x = parent;
                    parent = x->parent;
                }

                /* 
                Caso 3: lo zio di x è nero e x è figlio destro del padre,
                in questo caso eseguiamo alcuni cambi di colore e eseguiamo una rotazione verso
                sinsitra
                */
                rotateLeft(root,grand_parent);
                std::swap(parent->color,grand_parent->color);
                x = parent;
            }
        }
    }

    root->color = BLACK;
}
 
// Function to insert a new node with given data
void RBTree::insert(const int &data)
{
    Node *pt = new Node(data);
 
    // Do a normal BST insert
    root = BSTInsert(root, pt);
 
    // fix Red Black Tree violations
    fixViolation(root, pt);
}
 
// Function to do inorder and level order traversals
void RBTree::inorder()     {  inorderHelper(root);}
void RBTree::levelOrder()  {  levelOrderHelper(root); }

/* Metodo di supporto utilizzato dalla print */
void RBTree::print_helper(Node *root, string indentation, bool last)
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
        cout << root->data << "(" << node_color << ")" << endl;

        print_helper(root->left, indentation, false);
        print_helper(root->right, indentation, true);
    }
}

void RBTree::print()
{
    if(root != nullptr)
    {
        print_helper(this->root, "", true);
    }
}
 
// Driver Code
int main()
{
    RBTree rb;
 
    rb.insert(8);
    rb.insert(18);
    rb.insert(5);
    rb.insert(15);
    rb.insert(17);
    rb.insert(25);
    rb.insert(40);
    rb.insert(3);
    rb.insert(1);
    rb.insert(80);
 

    rb.print();
 
    return 0;
}