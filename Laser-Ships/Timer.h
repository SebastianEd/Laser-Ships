#pragma once

#include <SDL.h>
#include "Singleton.h"

#define g_pTimer CTimer::Get ()

class CTimer : public TSingleton<CTimer> {

public: 
	CTimer();
	void Update();
	float GetElapsed() { return m_fElapsed; }

private:
	float m_fElapsed; //Elapsed Time since the last frame
	float m_fCurTime; // Current time
	float m_fLastTime; // Time of the last frame

};