#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "multmatrix_stub.h"
#include "utils.h"



void freeMatrix(matrix_t* m){
    delete[] m->data;
    delete[] m;

}
int main()
{
    multmatrix_stub * mult=new multmatrix_stub();


    matrix_t* m1= mult->createRandMatrix(5,5);
    matrix_t* m2= mult->createIdentity(5,5);
    matrix_t* mres=mult->multMatrices(m1,m2);
    mult->writeMatrix(mres,"resultado.txt");
    matrix_t* m3=mult->readMatrix("resultado.txt");
    matrix_t* mres2=mult->multMatrices(m1,m3);
    mult->writeMatrix(mres2,"resultado2.txt");



    freeMatrix(m1);
    freeMatrix(m2);
    freeMatrix(mres);
    freeMatrix(m3);
    freeMatrix(mres2);
    delete mult;

}
