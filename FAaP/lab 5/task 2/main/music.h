#pragma once
#include <vector>
#include <iostream>

struct COMPOSITION {
	
	char Name[20];
	char CopmpName[20];
	char Style[20];
	unsigned Time;


};

struct CATALOG {

	char Name[10];
	unsigned N;
	COMPOSITION* Composition;

};