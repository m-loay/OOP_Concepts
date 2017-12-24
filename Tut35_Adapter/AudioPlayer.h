/*
 * AudioPlayer.h
 *
 *  Created on: Oct 24, 2016
 *      Author: modys
 */

#ifndef AUDIOPLAYER_H_
#define AUDIOPLAYER_H_

#include <iostream>
#include <string>
#include "AdvncedMediaPlayer.h"

using namespace std;

class MediaPlayer
{
public:
	MediaPlayer()
{
		cout<<"MediaPlayer Constructor Called"<<endl;
}
	virtual ~MediaPlayer()
	{
		cout<<"MediaPlayer Destructor Called"<<endl;
	}

	virtual void play(string audioType, string fileName)=0;

};

class MediaAdapter :public MediaPlayer
{
public:
	 AdvancedMediaPlayer *advancedMusicPlayer;
	MediaAdapter(string audioType):advancedMusicPlayer(0)
	{
		if(audioType == "vlc")
			advancedMusicPlayer = new VlcPlayer;
		else if(audioType == "mp4")
			advancedMusicPlayer = new Mp4Player;

		cout<<"MediaAdapter Constructor Called"<<endl;
	}

	~MediaAdapter()
	{
		cout<<"MediaAdapter Destructor Called"<<endl;
		delete advancedMusicPlayer;
	}

	void play(string audioType, string fileName)
	{

			if(audioType == "mp4")
				advancedMusicPlayer->playMp4(fileName);
			else if(audioType == "vlc")
				advancedMusicPlayer->playVlc(fileName);
	}
};

class AudioPlayer :public MediaPlayer
{
public:
	AudioPlayer():playAdapter(0)
	{
		cout<<"AudioPlayer Constructor Called"<<endl;
	}
	~AudioPlayer()
	{
		cout<<"AudioPlayer Destructor Called"<<endl;
		delete playAdapter;
	}

	MediaAdapter *playAdapter;
	void play(string audioType, string fileName)
	{
		if(audioType == "mp3")
			cout<<"playing mp3 file name"<<fileName<<endl;

		  else if(audioType == "vlc"|| audioType == "mp4")
		  {
			  playAdapter = new MediaAdapter(audioType);
			  playAdapter->play(audioType, fileName);
		  }
	}
};


#endif /* AUDIOPLAYER_H_ */
