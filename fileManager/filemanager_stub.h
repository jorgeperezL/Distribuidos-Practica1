#pragma once 
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "utils.h"


#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 65000


#define   OP_SALIR                 	  0
#define   OP_READFILE             	 10
#define   OP_WRITEFILE	          	 11
#define   OP_FREELIST		  	 12
#define 

class filemanager_stub{

	private:
		
	public:
		filemanager_stub();
		
		filemanager_stub(string path);
		
		vector<string*>* listFiles();
		void readFile(char* fileName, char* &data, unsigned long int & dataLength);
    		void writeFile(char* fileName, char* data, unsigned long int dataLength);
    		void freeListedFiles(vector<string*>* fileList);
		
		~filemanager_stub();
	

}
