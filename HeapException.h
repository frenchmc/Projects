/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   HeapException.h
 * Author: cwood
 *
 * Created on April 14, 2019, 7:01 PM
 */

#ifndef HEAPEXCEPTION_H
#define HEAPEXCEPTION_H

#include <stdexcept>
#include <string>
using namespace std;

class HeapException : public logic_error {
public:
    HeapException(const string& msg = "");
};

#endif /* HEAPEXCEPTION_H */

