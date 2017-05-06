#include "Framework.h"

//Init
//
//Initialize framework
//
bool CFramework::Init(int ScreenWidth, int ScreenHeight, int ColorDepth, bool bFullscreen) {

	//Initialize systems of the SDL
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) == -1) {
		
		std::cerr << "SDL couldn't be initialized!\n";
		std::cerr << "Error: " << SDL_GetError() << std::endl;

		Quit();

		return (false);
	}

	//Fullscreen or Windowmode
	if (bFullscreen == true) {
		m_pScreen = SDL_SetVideoMode(ScreenWidth, ScreenHeight, ColorDepth, SDL_SWSURFACE| SDL_GL_DOUBLEBUFFER | SDL_WINDOW_FULLSCREEN);
	}
	else {

	}

	//Did everything work?SS
	if (m_pScreen == nullptr) {
		
		std::cerr << "Video Mode couldn't be set properly!\n";
		std::cerr << "Error: " << SDL_GetError() << std::endl;

		Quit();

		return (false);
	}

	m_pKeystate = SDL_GetKeyboardState(NULL);

	//Everything did work -> return true
	return (true);
}