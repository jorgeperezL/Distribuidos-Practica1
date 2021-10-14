#pragma once

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "filemanager.h"


class filemanager_imp
{

private:
	int clientID=-1;
	bool salir=false;
	FileManager* fm=nullptr;
	std::map<std::string, std::string* > files;
public:
	filemanager_imp(int clientID,std::string path);
	~filemanager_imp();
	bool getSalir(){return salir;};
	void atenderOperacion();

};
