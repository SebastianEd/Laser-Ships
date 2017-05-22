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
	Mix_CloseAudio();

}


//Destructor
//
CSound::~CSound() {

	if (m_pSoundEffect != nullptr) {
		Mix_FreeChunk(m_pSoundEffect);
		m_pSoundEffect = nullptr;
	}

	//I'm not really sure what this does, but I read at Stack Overflow that this returns if the music was freed or not
	if (!Mix_QuerySpec(0, 0, 0)){
		Mix_FreeMusic(m_pBMG);
	}

	if (m_pBMG != nullptr) {
		//This gives me an error when I close the Programm
		//Mix_FreeMusic(m_pBMG);
		m_pBMG = nullptr;
	}


	
}//Destructor




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




