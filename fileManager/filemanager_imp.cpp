#include "filemanager_imp.h"


#define OP_SALIR               0

#define OP_READFILE		10
#define OP_WRITEFILE		11
#define OP_FREELISTEDFILES	12
#define OP_LISTFILES		13


filemanager_imp::filemanager_imp(int clientID, std::string path){
	
	this->path=path;

	this->clientID=clientID;
	this->salir=false;
	
	fm = new filemanager();
	//TODO crear lista de ficheros en files
	
	
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
				salir=true;
			
			}break;
			
			case OP_READFILE:
			{
				//recibir nombre
		
				char* nombre=nullptr;
				int fileLen=0;
				char* fileData=nullptr;
				char* moreData = nullptr;
				
				
				recvMSG(clientID,(void**)&nombre,&dataLen);
				
				//leer fichero
				fileData = fm->readFile(nombre,moreData, &fileLen)
				
			
				//devolver datos fichero
				sendMSG(clientID,(void*)fileData,fileLen);
				
				delete nombre;
				delete fileData;
				delete moreData;
			
			}break;
			
			
			case OP_WRITEFILE:{
				
				char* nombre=nullptr;
				int fileLen=0;
				char* fileData=nullptr;
				char* moreData = nullptr;
				
				//recibir paquete variables 
				recvMSG(clientID,
					(void**)&nombre,&dataLen);
				//escribir fichero
				fileData = fm->writeFile(nombre,moreData,&fileLen);
				
				//devolver datos fichero		
				sendMSG(clientID,(void*)fileData,fileLen);
				
				//TODO añadir a la lista el nuevo fichero si no existe ya
				
				delete nombre;
				delete fileData;
				delete moreData;
			
				
			}break;
			
			case OP_LISTFILES:{
				//pseudocodigo:
				//sendMSG(clientID,Vector De Ficheros,fileLen);
				
				//delete Vector De Ficheros;
			
			}break;//copia en el momento x de this->files

			
			case OP_FREELIST://libera un std::vector<std::string*>*
			{
				//vector<string*>* lista_fich;
				
				//fm ->freeListedFiles(lista_fich);
				 
			}
			
			break;
			
		}	
	}

}





filemanager_imp::~filemanager_imp()
{
	closeConnection(clientID);
}
