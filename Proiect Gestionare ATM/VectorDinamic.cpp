//
// Created by camel on 4/3/2023.
//
#include <iostream>
#include "VectorDinamic.h"
using namespace std;

VectorDinamic::VectorDinamic() {
}

VectorDinamic::VectorDinamic(int capacitate) {
    if(capacitate <= 0)
        throw std::invalid_argument("capacitatea trebuie sa fie un numar pozitiv");
    this->capacity = capacitate;
    this->elems = new TElem [capacitate];
    this->nrElems = 0;
}

int VectorDinamic::size() const {
    return this->nrElems;
}

TElem VectorDinamic::getAt(int i) const {
    if(i < 0 || i >= nrElems)
        throw std::invalid_argument("pozitie invalida");
    return this->elems[i];
}

void VectorDinamic::update(int i, TElem e) {
    //TODO - IMPLEMENT METHOD
    if(i < 0 || i>= nrElems)
        throw std::invalid_argument("pozitie invalida");
    this -> elems[i] = e;
}

void VectorDinamic::push_back(TElem e) {
    //TODO - IMPLEMENT METHOD
    if (nrElems == capacity)
        resize();
    this->elems[nrElems] = e;
    this->nrElems ++;
}

void VectorDinamic::addAt(int i, TElem e) {
    //TODO - IMPLEMENT METHOD
    if(i < 0 || i>= nrElems)
        throw std::invalid_argument("pozitie invalida");
    if(this->nrElems+1 > this->capacity) resize();
    this -> nrElems ++;
    int j;
    for(j=this->nrElems;j>i;--j) {
        this->elems[j] = this->elems[j - 1];
    }
        this->elems[i] = e;


}

TElem VectorDinamic::sterge(int i) {
    //TODO - IMPLEMENT METHOD
    if(i < 0 || i>= nrElems)
        throw std::invalid_argument("pozitie invalida");
    int j;
    for(j=i;j<this->nrElems;++j) {
        this->elems[j] = this->elems[j + 1];
    }
        this->nrElems--;
}

VectorDinamic::~VectorDinamic() {
    //TODO - IMPLEMENT METHOD
    delete[] this->elems;
    this->nrElems = 0;
    this->capacity = 0;
}

void VectorDinamic::resize() {
     this->capacity ++;
}

void VectorDinamic::Afiseaza() {
    int i;
    for(i=0;i<this->nrElems;++i) {
        cout << this->elems[i] << " ";
    }
}
