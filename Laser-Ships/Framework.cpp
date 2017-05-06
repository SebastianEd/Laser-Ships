#include "Framework.h"

//Init
//
//Initialize framework
//
bool CFramework::Init(int ScreenWidth, int ScreenHeight, bool bFullscreen) {

	//Initialize systems of the SDL
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) != 0) {
		
		std::cerr << "SDL couldn't be initialized!\n";
		std::cerr << "Error: " << SDL_GetError() << std::endl;

		Quit();

		return (false);
	}

	//Fullscreen or Windowmode
	if (bFullscreen == true) {
		m_pWindow = SDL_CreateWindow(
			m_Title.c_str(),
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
			ScreenWidth, ScreenHeight,
			SDL_WINDOW_FULLSCREEN_DESKTOP);
	}
	else {
			m_pWindow = SDL_CreateWindow(
				m_Title.c_str(),
				SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
				ScreenWidth, ScreenHeight,
				0);

	}

	//Did everything work?
	if (m_pWindow == nullptr) {
		
		std::cerr << "Failed to create Window!\n";
		std::cerr << "Error: " << SDL_GetError() << std::endl;

		Quit();

		return 0;
	}

	m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, SDL_RENDERER_ACCELERATED);

	if (m_pRenderer == nullptr) {

		std::cerr << "Failed to create Renderer!\n";
		std::cerr << "Error: " << SDL_GetError() << std::endl;

		Quit();

		return 0;
	}

	return 0;
}

// Quit
//
// Aufgabe: Framework (SDL) beenden
//
void CFramework::Quit()
{
	// SDL beenden
	SDL_DestroyRenderer(m_pRenderer);
	SDL_DestroyWindow(m_pWindow);
	SDL_Quit();

} // Quit


void CFramework::pollEvents() {
	SDL_Event Event;

	if (SDL_PollEvent(&Event)) {

		switch (Event.type) {
		case SDL_QUIT:
			m_Closed = true;
			break;
		}
	}
}