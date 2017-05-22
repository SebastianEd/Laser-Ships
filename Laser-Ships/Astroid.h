#pragma once

#include"LoadSprites.h"

#define max_Column 5

class CAstroid {

public:

	CAstroid(CSprite *pSpriteAstroid, float fPos_x, float fPos_y);
	void Update();
	void Render();
	bool IsAlive() { return m_bIsAlive; };

private:
	void Animation();

	int m_Column;

	CSprite *m_pSpriteAstroid;
	float m_fPos_x;
	float m_fPos_y;
	float m_fAnimationPhase;
	bool m_bIsAlive;
	SDL_Rect m_Rect;

	float m_fMoveSpeed = 300.0;

};