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
	
	mult=new multMatrix();
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
				char* nombre=nullptr;
				

				recvMSG(clientID,(void**)&nombre,&dataLen);
				
				matrix_t *m=mult->readMatrix(nombre);
				
				
				datos = new char[sizeof(int)*((m->rows*m->cols)+2)];
				memcpy(datos,&m->rows,sizeof(int));
				memcpy(&datos[sizeof(int)],&m->cols,sizeof(int));
				memcpy(&datos[sizeof(int)*2],m->data,sizeof(int)*(m->rows*m->cols));
				
				//devolver resultado
				sendMSG(clientID,(void*)datos,sizeof(int)*((m->rows*m->cols)+2));
				
				delete datos;
				delete nombre;
			}break;
			
			
			case OP_MULTMATRICES:{
			
				matrix_t * m1 = new matrix_t();
				matrix_t * m2 = new matrix_t();
				
				recvMSG(clientID,(void**)&datos,&dataLen);
				
				memcpy(&m1->rows,datos,sizeof(int));
				memcpy(&m1->cols,&datos[sizeof(int)],sizeof(int));
				m1->data = new int[sizeof(int)*(m1->rows*m1->cols)];
				memcpy(m1->data,(int*)&datos[sizeof(int)*2],sizeof(int)*(m1->rows*m1->cols));
				//m1->data = (int*)&datos[sizeof(int)*2];		
				
				delete datos;
				
				recvMSG(clientID,(void**)&datos,&dataLen);
				
				memcpy(&m2->rows,datos,sizeof(int));
				memcpy(&m2->cols,&datos[sizeof(int)],sizeof(int));
				m2->data = new int[sizeof(int)*(m2->rows*m2->cols)];
				memcpy(m2->data,(int*)&datos[sizeof(int)*2],sizeof(int)*(m2->rows*m2->cols));
				//m2->data = (int*)&datos[sizeof(int)*2];
				
				delete datos;
				
				matrix_t* mres=mult->multMatrices(m1,m2);				
				
				delete m1;
				delete m2;
				
				datos = new char[sizeof(int)*((mres->rows*mres->cols)+2)];
				memcpy(datos,&mres->rows,sizeof(int));
				memcpy(&datos[sizeof(int)],&mres->cols,sizeof(int));
				memcpy(&datos[sizeof(int)*2],mres->data,sizeof(int)*(mres->rows*mres->cols));
				
				//devolver resultado
				sendMSG(clientID,(void*)datos,sizeof(int)*((mres->rows*mres->cols)+2));
				
				delete datos;
				
			}break;
			
			case OP_WRITEMATRIX:
			{
				matrix_t *m = new matrix_t();
				char* nombre=nullptr;				
				
				recvMSG(clientID,(void**)&nombre,&dataLen);
				
				recvMSG(clientID,(void**)&datos,&dataLen);
				
				memcpy(&m->rows,datos,sizeof(int));
				memcpy(&m->cols,&datos[sizeof(int)],sizeof(int));
				m->data = new int[sizeof(int)*(m->rows*m->cols)];
				memcpy(m->data,(int*)&datos[sizeof(int)*2],sizeof(int)*(m->rows*m->cols));
				//m->data = (int*)&datos[sizeof(int)*2];
						
				
		
				mult->writeMatrix(m,nombre);
				
				delete nombre;
				delete datos;
				delete m;
			}
			
			break;
			case OP_CREATEIDENTITY:
			{
				
				int rows=0,cols=0;
					
				recvMSG(clientID,(void**)&datos,&dataLen);
				memcpy(&rows,datos, sizeof(int));
				delete datos;
				
				recvMSG(clientID,(void**)&datos,&dataLen);
				memcpy(&cols,datos, sizeof(int));
				delete datos;
				
    				matrix_t* m= mult->createIdentity(rows,cols);
    				
    				datos = new char[sizeof(int)*((m->rows*m->cols)+2)];
				memcpy(datos,&m->rows,sizeof(int));
				memcpy(&datos[sizeof(int)],&m->cols,sizeof(int));
				memcpy(&datos[sizeof(int)*2],m->data,sizeof(int)*(m->rows*m->cols));
				
				//devolver resultado
				sendMSG(clientID,(void*)datos,sizeof(int)*((m->rows*m->cols)+2));
				
				delete datos;
			}
			
			break;
			
			case OP_CREATERANDMATRIX:
			{
				int rows=0,cols=0;
					
				recvMSG(clientID,(void**)&datos,&dataLen);
				memcpy(&rows,datos, sizeof(int));
				delete datos;
				
				recvMSG(clientID,(void**)&datos,&dataLen);
				memcpy(&cols,datos, sizeof(int));
				delete datos;
					
				matrix_t* m= mult->createRandMatrix(rows,cols);
				
				datos = new char[sizeof(int)*((m->rows*m->cols)+2)];
				memcpy(datos,&m->rows,sizeof(int));
				memcpy(&datos[sizeof(int)],&m->cols,sizeof(int));
				memcpy(&datos[sizeof(int)*2],m->data,sizeof(int)*(m->rows*m->cols));
				
				//devolver resultado
				sendMSG(clientID,(void*)datos,sizeof(int)*((m->rows*m->cols)+2));
				
				delete datos;				
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

