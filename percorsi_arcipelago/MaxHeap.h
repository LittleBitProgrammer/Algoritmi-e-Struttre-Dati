/**
 * @file MaxHeap.h
 * @author Roberto Vecchio (roberto.vecchio001@uniparthenope.it)
 * @brief 
 * @version 1.0
 * @date 2021-11-09
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef _MAX_HEAP_H_
#define _MAX_HEAP_H_

class MaxHeap
{
    private:
        int *arr; // Puntatore ad array di elementi nell'heap
        int capacity; // Massima grandezza possibile del MaxHeap
        int heapsize; // Numero di elementi nel max_heap
    
        // Algoritmi di sostegno che servono per il normale funzionamento di un maxheap
        void max_heapify(int root, int size);
        void build_max_heap();
    public:
        // Constructor
        MaxHeap(int capacity);
        MaxHeap(int *arr, int capacity, int heapsize);

        // Padre del nodo i
        int parent(int i);

        // Figlio sinistro del nodo i
        int left(int i);

        // Figlio destro del nodo i
        int right(int i);

        // Estrazione del massimo con complessità -> 1
        int extractMax();

        // Ritorna l'elemento con chiave massima
        int maximum();

        // Maggiora la chiave del nodo i con un valore strettamente maggiore di quello attuale
        void increase_key(int i, int greater_value);

        // Elimina la chiave memorizzata nel nodo all'indice i-esimo
        void delete_key(int i);

        // Inserisce una nuova chiave dal valore k
        void insert_key(int k);

        // Stampa array
        void print_array();

        // Implementazione Heap sort
        void heap_sort();

        // Operator overloading
        void operator+(int key);
};

#endif