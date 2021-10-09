#include "multmatrix_imp.h"


#define OP_SALIR 				0

#define OP_READMATRIX  				10
#define OP_MULTMATRICES			11
#define OP_WRITEMATRIX  			12
#define OP_CREATEIDENTITY  	13
#define OP_CREATERANDMATRIX  			14


multmatrix_imp::multmatrix_imp(int clientID)
{
	this->clientID=clientID;
	this->salir=false;
	
	mult=new multmatrix();
}


void multmatrix_imp::atenderOperacion()
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
			
			case OP_READMATRIX:
			{
				//recibir argumentos
				int rows=0,cols=0;
				int * p = nullptr;
				char* nombre=nullptr;
				
				recvMSG(clientID,(void**)&nombre,&dataLen);
				/*recvMSG(clientID,(void**)&datos,&dataLen);
				memcpy(&a,datos, sizeof(int));
				delete datos;*/
				
				/*recvMSG(clientID,(void**)&datos,&dataLen);
				memcpy(&b,datos, sizeof(int));
				delete datos;*/
				
				matrix_t* m=mmatrix->readMatrix(nombre+".txt");
				
				rows = m.rows;
				cols = m.cols;
				p = malloc((rows*cols) * sizeof(int));
   				memcpy(p, m.data, (rows*cols) * sizeof(int));
				
				//devolver resultado
				sendMSG(clientID,(void*)&rows,sizeof(int));
				sendMSG(clientID,(void*)&cols,sizeof(int));
				sendMSG(clientID,(void*)p,sizeof(int));
			
			}break;
			
			
			case OP_MULTMATRICES:{
				float* a=nullptr;
				float* b=nullptr;
				int tam=0;
				float resultado=0;
				//recibir paquete variables 
				recvMSG(clientID,
					(void**)&datos,&dataLen);
				//desempaqueto
				tam=dataLen/(sizeof(float)*2);
				a=(float*)datos;
				b=(float*)&datos[sizeof(float)*tam];				
				
				resultado=ops->multVector(a,b,tam);
				delete datos;
				
				//enviar resultado
				sendMSG(clientID,(void*)&resultado,sizeof(float));
				
			}break;
			
			case OP_WRITEMATRIX:
			{
				//recibir nombre
				char* nombre=nullptr;
				int fileLen=0;
				char* fileData=nullptr;
				
				recvMSG(clientID,(void**)&nombre,&dataLen);
				
				//leer fichero
				fileData=ops->leeFichero(nombre,&fileLen);
				
				//devolver datos fichero
				sendMSG(clientID,(void*)fileData,fileLen);
				delete nombre;
				delete fileData;
				
			}
			
			break;
			case OP_CREATEIDENTITY:
			{
				ops->incrementaCount();
			}
			
			break;
			
			case OP_CREATERANDMATRIX:
			{
				int resultado=0;
				resultado=ops->getCount();
				
				sendMSG(clientID, &resultado,sizeof(int));
			}
			
			break;			
			default:
			{
				std::cout<<"ERROR: Operacion no valida\n";
			}break;
		}	
	}

}

multmatrix_imp::~multmatrix_imp()
{
	closeConnection(clientID);
}

