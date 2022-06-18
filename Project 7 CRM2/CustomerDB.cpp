// CRM in C++ <CustomerDB.cpp>
// EE 312 Project 7 submission by
// Ayan Basu
// EID: ab73287
// Slip days used: <0>
// Fall 2021
#include <iostream>
#include <cassert>
#include "UTString.h"
#include "CustomerDB.h"

using namespace std;

const int default_capacity = 1;

Customer::Customer(UTString name) { // done, please do not edit
    this->bottles = 0;
    this->rattles = 0;
    this->diapers = 0;
    this->name = name;
}

CustomerDB::CustomerDB(void) { // done, please do not edit
    this->capacity = default_capacity;
    this->data = new Customer[this->capacity];
    this->length = 0;
}

int CustomerDB::size(void) { // done, please do not edit
    return this->length;
}

CustomerDB::~CustomerDB(void) { // done, please do not edit
    delete[] this->data;
}



void CustomerDB::clear(void) { // done, please do not edit
    delete[] this->data;
    this->capacity = default_capacity;
    this->data = new Customer[this->capacity];
    this->length = 0;
}

Customer& CustomerDB::operator[](int k) { // done, please do not edit
    assert(k >= 0 && k < this->length);
    return this->data[k];
}

Customer& CustomerDB::operator[](UTString name) {
    for (int i=0; i<length; i++)
    {
        if (data[i].name == name)
        {
            return data[i];
        }
    }
    if (capacity == length)
    {
        Customer *newData = new Customer[capacity * 2];
        for (int i = 0; i < length; i++)
        {
            newData[i] = data[i];
        }
        capacity *= 2;
        delete[] data;
        data = newData;
    }
    data[length] = Customer(name);
    length++;
    return data[length-1];
}

bool CustomerDB::isMember(UTString name) {
    for (int i = 0; i < length; i++)
    {
        if (name == data[i].name)
        {
            return true;
        }
    }
    return false;
}
