#pragma once

#include"LoadSprites.h"

#define max_ColumnAstroid 6

class CAstroid {

public:
	CAstroid(CSprite *pSpriteAstroid, float fPos_x, float fPos_y);
	void Update();
	void Render();
	bool IsAlive() { return m_bIsAlive; };
	void setIsAlive(bool set) { m_bIsAlive = set; };
	SDL_Rect getRect() { return m_Rect; };
	CAstroid getAstroid() { return *this; };

private:
	void Animation();

	int m_Column;

	CSprite *m_pSpriteAstroid;
	float m_fPos_x;
	float m_fPos_y;
	float m_fAnimationPhase;
	bool m_bIsAlive;

	int m_Rect_x;
	SDL_Rect m_Rect;

	float m_fMoveSpeed = 200.0;

};