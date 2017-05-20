#pragma once

#include "LoadSprites.h"
#include "Framework.h"
#include "Laser.h"
#include <list>

#define max_ColumnPlayer 4		//Defines the Number of Columns of the Player Sprite


class CPlayer : public CFramework {

public:

	CPlayer(const CFramework &framework, int PlayerPostion_x, int PlayerPostion_y, int FrameWidth, int FrameHeight);
	~CPlayer();

	void PlayerPostion(float fPos_x, float fPos_y);
	void PlayerUpdate();


private:

	void PlayerRender();
	void PlayerMoving();
	void PlayerShooting();

	void PlayerCheckPosition(int ScreenWidht, int ScreenHeight);
	void PlayerAnimation();

	const Uint8 *keyState;
	CSprite *m_pPlayer = nullptr;
	CSprite *m_pLaser = nullptr;

	bool m_bShotLock;
	char m_LineOfSight = 'r';

	std::list<CLaser> m_LaserList;

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
	float m_fPlayerPostion_x = 0;
	float m_fPlayerPostion_y = 0;

	//Position where the Laser will be rendered
	float m_fLaserPosition_x;
	float m_fLaserPosition_y;

	//Column and Row of the Animation Sprite
	int m_Column;
	int m_Row;

};