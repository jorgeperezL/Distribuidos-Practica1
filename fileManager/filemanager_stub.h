#pragma once 
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <map>
#include <vector>
#include <dirent.h>

#include "utils.h"


#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 65000


#define   OP_SALIR                 	  0
#define   OP_READFILE             	 10
#define   OP_WRITEFILE	          	 11
#define   OP_LISTFILES		  	 12


class filemanager_stub{

	private:
		std::string path;
    		//std::map<std::string, std::string* > files;
    		int serverID=-1;
	public:
		
		filemanager_stub();
		
		std::vector<std::string*>* listFiles();
		void readFile(char* fileName, char* &data, int &dataLength);
    		void writeFile(char* fileName, char* data, int dataLength);
    		void freeListedFiles(std::vector<std::string*>* fileList);
		
		~filemanager_stub();
	

};
