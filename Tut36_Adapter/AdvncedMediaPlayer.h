/*
 * AdvncedMediaPlayer.h
 *
 *  Created on: Oct 24, 2016
 *      Author: modys
 */

#ifndef ADVNCEDMEDIAPLAYER_H_
#define ADVNCEDMEDIAPLAYER_H_

#include <iostream>
#include <string>

using namespace std;
/**********Advanced Media Player***********/
class AdvancedMediaPlayer
{
public:
	AdvancedMediaPlayer()
	{
		cout<<"AdvancedMediaPlayer Constructor Called"<<endl;
	}
	virtual ~AdvancedMediaPlayer()
	{
		cout<<"AdvancedMediaPlayer Destructor Called"<<endl;
	}

	virtual void playVlc(string fileName)=0;
	virtual void playMp4(string fileName)=0;

};

class VlcPlayer :public AdvancedMediaPlayer
{
public:
	VlcPlayer()
	{
		cout<<"VlcPlayer Constructor Called"<<endl;
	}
	~VlcPlayer()
	{
		cout<<"VlcPlayer Destructor Called"<<endl;
	}

	void playVlc(string fileName)
	{
		cout<<"playing vlc file name"<<fileName<<endl;
	}
	void playMp4(string fileName)
	{

	}

};

class Mp4Player :public AdvancedMediaPlayer
{
public:
	Mp4Player()
{
		cout<<"Mp4Player Constructor Called"<<endl;
}
	~Mp4Player()
	{
		cout<<"Mp4Player Destructor Called"<<endl;
	}

	void playVlc(string fileName)
	{

	}
	void playMp4(string fileName)
	{
		cout<<"playing Mp4 file name"<<fileName<<endl;
	}

};


#endif /* ADVNCEDMEDIAPLAYER_H_ */
