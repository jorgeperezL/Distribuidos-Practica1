#pragma once

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "utils.h"


#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 65000

#define OP_SALIR 				0

#define OP_READMATRIX  				10
#define OP_MULTMATRICES			11
#define OP_WRITEMATRIX  			12
#define OP_CREATEIDENTITY  	13
#define OP_CREATERANDMATRIX  	14

typedef struct matrix_t
{
    int rows;
    int cols;
    int* data;
}matrix_t;

class multmatrix_stub
{
private:
	int serverID=-1;

public:
	multmatrix_stub();
    	matrix_t* readMatrix(const char* fileName);
    	matrix_t *multMatrices(matrix_t* m1, matrix_t *m2);
    	void writeMatrix(matrix_t* m, const char *fileName);
    	matrix_t *createIdentity(int rows, int cols);
    	matrix_t *createRandMatrix(int rows, int cols);
    	~multmatrix_stub();
};
