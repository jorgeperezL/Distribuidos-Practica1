#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "filemanager_stub.h"

using namespace std;

int main(int argc, char** argv){

	
	filemanager_stub* fm = new filemanager_stub("./dirprueba/");
	
	
	vector<string*>* vfiles=fm->listFiles();
    	
    	cout<<"Lista de ficheros en el directorio de prueba:\n";
    
    	for(unsigned int i=0;i<vfiles->size();++i)
    	{
        	cout<<"Fichero: "<<vfiles->at(i)->c_str()<<endl;
    	}
   	cout<<"Leyendo el primer fichero del directorio de prueba:\n";
    
	int opcion = 0;
	
	
	char* data=nullptr;
    	unsigned long int fileLen=0;
    	
    	cout<<"eliga 1 para leer fichero, eliga 2 para escribir: ";
    	cin>>opcion;
    	
    	int cont = 0;
    	
    	while(cont<=i){ //repetimos el switch hasta que no haya mas ficheros
    	
		switch(opcion){
		
			case 1:
				fm->readFile(&(*(vfiles->at(0)))[0],data,fileLen);
	    			cout<<"Escribiendo el primer fichero del directorio de prueba:\n";
				break;
			case 2:
				fm->writeFile(&(*(vfiles->at(0)))[0],data,fileLen);
	    			cout<<"Liberando lista de ficheros:\n";
				break;
					
			default:
				cout<<"escriba un paramentro correcto";
				
		
		}
		cont ++;
	}
	
    	
    	
    	//liberamos memoria de fichero
    	fm->freeListedFiles(vfiles);
    	cout<<"Liberando datos de fichero leído:\n";

    	delete[] data;
    	return 0;
	
	
	//se tiene que crear ficheros antes de ejercutar un programa o se crean ficheros durante el programa

}
