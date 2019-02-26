
#ifndef __SoundController_H__
#define __SoundController_H__

#include "cocos2d.h"
#include"SimpleAudioEngine.h"
enum Esounds
{
	E_PlayerMove,// player di chuyen
	E_EatKey = 0,
	E_Win,
	E_Lose,
	E_last,
};
class SoundController
{
public :
	void preloadEffect(Esounds sound);
	void playMusic(Esounds  sound, bool isLoop = false);
	void preloadingAndPlayMusic(Esounds sound, bool isLoop = false);
	void preloadingAndPlayEffect(Esounds sound, bool isLoop = false);
	void playEffect(Esounds sound, bool isloop = false);
};

#endif // __SoundController_H__
