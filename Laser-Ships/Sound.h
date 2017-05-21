#pragma once

#include <SDL_mixer.h>
#include <string>
#include <iostream>

class CSound{

public:

	CSound();
	~CSound();

	void playBGM(const std::string &filePath);
	void playSoundEffect(const std::string &filePath);
	void mixerQuit() { Mix_Quit(); };

private:

	Mix_Music *m_pBMG;
	Mix_Chunk *m_pSoundEffect;

};

static int Counter = 0;
