#include "Timer.h"	
#include <iostream>

//Constructor
//
//Initalizes timer
//
CTimer::CTimer() {

	m_fCurTime = 0.0f;
	m_fLastTime = SDL_GetTicks() / 1000.0f; //Divide by thousand to get seconds
	m_fElapsed = 0.0f;

}//Constructor

//Update
//
//Timer update
//
void CTimer::Update() {

	//Calculate the elapsed time since last frame
	m_fCurTime = SDL_GetTicks() / 1000.0f;

	m_fElapsed = m_fCurTime - m_fLastTime;
	m_fLastTime = m_fCurTime;

}//Update

