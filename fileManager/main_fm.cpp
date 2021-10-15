#include <iostream>
#include "filemanager_stub.h"

int main(int argc,char** argv)
{
    filemanager_stub* fm=new filemanager_stub();
    
   /* char* dataA=nullptr;
    int fileLenA=0;
    fm->readFile((char*)"prueba_1",dataA,fileLenA);
    
    return 0;*/
    
    
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
    std::cout<<"Liberando datos de fichero leído:\n";
    
    delete[] data;
    delete fm;
    return 0;
}
