/**
 * @file main.cpp
 * @author Roberto Vecchio (roberto.vecchio001@uniparthenope.it)
 * @brief 
 * @version 0.1
 * @date 2021-11-09
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include "MaxHeap.h"

using std::cout;
using std::endl;

int main()
{
    /* Costruzione Heap */
    int capacity{10};
    int *my_array = new int[capacity] {4,1,3,2,16,9,10,14,8,7};
    MaxHeap max_heap{my_array,capacity, 10};

    /* Build heap */
    cout << "Il nostro array buildato con max heap e':" << endl;
    max_heap.print_array();

    /* Estrazione massimo */
    cout << "\nMAX estratto= " << max_heap.extractMax() << endl;
    cout << "Il nostro array con massimo estratto e':" << endl;
    max_heap.print_array();

    /* Recupero elemento massimo */
    cout << "\nMAX non estratto= " << max_heap.maximum() << endl;
    cout << "Il nostro array con massimo non estratto e':" << endl;
    max_heap.print_array();

    /* Inserimento chiave */
    cout << "\nInserita la chiave 16" << endl;
    cout << "In nostro array con la nuova chiave inseirta e':"<< endl;
    max_heap.insert_key(16);
    max_heap.print_array();

    /* Incremento di una chiave */
    cout << "\nIncrementiamo la chiave 3 a 17" << endl;
    cout << "Il nostro array con chiave incrementata e':" << endl;
    max_heap.increase_key(6,17);
    max_heap.print_array();

    /* Parent i */
    cout << "\nIl padre di 9 e' " << my_array[max_heap.parent(5)];

    /* Left i */
    cout << "\nIl left di 8 e' " << my_array[max_heap.left(4)];

    /* Right i */
    cout << "\nIl right di 4 e'" << my_array[max_heap.right(3)] << endl;

    /* Cancellazione di una chiave */
    cout << "\nCancelliamo la chiave 8" << endl;
    cout << "Il nostro array con la chiave cancellata e':" << endl;
    max_heap.delete_key(4);
    max_heap.print_array();

    /* Overloading operatore */
    cout << "\nInserita la chiave 8" << endl;
    cout << "In nostro array con la nuova chiave inseirta e':"<< endl;
    max_heap + 8;
    max_heap.print_array();

    return 0;
}