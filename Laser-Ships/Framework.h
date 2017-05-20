#pragma once

#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>

#include "Singleton.h"
#include "Timer.h"

#define g_pFramework CFramework::Get()

class CFramework : public TSingleton<CFramework> {

public: 

	CFramework() {}; 
	CFramework(int ScreenWidth, int ScreenHeight, bool bFullscreen);
	~CFramework();

	void Update();
	int getScreenWidth() const { return m_ScreenWidth; };
	int getScreenHeight() const { return m_ScreenHeight; };
	inline bool isClosed() const {return m_Closed;}


private:
	bool Init();								
	void pollEvents();
	void Clear() const;

	std::string m_Title = "Laser-Ships";			//Title of the Game
	SDL_Window *m_pWindow = nullptr;				//Pointer on the Window					
	
	bool m_Closed = false;							//Window closed?
	int m_ScreenWidth;
	int m_ScreenHeight;
	bool m_Fullscreen;								//Fullscreen mode?



protected:
	SDL_Renderer *m_pRenderer = nullptr;			//Pointer on renderer

};