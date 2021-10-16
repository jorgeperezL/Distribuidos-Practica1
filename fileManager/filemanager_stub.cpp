#include "filemanager_stub.h"
#include <string>


filemanager_stub::filemanager_stub(/*std::string path*/){
	
	//this->path=path;
	char* ip = new char[strlen(SERVER_IP)+1];
	memcpy(ip,SERVER_IP,strlen(SERVER_IP)+1);
	
	serverID = initClient(ip,SERVER_PORT);
	
	delete ip;
	
	


}



filemanager_stub::~filemanager_stub(){

	int operacion= OP_SALIR;
	sendMSG(serverID, (void*)&operacion,sizeof(int));
	
	closeConnection(serverID);

}

void filemanager_stub::writeFile(char* fileName, char* data, int dataLength){

	int operacion = OP_WRITEFILE;
	
	sendMSG(serverID,(void*) &operacion,sizeof(int)); //tipo operacion
	sendMSG(serverID,(void*) fileName,strlen(fileName)+1); //enviar nombre
	
	sendMSG(serverID,(void*)data,dataLength);  //enviar datos
	
	
}





void filemanager_stub::readFile(char* fileName, char* &data, int &dataLength){
	
	//ya tenemos un puntero de data por parametro
	int operacion = OP_READFILE;
	
	sendMSG(serverID,(void*) &operacion,sizeof(int)); //tipo operacion
	sendMSG(serverID,(void*) fileName,strlen(fileName)+1); //enviar nombre
	
	recvMSG(serverID,(void**)&data,(int*)&dataLength);  //recibe datos
	

}


std::vector<std::string*>* filemanager_stub::listFiles() {

	int operacion  = OP_LISTFILES;
	int cantFicheros=0;
	int tamNombre=0;
	int dataLen = 0;
	char* nombre= nullptr;
	char* datosBuffer = nullptr;
	
	std::vector<std::string*>* list = new std::vector<std::string*>();
	
	sendMSG(serverID,(void*) &operacion, sizeof(int)); //tipo operacion
	recvMSG(serverID,(void**)&datosBuffer,&dataLen);   //recibe cantFicheros
	memcpy(&cantFicheros,datosBuffer, sizeof(int));
	delete datosBuffer;

	//TODO el cantFicheros, aca el error de punteros.
	std::cout<<"\nEl cant ficheros: "<<cantFicheros<<std::endl;
	
	for(int a=0;a<cantFicheros;a++) 
	{
		recvMSG(serverID,(void**)&nombre,&tamNombre);  //recibe nombre fichero
		list->push_back(new std::string(nombre));
	}
	
	delete[] nombre;
	return list;
}


void filemanager_stub::freeListedFiles(std::vector<std::string*>* fileList){

	for(std::vector<std::string*>::iterator i=fileList->begin();i!= fileList->end();++i)
	{
        	delete *i;
	}
    	delete fileList;


}
