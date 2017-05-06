#pragma once

#include <iostream>
#include <string>
#include "Singleton.h"
#include "Timer.h"

#define g_pFramework CFramework::Get ()

class CFramework : public TSingleton<CFramework> {

public: 
	bool Init(int ScreenWidth, int ScreenHeight, bool bFullscreen);
	void Quit();
	void pollEvents();

	inline bool isClosed() const {
		return m_Closed;
	}


	void Update();
	void Clear();
	void Flip();
	bool KeyDown(int Key_ID);

private:
	std::string m_Title = "Laser-Ships";			//Title of the Game
	SDL_Window *m_pWindow = nullptr;				//Pointer on the Window					
	SDL_Renderer *m_pRenderer = nullptr;			//Pointer on renderer
	bool m_Closed = false;

};