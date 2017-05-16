#pragma once

#include "LoadSprites.h"
#include "Framework.h"


class CPlayer : public CFramework {

public:

	CPlayer(const CFramework &framework, int PlayerPostion_x, int PlayerPostion_y, int FrameWidth, int FrameHeight);
	
	void PlayerPostion(float fPos_x, float fPos_y);
	void PlayerRender();
	void PlayerMoving();


private:

	void PlayerAnimation();

	const Uint8 *keyState;

	CSprite *m_pPlayer = nullptr;

	//MoveSpeed and AnimationPhase
	float m_fMoveSpeed = 300.0f;
	float m_fAnimationPhase;

	//Widht and Height of the Texture
	//Rect Position is calculated by the Rows and Columns of the Animated Sprite
	int m_FrameWidth;
	int m_FrameHeight;
	int m_RectPosition_x;
	int m_RectPosition_y;

	//Position on the Screen
	float m_PlayerPostion_x = 0;
	float m_PlayerPostion_y = 0;

	//Column and Row of the Animation Sprite
	int m_Column;
	int m_Row;

};