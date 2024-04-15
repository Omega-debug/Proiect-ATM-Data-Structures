//
// Created by Mihnea Marinescu on 26.04.2023.
//

#include "Colectie.h"

#include<iostream>
using namespace std;

Collection::Collection() {


    values = VectorDinamic(5);
    values.push_back(10);
    values.push_back(50);
    values.push_back(100);
    exemplare = VectorDinamic(5);
    exemplare.push_back(100);
    exemplare.push_back(45);
    exemplare.push_back(50);
    distincteValues = 3;
    capacity = 5;
}

void Collection::afis(){
    for(int i=0;i<distincteValues; ++i){
        cout << "Bancnota " << values.getAt(i) << "are un numar de exemplare: " << exemplare.getAt(i) << endl;
    }
}

void Collection::add(int bancnota)
{
    bool exist = false;
    int poz;
    for(int i=0;i<distincteValues;i++)
    {
        if(bancnota==values.getAt(i))
        {
            exist = true;
            poz=i;
        }
    }
    if(exist)
    {
        int valoare = exemplare.getAt(poz);
        exemplare.update(poz,valoare+1);
    }
    else
    {
        values.push_back(bancnota);
        //values.update(distincteValues,bancnota);
        //values[distincteValues]=bancnota;
        exemplare.push_back(1);
        //exemplare.update(distincteValues,1);
        //[distincteValues]=1;
        distincteValues++;

    }
}

bool Collection::search(int bancnota)
{
    for(int i=0;i<distincteValues;i++)
    {
        if (bancnota==values.getAt(i))
        {
            return true;
        }
    }
    return false;
}

int Collection::size()
{
    return distincteValues;
}

int Collection::nroccurrences(int banknote)
{
    for(int i=0;i<distincteValues;i++)
    {
        if(banknote==values.getAt(i))
        {
            return exemplare.getAt(i);
        }
    }
    return 0;
}

void Collection::destroy()

{
    values.~VectorDinamic();
    exemplare.~VectorDinamic();
    distincteValues=1;
}

TypeBanknote Collection::getAt(int poz)
{
    return values.getAt(poz);
}

bool Collection::remove(int bancnota)
{
    bool exist = false;
    int poz;
    for(int i=0;i<distincteValues;i++)
    {
        if(bancnota == values.getAt(i))
        {
            exist = true;
            poz=i;
        }
    }
    if(exist)
    {
        if(exemplare.getAt(poz)>1)
        {
            int c = exemplare.getAt(poz);
            exemplare.update(poz,c-1);
        }
        else
        {
            for(int i=poz;i<distincteValues;i++)
            {
                int k = values.getAt(i+1);
                values.update(i,k);
                //values[i]=values[i+1];
                int a = exemplare.getAt(i+1);
                exemplare.update(i,a);
                //[i]=this->exemplare[i+1];

            }
            distincteValues--;
        }
        return true;
    }
    return false;
}


