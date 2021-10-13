#include "filemanager_stub.h"


filemanager_stub::filemanager_stub(){

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

void filemanager_stub::writeFile(char* fileName, char* data, unsigned long int dataLength){

	int operacion = OP_WRITEFILE;
	
	sendMSG(serverID,(void*) &operacion,sizeof(int)); //tipo operacion
	sendMSG(serverID,(void*) fileName,sizeof(int)); //enviar nombre
	
	recvMSG(serverID,(void**)&data,&dataLength);  //recibe datos
	
}





void filemanager_stub::readFile(char* fileName, char* &data, unsigned long int &dataLength){
	
	//ya tenemos un puntero de data por parametro
	int operacion = OP_READFILE;
	
	sendMSG(serverID,(void*) &operacion,sizeof(int)); //tipo operacion
	sendMSG(serverID,(void*) fileName,sizeof(int)); //enviar nombre
	
	recvMSG(serverID,(void**)data,dataLength);  //recibe datos
	

}





void filemanager_stub::freeListedFiles(vector<string*>* fileList){




}
