#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "multmatrix_stub.h"
#include "utils.h"



char * remoto_ruta(){
    int numero;
    FileManager *fm=new FileManager("./dirprueba_remoto/");
    vector<string*>* vfiles=fm->listFiles();
    cout<<"Lista de ficheros en el directorio de prueba:\n";
    for(unsigned int i=0;i<vfiles->size();++i)
    {
    cout<<i<<"-"<<"Fichero: "<<vfiles->at(i)->c_str()<<endl;
    }
    cout << "Elegir numero fichero: " << endl;
    cin >> numero;
    
    const char * directorio = "./dirprueba_remoto/";
    
    char * ruta = (char*)malloc(strlen(directorio)+strlen(&(*(vfiles->at(numero)))[numero])+2);
    strcpy(ruta,directorio);
    strcat(ruta,&(*(vfiles->at(numero)))[numero]);
    
    return ruta;
    	
}

char * local_ruta(){
    int numero;
    FileManager *fm=new FileManager("./dirprueba_local/");
    vector<string*>* vfiles=fm->listFiles();
    cout<<"Lista de ficheros en el directorio de prueba:\n";
    for(unsigned int i=0;i<vfiles->size();++i)
    {
    cout<<i<<"-"<<"Fichero: "<<vfiles->at(i)->c_str()<<endl;
    }
    cout << "Elegir numero fichero: " << endl;
    cin >> numero;
    
    const char * directorio = "./dirprueba_remoto/";
    
    char * ruta = (char*)malloc(strlen(directorio)+strlen(&(*(vfiles->at(numero)))[numero])+2);
    strcpy(ruta,directorio);
    strcat(ruta,&(*(vfiles->at(numero)))[numero]);
    
    return ruta;
}


void freeMatrix(matrix_t* m){
    delete[] m->data;
    delete[] m;

}

void local(multmatrix_stub * mmatrix_stub,multMatrix * mmatrix){

	matrix_t *m1= mmatrix_stub->createRandMatrix(5,5);
    	matrix_t *m2= mmatrix_stub->createIdentity(5,5);
    	matrix_t *mres=mmatrix_stub->multMatrices(m1,m2);
    	mmatrix->writeMatrix(mres,"./dirprueba_remoto/resultado.txt");
    	matrix_t *m3=mmatrix->readMatrix("./dirprueba_remoto/resultado.txt");
    	matrix_t *mres2=mmatrix_stub->multMatrices(m1,m3);
    	mmatrix->writeMatrix(mres2,"./dirprueba_remoto/resultado2.txt");
    	
    	freeMatrix(m1);
    	freeMatrix(m2);
    	freeMatrix(mres);
    	freeMatrix(m3);
    	freeMatrix(mres2);
}


void remoto(multmatrix_stub * mmatrix_stub){

	matrix_t *m1= mmatrix_stub->createRandMatrix(5,5);
    	matrix_t *m2= mmatrix_stub->createIdentity(5,5);
    	matrix_t *mres=mmatrix_stub->multMatrices(m1,m2);
    	mmatrix_stub->writeMatrix(mres,"./dirprueba_local/resultado.txt");
    	matrix_t *m3=mmatrix_stub->readMatrix("./dirprueba_local/resultado.txt");
    	matrix_t *mres2=mmatrix_stub->multMatrices(m1,m3);
    	mmatrix_stub->writeMatrix(mres2,"./dirprueba_local/resultado2.txt");
    	
    	freeMatrix(m1);
    	freeMatrix(m2);
    	freeMatrix(mres);
    	freeMatrix(m3);
    	freeMatrix(mres2);
}

int main()
{
    multmatrix_stub * mmatrix_stub =new multmatrix_stub();
    multMatrix * mmatrix = new multMatrix();
     
    int seleccion = 0;
    cout << "1-Local"<<endl;
    cout << "2-Remoto"<<endl;
    scanf("%d", &seleccion);  	
    switch (seleccion){
    	case 1: 
    		local(mmatrix_stub,mmatrix); 
    	case 2:
    		remoto(mmatrix_stub);	
	}

    
    delete mmatrix_stub;
    delete mmatrix;

}
