#include "filemanager_imp.h"


#define OP_SALIR               0

#define OP_READFILE		10
#define OP_WRITEFILE		11
#define OP_LISTFILES		12


filemanager_imp::filemanager_imp(int clientID, std::string path){

	this->clientID=clientID;
	this->salir=false;
	
	fm = new FileManager(path);
	
}


void filemanager_imp::atenderOperacion()
{
	while(!salir)
	{
	
	
		//recibir el tipo de operación
		int operacion=-1;
		char* datos=nullptr;
		int dataLen=0;
		recvMSG(clientID,(void**)&datos,&dataLen);
		memcpy(&operacion,datos, sizeof(int));
		delete datos;
		
			//seleccionar operacion
			//	caso 1
			//		recibir parametros op1
			//		ejecutar
			//		devolver resultado
			//....
			//  caso n
		switch(operacion)
		{
			case OP_SALIR:
			{
				this->salir=true;
			
			}break;
			
			case OP_READFILE:
			{
				//recibir nombre
		
				char* nombre=nullptr;
				unsigned long int fileLen=0;
				char* fileData=nullptr;
				
				
				recvMSG(clientID,(void**)&nombre,&dataLen);
				
				//leer fichero
				std::cout<<"El nombre recibido es:"<<nombre<<"\n";
				fm->readFile(nombre,fileData, fileLen);
				
			
				//devolver datos fichero
				sendMSG(clientID,(void*)fileData,fileLen);
				
				delete nombre;
				delete fileData;
			
			}break;
			
			
			case OP_WRITEFILE:{
				
				char* nombre=nullptr;
				int fileLen=0;
				char* fileData=nullptr;
				
				//recibir paquete variables 
				recvMSG(clientID,
					(void**)&nombre,&dataLen);
					
				//recibe datos fichero
				recvMSG(clientID,(void**)&fileData,&fileLen);
				
				//escribir fichero
				fm->writeFile(nombre,fileData,(unsigned long int)fileLen);
				
				
				//TODO añadir a la lista el nuevo fichero si no existe ya
				std::cout<<"Se escribio "<<nombre<<std::endl;
				delete nombre;
				delete fileData;
			
			}break;
			
			case OP_LISTFILES:{
				
				std::vector<std::string*> *list = fm->listFiles();
				
				int cantFicheros = list->size();
				
				//envia cantidad ficheros
				sendMSG(clientID,&(cantFicheros),sizeof(int));
				
				//enviar nombres de fichero
				for(int a=0;a<cantFicheros;a++) 
				{
					const char* nombre = list->at(a)->c_str();
					sendMSG(clientID,(void*)nombre,strlen(nombre)+1);
				}
				
				fm->freeListedFiles(list);
				
				
				
				
			
			}break;//copia en el momento x de this->files

			
			
		}	
	}

}





filemanager_imp::~filemanager_imp()
{
	closeConnection(clientID);
	delete fm;
}
