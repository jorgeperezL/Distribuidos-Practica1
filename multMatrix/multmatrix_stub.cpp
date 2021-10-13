#include "multmatrix_stub.h"

multmatrix_stub::multmatrix_stub()
{
	char* ip=new char[strlen(SERVER_IP)+1];
	memcpy(ip,SERVER_IP,strlen(SERVER_IP)+1);
	
	serverID=initClient(ip,SERVER_PORT);
	
	delete ip;
}

multmatrix_stub::~multmatrix_stub()
{
	int operacion=OP_SALIR;
	sendMSG(serverID, (void*)&operacion, sizeof(int));
//
	closeConnection(serverID);
}


matrix_t * multmatrix_stub::readMatrix(const char* fileName){
	//enviar operacion
	int operacion=OP_READMATRIX;
	char* datos=nullptr;
	int dataLen=0;
	matrix_t* m = new matrix_t();
	
	//enviar argumentos
		
	sendMSG(serverID,(void*)&operacion,sizeof(int));
	
	sendMSG(serverID,(void*)fileName,strlen(fileName)+1);	
				
	//recibir resultado
	
	recvMSG(clientID,(void**)&datos,&dataLen);
				
	m.rows = (int*)datos;
	m.cols = (int*)&datos[sizeof(int)];
	m->data = (int**)&datos[sizeof(int)*2];
	
	delete datos;
			s	
	return m;
}



matrix_t * multmatrix_stub::multMatrices(matrix_t* m1, matrix_t *m2){

	int operacion=OP_MULTMATRICES;
	char* datos=nullptr;
	int dataLen=0;
	matrix_t* mres = new matrix_t();
	
//enviar tipo operacion
	sendMSG(serverID,(void*)&operacion,sizeof(int));

//enviar datos
	//crear paquete datos
	datos = new char[sizeof(int)*((m1.rows*m1.cols)+2));
	memcpy(datos,&m1.rows,sizeof(int));
	memcpy(&datos[sizeof(int)],&m1.cols,sizeof(int));
	memcpy(&datos[sizeof(int)*2],m1->data,sizeof(int)*(m1.rows*m1.cols));
	//enviar
	sendMSG(clientID,(void*)datos,sizeof(int)*((m1.rows*m1.cols)+2));
	delete datos;
//enviar datos
	//crear paquete datos
	datos = new char[sizeof(int)*((m2.rows*m2.cols)+2));
	memcpy(datos,&m2.rows,sizeof(int));
	memcpy(&datos[sizeof(int)],&m2.cols,sizeof(int));
	memcpy(&datos[sizeof(int)*2],m2->data,sizeof(int)*(m2.rows*m2.cols));
	//enviar
	sendMSG(clientID,(void*)datos,sizeof(int)*((m2.rows*m2.cols)+2));
	delete datos;
//recibir resultado
	recvMSG(clientID,(void**)&datos,&dataLen);
				
	mres.rows = (int*)datos;
	mres.cols = (int*)&datos[sizeof(int)];
	mres->data = (int**)&datos[sizeof(int)*2];		
				
	delete datos;
	
 	return mres;
}


void multmatrix_stub::writeMatrix(matrix_t* m, const char *fileName)
{
	char* fileData=nullptr;
	char* datos=nullptr;
	int operacion=OP_WRITEMATRIX;
	
	//enviar tipo operacion
	sendMSG(serverID,(void*)&operacion,sizeof(int));
	
	//enviar nombre
	sendMSG(serverID,(void*)fileName,strlen(fileName)+1);
	
	datos = new char[sizeof(int)*((m.rows*m.cols)+2));
	memcpy(datos,&m.rows,sizeof(int));
	memcpy(&datos[sizeof(int)],&m.cols,sizeof(int));
	memcpy(&datos[sizeof(int)*2],m->data,sizeof(int)*(m.rows*m.cols));
	//enviar
	sendMSG(clientID,(void*)datos,sizeof(int)*((m1.rows*m1.cols)+2));
	delete datos;
}


matrix_t* multmatrix_stub::createIdentity(int rows, int cols){

	int operacion=OP_CREATEIDENTITY;
	char* datos=nullptr;
	matrix_t* mres = new matrix_t();
	
//enviar tipo operacion
	sendMSG(serverID,(void*)&operacion,sizeof(int));
	
	//enviar argumentos
	sendMSG(serverID,(void*)&rows,sizeof(int));	
	sendMSG(serverID,(void*)&cols,sizeof(int));
	
	//recibir resultado
	recvMSG(clientID,(void**)&datos,&dataLen);
				
	mres.rows = (int*)datos;
	mres.cols = (int*)&datos[sizeof(int)];
	mres->data = (int**)&datos[sizeof(int)*2];		
				
	delete datos;
	
	return mres;
}


matrix_t * multmatrix_stub::createRandMatrix(int rows, int cols){
	int operacion=OP_CREATERANDMATRIX;
	char* datos=nullptr;
	matrix_t* mres = new matrix_t();
	
//enviar tipo operacion
	sendMSG(serverID,(void*)&operacion,sizeof(int));
	
	//enviar argumentos
	sendMSG(serverID,(void*)&rows,sizeof(int));	
	sendMSG(serverID,(void*)&cols,sizeof(int));
	
	//recibir resultado
	recvMSG(clientID,(void**)&datos,&dataLen);
				
	mres.rows = (int*)datos;
	mres.cols = (int*)&datos[sizeof(int)];
	mres->data = (int**)&datos[sizeof(int)*2];		
				
	delete datos;
	
	return mres;
}

