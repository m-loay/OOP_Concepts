/*
 * Startegy.h
 *
 *  Created on: Oct 19, 2016
 *      Author: modys
 */

#ifndef STARTEGY_H_
#define STARTEGY_H_
#include <iostream>
using namespace std;

class SortBehavior
{
public:
	SortBehavior ()
	{
		cout<<"SortBehavior  Called"<<endl;
	}
	virtual ~SortBehavior ()
	{
		cout<<"~SortBehavior  Called"<<endl;
	}
	virtual void sort() const = 0;
};

class Merge: public SortBehavior
{
    public:
	Merge()
	{
		cout<<"Merge Called"<<endl;
	}
	virtual ~Merge()
	{
		cout<<"~Merge Called"<<endl;
	}
        virtual void sort() const {
            cout << "Merge sort()\n";
        }
};

class Quick: public SortBehavior  {
    public:
	Quick()
	{
		cout<<"Quick Called"<<endl;
	}
	virtual ~Quick()
	{
		cout<<"~Quick Called"<<endl;
	}
        virtual void sort() const {
            cout << "Quick sort()\n";
        }
};

class Heap: public SortBehavior
{
    public:
	Heap()
	{
		cout<<"Heap Called"<<endl;
	}
	virtual ~Heap()
	{
		cout<<"~Heap Called"<<endl;
	}
        virtual void sort() const {
            cout << "Heap sort()\n";
    }
};

class Strategy
{
private:
     SortBehavior* m_sort;

 public:
     Strategy():m_sort(0)
 	{
 		cout<<"Strategy Called"<<endl;
 	}
 	~Strategy()
 	{
 		cout<<"~Strategy Called"<<endl;
 	}
     void set_sort(SortBehavior* s){
         m_sort = s;
     }

     void sort() const {
         m_sort->sort();
     }
};

#endif /* STARTEGY_H_ */
