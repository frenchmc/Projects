/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/** 
 * @file:   HeapException.cpp
 * @author: cwood
 * @class:  HeapException
 * 
 * Created on April 14, 2019, 7:01 PM
 */

#include "HeapException.h"

HeapException::HeapException(const string& msg)
    : logic_error("Heap Exception: " + msg) {
}

