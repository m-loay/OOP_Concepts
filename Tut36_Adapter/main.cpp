/*
 * main.cpp
 *
 *  Created on: Oct 16, 2016
 *      Author: modys
 */

#include "AudioPlayer.h"
int main()
{
	AudioPlayer device;
	cout<<endl;
	device.play("mp4"," Hello");
	cout<<endl;
	device.play("mp3"," Hello");
	cout<<endl;
	device.play("vlc"," Hello");
	cout<<endl;
}


