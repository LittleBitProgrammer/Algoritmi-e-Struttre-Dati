/**
 * @file MaxHeap.cpp
 * @author Roberto Vecchio (roberto.vecchio001@uniparthenope.it)
 * @brief 
 * @version 1.0
 * @date 2021-11-09
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include "MaxHeap.h"
#include "utilitylib.h"

// Costruttori
MaxHeap::MaxHeap(int *arr, int capacity, int heapsize):arr{arr},capacity{capacity},heapsize{heapsize}
{
    build_max_heap();
}

MaxHeap::MaxHeap(int capacity):MaxHeap{new int[capacity], capacity, 0}{}

// Metodi
int MaxHeap::parent(int i)
{
    return (i-1)/2;
}

int MaxHeap::left(int i)
{
    return (2 * i + 1);
}

int MaxHeap::right(int i)
{
    return (2 * i + 2);
}

int MaxHeap::extractMax()
{
    using std::runtime_error;

    // Se la struttura dati è vuota lancia l'errore
    if(heapsize <= 0)
    {
        throw runtime_error("Heap Underflow");
    }
    
    // Memorizziamo l'elemento in cima all'heap in una variabile
    int root{arr[0]};
    // Scambiamo il primo elemento con l'ultimo nell'heap
    arr[0] = arr[heapsize - 1];
    // Decrementiamo l'heap in modo che l'ultimo elemento non venga considerato più
    heapsize--;

    // Lanciamo un max_heapify in modo da rispettare le regole dell'heap
    max_heapify(0,heapsize);

    return root;
}

void MaxHeap::max_heapify(int root, int size)
{
    // Dichiariamo il massimo come l'indice passato in input
    int max = root;

    // Otteniamo l'indice del figlio sinistro e destro di index
    int left = (2 * root) + 1;
    int right = (2 * root) + 2;

    // Caso in cui il figlio sinistro sia maggiore della root
    if(arr[left] > arr[max] && left < size)
    {
        max = left;
    }

    // Caso in cui il figlio destro sia maggiore della root
    if(arr[right] > arr[max] && right < size)
    {
        max = right;
    }

    // Nel caso in cui la root non sia maggiore
    if(max != root)
    {
        swap(arr[root], arr[max]);

        // Richiama ricorsivamente nel sottoalbero
        max_heapify(max,size);
    }
}

int MaxHeap::maximum()
{
    return arr[0];
}

void MaxHeap::increase_key(int i, int greater_value)
{
    using std::invalid_argument;

    if(greater_value <= arr[i])
    {
        throw invalid_argument("Wrong argument, enter a value greater than key at index i");
    }

    // Assegnamo il nuovo valore al nodo in posizione i-esima
    arr[i] = greater_value;

    // Controlliamo se le proprietà dell'heap sono rispettate
    while(i != 0 && arr[parent(i)] < arr[i])
    {
        swap(arr[i],arr[parent(i)]);
        i = parent(i);
    }
}

void MaxHeap::delete_key(int i)
{
    increase_key(i,INT16_MAX);
    extractMax();
}

void MaxHeap::insert_key(int k)
{
    using std::runtime_error;

    if(heapsize == capacity)
    {
        throw runtime_error("Overflow heap error: could not insert key");
    }

    // Inseriamo un nuovo nodo alla fine
    heapsize++;
    int i = heapsize - 1;
    arr[i] = INT_MIN;

    increase_key(i,k);
}

void MaxHeap::build_max_heap()
{
    // Nel Max heapify non vengono prese in considerazione le foglie
    // Per cui iniziamo da size/2, ovvero il primo nodo non foglia disponibile
    for(auto i{(heapsize/2)-1}; i >= 0; i--)
    {
        max_heapify(i,heapsize);
    }
}

void MaxHeap::print_array()
{
    using std::cout;
    using std::endl;

    for(auto i{0}; i < heapsize; i++)
    {
        cout << "| " << arr[i] << " ";
    }

    cout << "|" << endl;
}

void MaxHeap::operator+(int key)
{
    insert_key(key);
}

void MaxHeap::heap_sort()
{
    build_max_heap();

    // Estrazione degli elementi dall'heap uno ad uno 
    for(auto i{heapsize - 1}; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        
        // Chiamiamo heapify con heap ridotto
        max_heapify(0,i);
    }
}