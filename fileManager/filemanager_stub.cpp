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
	sendMSG(serverID,(void*) fileName,sizeof(int)); //enviar nombre
	
	recvMSG(serverID,(void**)&data,&dataLength);  //recibe datos
	
	
}





void filemanager_stub::readFile(char* fileName, char* &data, int &dataLength){
	
	//ya tenemos un puntero de data por parametro
	int operacion = OP_READFILE;
	
	sendMSG(serverID,(void*) &operacion,sizeof(int)); //tipo operacion
	sendMSG(serverID,(void*) fileName,sizeof(int)); //enviar nombre
	
	recvMSG(serverID,(void**)data,(int*)&dataLength);  //recibe datos
	

}


std::vector<std::string*> filemanager_stub::listFiles() {
	std::vector<std::string*>* fileList =
}


void filemanager_stub::freeListedFiles(std::vector<std::string*>* fileList){




}
