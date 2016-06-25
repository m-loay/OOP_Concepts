/*
 * main.cpp
 *
 *  Created on: Jun 25, 2016
 *      Author: modys
 */


#include<iostream>
#include <string>
#include "Menu.h"
using namespace std;


int main ()
{

	char *menu[COL]={"Insert","Print","Find",
			 "Delete","Get Count","Free List","Exit"};


	Menu sllMenu(7,20,20,8,menu);

	do {
		sllMenu.draw_menu();
		sllMenu.checkHotkey();
		sllMenu.menuBody();
	   } while ( sllMenu.getFlag()!=1 );


}
