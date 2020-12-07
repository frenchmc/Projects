/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/** 
 * @file:   HeapADT.h
 * @author: cwood
 * @class:  HeapADT
 *
 * Created on April 14, 2019, 6:48 PM
 */

#ifndef HEAPADT_H
#define HEAPADT_H

template <class T>
class HeapADT {
    public:
        virtual bool isEmpty() const = 0;
        virtual int getItemCount() const = 0;
        virtual T peek() const = 0;
        virtual bool add(const T& newItem) = 0;
        virtual bool remove() = 0;
        virtual void clear() = 0;
};

#endif /* HEAPADT_H */

