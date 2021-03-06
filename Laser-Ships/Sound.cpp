#include "Sound.h"

//Constructor
//
CSound::CSound() {

	m_pBMG = nullptr;
	m_pSoundEffect = nullptr;

	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
		std::cerr << "Error: " << Mix_GetError() << std::endl;
	}

}//Constructor

void CSound::CleanUp() {
	freeMusic();
	Mix_CloseAudio();
	Mix_Quit();

}


//Destructor
//
CSound::~CSound() {

	if (m_pSoundEffect != nullptr) {
		Mix_FreeChunk(m_pSoundEffect);
		m_pSoundEffect = nullptr;
	}
	
}//Destructor



void CSound::freeMusic() {

	if (m_pBMG != nullptr) {
		Mix_FreeMusic(m_pBMG);
		m_pBMG = nullptr;
	}

	//You never can be sure enough to free your memory :D
	if (m_pSoundEffect != nullptr) {
		Mix_FreeChunk(m_pSoundEffect);
		m_pSoundEffect = nullptr;
	}
}



//playBMG: plays background music
//
void CSound::playBGM(const std::string &filePath) {

	//Load Background Music
	m_pBMG = Mix_LoadMUS(filePath.c_str());

	if (!Mix_PlayingMusic()) {
		Mix_PlayMusic(m_pBMG, -1);
	}

}//playBGM


//playSoundEffect
//
void CSound::playSoundEffect(const std::string &filePath) {

	m_pSoundEffect = Mix_LoadWAV(filePath.c_str());
	Mix_PlayChannel(-1, m_pSoundEffect, 0);


}//playSoundEffect




