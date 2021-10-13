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
	filemanager* fm=nullptr;

public:
	filemanager_imp(int clientID);
	~filemanager_imp();
	bool getSalir(){return salir;};
	void atenderOperacion();

};
