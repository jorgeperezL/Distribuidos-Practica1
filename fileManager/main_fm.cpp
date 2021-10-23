#include <iostream>
#include "filemanager_stub.h"
#include <stdio.h>

int main(int argc,char** argv)
{
    filemanager_stub* fm=new filemanager_stub();
    
    std::vector<std::string*>* vfiles=fm->listFiles();
    
    std::cout<<"Lista de ficheros en el directorio de prueba:\n"<<std::endl;
    
    for(unsigned int i=0;i<vfiles->size();++i)
    {
        std::cout<<"Fichero: "<<vfiles->at(i)->c_str()<<std::endl;
    }
    

    char* data=nullptr;
    int fileLen=0;
    
    for(unsigned int i=0;i<vfiles->size();++i){
    	    std::cout<<"Leyendo el primer fichero del directorio de prueba:"<<std::endl;
	    fm->readFile(&(*(vfiles->at(i)))[0],data,fileLen);
	    std::cout<<"Escribiendo el primer fichero del directorio de prueba:\n"<<std::endl;
	    fm->writeFile(&(*(vfiles->at(i)))[0],data,fileLen);
	   
    }
    
    
    std::cout<<"Liberando lista de ficheros:\n";
    fm->freeListedFiles(vfiles);
    std::cout<<"Liberando datos de fichero leído:\n\n";
	
	
	    
    delete[] data;
    delete fm;
    return 0;
}

	
	
	
	
	
	
	
	
	
	
	
	
/* 	
	


int main(int argc,char** argv)
{

    filemanager_stub* fm=new filemanager_stub();
    
    bool salir = false;
    int opcion;
    
    FILE* f;
    
    char* data=nullptr;
    int fileLen=0;
    
    std::vector<std::string*>* vfiles;
    
    std::string fileName = "";
    char* fileNameChar=nullptr;
    
    std::cout<<"1.ls, 2.download, 3.upload";
    
    do{
            switch(opcion) {
                case 1: //ls          	
                	 vfiles=fm->listFiles();
                	
                    	 for(unsigned int i=0;i<vfiles->size();++i){
        			std::cout<<" "<<vfiles->at(i)->c_str()<<std::endl;
        		 }
        		 fm->freeListedFiles(vfiles);
                  
                break;
                case 2: //download
                
                  std::cout<<"Que fichero quiere descargar";
                  std::cin>>fileName;  
              		
                  fileName = fileName + ".txt";
                  
                  vfiles=fm->listFiles();
                  fileLen=-1;
                	
                  for(unsigned int i=0;i<vfiles->size();++i){
                  
        		if(vfiles->at(i)->compare(fileName)==0){
        		
        			fileNameChar= new char[fileName.size() + 1];
				memcpy(fileNameChar, fileName.c_str(), fileName.size() + 1);
				
        			fm->readFile(fileNameChar,data,fileLen);
                  		f = std::fopen(fileName.c_str(),"w");
		   		std::fwrite(data,fileLen,1,f);
		   		
		   		delete fileNameChar;
		   		break;
        		}
        	   }
        	   
        	   if(fileLen ==-1){
        	   	std::cout<<"no se ha podido descargar";
        	   }
        	   
        	   fm->freeListedFiles(vfiles);
                  
                
                
                break;
                
                case 3: //upload
                
                  std::cout<<"Que fichero quiere descargar";
                  std::cin>>fileName;
              
                  fileName = fileName + ".txt"; 
                  
                	
                  f = std::fopen(fileName.c_str(),"r");
                  
                  if(f==NULL) {
  			std::cout<<"Error al leer el fichero."<<std::endl;
  			break;
		   }
		   fileNameChar= new char[fileName.size() + 1];
		   memcpy(fileNameChar, fileName.c_str(), fileName.size() + 1);
		   
		   std::fread(data,fileLen,1,f);
		   fm->writeFile(fileNameChar,data,fileLen);
                  delete fileNameChar;
                  break;
             
                
            }
        }while(!salir);
        
        
    std::cout<<"Liberando lista de ficheros:\n";
    fm->freeListedFiles(vfiles);
    std::cout<<"Liberando datos de fichero leído:\n\n";
	
	
	    
    delete[] data;
    delete fm;
    return 0;
        
}
*/
        

    
