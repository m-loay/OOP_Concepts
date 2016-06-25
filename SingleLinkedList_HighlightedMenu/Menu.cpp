/*
 * Menu.cpp
 *
 *  Created on: Jun 25, 2016
 *      Author: modys
 */

#include "Menu.h"
using namespace std;

Menu::Menu(int r, int c,int x_pos,int y_pos , char *str[7] )
:row((r>0 && r<=20)?r:10),col((c>0 && c<=15)?c:10),x_start((r>0 && r<=20)?r:10),y_start((c>0 && c<=15)?c:10)
{
	// TODO Auto-generated constructor stu

	ch=0;
	choice=0;
	flag=0;
	for(int i=0; i<7;i++)
	{
		this->p[i]=str[i];
	}
	gotoxy(0,0);
	textattr(0x07);
	clrscr();
	cout << "Date object constructor for Menu ";
}

Menu::~Menu()
{
	// TODO Auto-generated destructor stub
	cout << "Date object destructor for Menu ";
}

void Menu::draw_menu()
{
	int counter;
	gotoxy(0,0);
	textattr(0x07);
	clrscr();
	for(counter=0;counter<row;counter++)
	{
		gotoxy(0,0);
		//gotoxy(-50 , 2*counter+y_start);

		if(choice==counter)
		{
			textattr(0x34);
			cout << "\n" << p[counter] << endl;
		}
		else
		{
			textattr(0x07);
			cout << "\n" << p[counter] << endl;

		}

	}
}

void Menu::checkHotkey()
{
	ch=getch();
	if(ch != '\0')
	{
		switch(ch)
		{
		case UP:
		{
			choice--;
			if (choice<0) choice=row-1;
		}
		break;
		case DOWN:
		{
			choice++;
			if (choice>row-1) choice=0;
		}
		break;
		case HOME:
		{
			choice=0;
		}
		break;

		case END:
		{
			choice=row-1;
		}
		break;
		}

	}
}

void Menu::menuBody()
{
	switch (ch)
	{
	case ESC:
	{
		clrscr();
		flag=1;
	}
	break;

	case ENTER:
	{
		switch(choice)
		{
		case 0:
		{
			clrscr();
			gotoxy(0,0);
			/*Please Add your function here*/
			cout<<p[0]<<endl;

			getch();
		}
		break;
		case 1:
		{
			clrscr();
			gotoxy(0,0);
			/*Please Add your function here*/
			cout<<p[1]<<endl;

			getch();
		}
		break;
		case 2:
		{
			clrscr();
			gotoxy(0,0);
			/*Please Add your function here*/
			cout<<p[2]<<endl;
			getch();
			break;
		}
		break;

		case 3:
			clrscr();
			gotoxy(0,0);
			/*Please Add your function here*/
			cout<<p[3]<<endl;
			getch();
			break;

		case 4:
			clrscr();
			gotoxy(0,0);
			/*Please Add your function here*/
			cout<<p[4]<<endl;
			getch();
			break;

		case 5:
			clrscr();
			gotoxy(0,0);
			/*Please Add your function here*/
			cout<<p[5]<<endl;
			getch();
			break;

		case 6:
			flag=1;
			break;

		}
	}
	}
}


