#pragma once

#include "LoadSprites.h"
#include "Framework.h"

#define max_Row 10

class CLaser {
public:

	CLaser(CSprite *pShotSprite, float fPos_x, float fPos_y);

	void setDirection(char direction);
	void Update();
	void Render(int x, int y);
	bool isAlive() { return m_bIsAlive; };

	void setFrameSize(){
		m_Rect.w = 30;
		m_Rect.h = 4;
	}

private:

	CSprite *m_pShotSprite = nullptr;

	float m_fPos_x, m_fPos_y;
	bool m_bIsAlive;
	char m_look_direction = 'r';


	int m_Row; //for Animation
	float m_fAnimationPhase = 0.0f;

	float m_fMoveSpeed = 700.0f;

	SDL_Rect m_Rect;



};
