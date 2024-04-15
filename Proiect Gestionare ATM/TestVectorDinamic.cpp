//
// Created by camel on 4/3/2023.
//
#include <iostream>
#include <cassert>
#include "TestVectorDinamic.h"
using namespace std;

void TestVectorDinamic::test_constructor() {
    VectorDinamic v(3);
    try{
        VectorDinamic u(-3);
        //instructiuni neexecutate daca se arunca exceptia
        assert(false);
    }
    catch (std::invalid_argument ex) {
        assert(true);
    }

    //VectorDinamic v1(-3);

}

void TestVectorDinamic::test_size() {
    VectorDinamic v(10);
    assert(v.size() == 0);
    v.push_back(4);
    v.push_back(5);
    assert(v.size() == 2);
}

void TestVectorDinamic::test_push_back() {
    VectorDinamic v(3);
    v.push_back(4);
    v.push_back(5);
    assert(v.size() == 2);
}



void TestVectorDinamic::test_Get_At() {
    VectorDinamic v(10);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);;
    assert(v.getAt(2) == 6);

}

void TestVectorDinamic::test_addAt()  {
    VectorDinamic v(10);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(10);
    v.push_back(24);


    v.addAt(3, 666);
    assert(v.getAt(3) == 666);
}

void TestVectorDinamic::test_stergere() {
    VectorDinamic v(10);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(10);
    v.push_back(24);

    v.sterge(3);
    assert(v.getAt(3) == 24);
}

void TestVectorDinamic::test_update() {
    VectorDinamic v(10);
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);
    v.push_back(15);
    v.push_back(31);

    assert(v.getAt(4) == 31);

    v.update(4,111);
    assert(v.getAt(4) == 111);

}

void TestVectorDinamic::testAll(){
    test_constructor();
    test_size();
    test_push_back();
    test_Get_At();
    test_addAt();
    test_stergere();
    test_update();
}

