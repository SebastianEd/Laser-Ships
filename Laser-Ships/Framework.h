#pragma once

#include <iostream>
#include "Singleton.h"
#include "Timer.h"

#define g_pFramework CFramework::Get ()

class CFramework : public TSingleton<CFramework> {

public: 
	bool Init(int ScreenWidth, int ScreenHeight, int ColorDepth, bool bFullscreen);
	void Quit();
	void Update();
	void Clear();
	void Flip();
	bool KeyDown(int Key_ID);
	SDL_Surface *GetScreen() { return m_pScreen; };

private:
	SDL_Surface *m_pScreen;		//Surface for Screen
	Uint8 *m_pKeystate;			//Array for current keyboard status

};