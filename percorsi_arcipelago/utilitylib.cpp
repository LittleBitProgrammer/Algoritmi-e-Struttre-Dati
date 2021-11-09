/**
 * @file utilitylib.cpp
 * @author Roberto Vecchio (roberto.vecchio001@uniparthenope.it)
 * @brief 
 * @version 1.0
 * @date 2021-11-09
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "utilitylib.h"

void swap(int& a, int& b)
{
    int temp{a};
    a = b;
    b = temp;
}