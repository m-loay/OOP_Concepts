/*
 * main.cpp
 *
 *  Created on: Jun 18, 2016
 *      Author: modys
 */

#include<iostream>
#include "Menu.h"
#include "singleLinkedList.h"
#define DEBUG 0
using namespace std;

int main()
{
	string data[ROW]={"Queue","Print","Find", "Dequeue","Get Count","Free List","Exit"};
	Qeue qeue_sll;
	Menu sll_menu(data, qeue_sll, ROW, COL, 20,8);



#if(DEBUG==0)
	do
	{
		sll_menu.draw_menu();
		sll_menu.checkHotkey();
		sll_menu.menuBody();

	}while(sll_menu.getFlag()!=1);

#endif


}