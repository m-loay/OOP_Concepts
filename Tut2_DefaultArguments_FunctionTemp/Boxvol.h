/*
 * Boxvol.h
 *
 *  Created on: Jun 13, 2016
 *      Author: modys
 */

#ifndef BOXVOL_H_
#define BOXVOL_H_


#include "iostream"
#include "maximum.h"
using namespace std;

class Box_vol
{
public:
	Box_vol();
	virtual ~Box_vol();
	void setDim(int length=1, int width=1, int height=1 );
	int getVolume(void);
	int getBiggestInt(void);
	double getBiggestDouble(void);
	void print_volume (void);
	void max_valueInt(int op1=0, int op2=0, int op3=0);
	void max_valueDouble(double op1=0, double op2=0, double op3=0);

private:
	int volume,len,wid,high,biggest_int ;
	double biggest_double;
	void boxVolume( void );
};

#endif /* BOXVOL_H_ */
