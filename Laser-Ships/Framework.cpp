#include "Framework.h"


//Constructor
//
CFramework::CFramework(int ScreenWidth, int ScreenHeight, bool bFullscreen) :
	m_ScreenWidth(ScreenWidth), m_ScreenHeight(ScreenHeight), m_Fullscreen(bFullscreen)
{
	if (!Init()) {
		m_Closed = true;
	}

}//Constructor

//Destructor
//
CFramework::~CFramework() {

	SDL_DestroyRenderer(m_pRenderer);
	SDL_DestroyWindow(m_pWindow);
	IMG_Quit();
	Mix_Quit();
	SDL_Quit();

}//Destructor 


//Init
//
//Initialize framework
//
bool CFramework::Init() {

	//Initialize systems of the SDL
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_AUDIO) != 0) {
		
		std::cerr << "SDL couldn't be initialized!\n";
		std::cerr << "Error: " << SDL_GetError() << std::endl;

		return false;
	}

	if (IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG) != (IMG_INIT_PNG | IMG_INIT_JPG)) {

		std::cerr << "Failed to initialize SDL_image.\n";
		return false;
	}

	//Fullscreen or Windowmode
	if (m_Fullscreen == true) {
		m_pWindow = SDL_CreateWindow(
			m_Title.c_str(),
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
			m_ScreenWidth, m_ScreenHeight,
			SDL_WINDOW_FULLSCREEN_DESKTOP);
	}
	else {
			m_pWindow = SDL_CreateWindow(
				m_Title.c_str(),
				SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
				m_ScreenWidth, m_ScreenHeight,
				NULL);

	}

	//Did everything work?
	if (m_pWindow == nullptr) {
		
		std::cerr << "Failed to create Window!\n";
		std::cerr << "Error: " << SDL_GetError() << std::endl;

		return false;
	}

	//Renderer
	m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	//Makes Rendering look smoother
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");  // make the scaled rendering look smoother.
	SDL_RenderSetLogicalSize(m_pRenderer, 1080, 720);


	if (m_pRenderer == nullptr) {

		std::cerr << "Failed to create Renderer!\n";
		std::cerr << "Error: " << SDL_GetError() << std::endl;

		return false;
	}

	//Ende Renderer


	return true;
}//Init

//Update
//
void CFramework::Update() {
	SDL_PumpEvents();
	pollEvents();
	Clear();
	g_pTimer->Update();
}//

//pollEvents
//
//Process Events
//
void CFramework::pollEvents() {
	SDL_Event Event;

	if (SDL_PollEvent(&Event)) {

		switch (Event.type) {
		case SDL_QUIT:
			m_Closed = true;
			break;

		}
	}

}//pollEvents

//Clear
//
void CFramework::Clear() const {

	SDL_RenderPresent(m_pRenderer);
	SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);
	SDL_RenderClear(m_pRenderer);

}//Clear

