/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ArrayMaxHeap.h
 * Author: cwood
 *
 * Created on April 14, 2019, 6:50 PM
 */

#ifndef ARRAYMAXHEAP_H
#define ARRAYMAXHEAP_H

#include "HeapADT.h"

template <class T>
class ArrayMaxHeap : public HeapADT<T> {
public:
    ArrayMaxHeap();
    virtual ~ArrayMaxHeap();
    
    //interface methods
    bool isEmpty() const;
    int getItemCount() const;
    T peek() const;
    bool add(const T& newItem);
    bool remove();
    void clear();
    
private:
    static const int ROOT_INDEX = 0;
    static const int CAPACITY = 5000;
    int itemCount;
    T* items;
    
    int getLeftChild(int currNode) const;
    int getRightChild(int currNode) const;
    int getParent(int currNode) const;   
    bool isLeaf(int currNode) const;
    void percolateDown(int subtree);
};
#include "ArrayMaxHeap.cpp"
#endif /* ARRAYMAXHEAP_H */

