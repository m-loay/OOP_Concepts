/*
 * Employee.cpp
 *
 *  Created on: Jun 18, 2016
 *      Author: modys
 */

#include "Menu.h"

#include <iostream>
#include "singleLinkedList.h"

using namespace std;

Menu::Menu (const string *list, const Qeue &sll,int r ,int c ,int x_pos ,int y_pos)
:p(list), link(sll),
 row(r),col(c),x_start(x_pos),y_start(y_pos)
{
	// TODO Auto-generated constructor stub
	ch=0;
	choice=0;
	flag=0;
	input=0;
	gotoxy(0,0);
	textattr(0x07);
	clrscr();
	cout << "Menu object constructor: "<< endl;
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
		gotoxy(x_start,2*counter+y_start);
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
			cout<<"Enter a data to Queue"<<endl;
			cin>>input;
			link.insert(input)?cout<<input<<' '<<"has been added to Queue"<<endl:cout<<input<<' '<<"has not been added to Queue"<<endl;
			link.print();

			cout<<"Press any key to back to main menu"<<endl;
			getch();
		}
		break;
		case 1:
		{
			clrscr();
			gotoxy(0,0);
			/*Please Add your function here*/
			cout<<p[1]<<endl;
			if(!link.isEmpty())
			{
				link.print();
			}
			else cout<<"The Queue is empty"<<endl;

			cout<<"Press any key to back to main menu"<<endl;
			getch();
		}
		break;
		case 2:
		{
			clrscr();
			gotoxy(0,0);
			/*Please Add your function here*/
			cout<<p[2]<<endl;
			if(!link.isEmpty())
			{
				cout<<"Enter an element to find to Queue"<<endl;
				cin>>input;
				link.find(input)?cout<<input<<' '<<"has been found to Queue"<<endl:cout<<input<<' '<<"has not been found in Queue"<<endl;
			}
			else cout<<"The Queue is empty"<<endl;
			getch();
			break;
		}
		break;

		case 3:
			clrscr();
			gotoxy(0,0);
			/*Please Add your function here*/
			cout<<p[3]<<endl;
			if(!link.isEmpty())
			{
				link.remove()?cout<<"has been deleted from Queue"<<endl:cout<<' '<<"has not been found in Queue"<<endl;
				link.print();
			}
			else cout<<"The Queue is empty"<<endl;
			getch();
			break;

		case 4:
			clrscr();
			gotoxy(0,0);
			/*Please Add your function here*/
			cout<<p[4]<<endl;
			if(!link.isEmpty())
			{
				input=link.getCount();
				cout<<input<<' '<<"elements in the Queue"<<endl;
			}
			else cout<<"The Queue is empty"<<endl;
			getch();
			break;

		case 5:
			clrscr();
			gotoxy(0,0);
			/*Please Add your function here*/
			cout<<p[5]<<endl;
			if(!link.isEmpty())
			{
				link.freeList();
			}
			else cout<<"The Queue is empty"<<endl;
			getch();
			break;

		case 6:
			flag=1;
			break;

		}
	}
	}
}


Menu::~Menu()
{
	cout << "Menu object Destructor: ";
}



