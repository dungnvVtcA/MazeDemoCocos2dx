#include"Controller/SoundController.h"
static char soundNames[E_last][30] = {
	// player move
	//player aet key
	//player win
	//player lose

};
void SoundController::playMusic(Esounds sound, bool isloop)
{
	CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic(soundNames[sound], isloop);
}
void SoundController::playEffect(Esounds sound, bool isLoop)
{
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(soundNames[sound], isLoop);

}
void SoundController::preloadingAndPlayMusic(Esounds sound, bool isLoop)
{
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic(soundNames[sound]);
	CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic(soundNames[sound], isLoop);

}
void SoundController::preloadingAndPlayEffect(Esounds sound, bool isLoop)
{
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect(soundNames[sound]);
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(soundNames[sound], isLoop);
}
void SoundController::preloadEffect(Esounds sound)
{
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect(soundNames[sound]);
}