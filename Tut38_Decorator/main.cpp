/*
 * main.cpp
 *
 *  Created on: Oct 17, 2016
 *      Author: modys
 */

#include"Decorator.h"

int main ()
{
	AbstractNPC *goblin1= new Elite(new Shaman(new NPC(1,2)));
	//AbstractNPC *orc1= new Elite(new Captain(new NPC(3,4)));
	goblin1->draw(); cout << endl;
//	orc1->draw(); cout << endl;

	delete goblin1;
	//delete orc1;
}


