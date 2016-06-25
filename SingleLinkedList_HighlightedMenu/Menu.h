/*
 * Menu.h
 *
 *  Created on: Jun 25, 2016
 *      Author: modys
 */

#ifndef MENU_H_
#define MENU_H_

#include<iostream>
#include<string>

#include "common.h"
using namespace std;

class Menu
{

public:
	Menu(int , int, int, int , char *str[7] );
	virtual ~Menu();

	bool getFlag ()const
	{
		return flag;
	}
	void draw_menu ();
	void checkHotkey();
	void menuBody();

private:
	const int row;
	const int col;
	const int x_start;
	const int y_start;
	int ch;
	int choice;
	bool flag;
	char *p[7];

};

#endif /* MENU_H_ */
