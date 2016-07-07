/*
 * Employee.h
 *
 *  Created on: Jun 18, 2016
 *      Author: modys
 */

#ifndef MENU_H_
#define MENU_H_
#include<string>
#include "conio2.h"
#include "singleLinkedList.h"
#include "Stack.h"
#define UP 	  	72
#define DOWN  	80
#define HOME  	71
#define END   	79
#define ESC	  	27
#define ENTER 	13
#define ROW   	7
#define COL   	20

using namespace std;


class Menu {
public:
	Menu(const string *, const Stack &,int ,int ,int ,int);
	bool getFlag ()const
	{
		return flag;
	}
	void draw_menu ();
	void checkHotkey();
	void menuBody();
	~Menu();

private:
	const string  *p;
	Stack link;
	const int row;
	const int col;
	const int x_start;
	const int y_start;
	int ch;
	int choice;
	int input;
	bool flag;
};

#endif /* MENU_H_ */
