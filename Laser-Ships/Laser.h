#pragma once

#include "LoadSprites.h"
#include "Framework.h"
#include "Sound.h"
#include "Astroid.h"

#define max_ColumnLaser			6		//set 1 if you've got no sprite sheet for animations, but a single sprite
#define LaserFrameWidth		20		//set frame width of the lasers sprite
#define LaserFrameHeight	25		//set frame height of the lasers sprite

class CLaser {
public:

	CLaser(CSprite *pShotSprite, float fPos_x, float fPos_y);
	~CLaser();

	void freeResources();						//This is needed because there's a bug where the destructor is called too early
												//Please let me know if you found the issue <3
	void setDirection(char direction);	
	void Update();
	void Render();
	bool isAlive() { return m_bIsAlive; };
	SDL_Rect getRect() { return m_Rect; };
	void setIsAlive(bool set) { m_bIsAlive = set; }

private:

	void Animation();

	CSprite *m_pShotSprite = nullptr;		//Pointer to the lasers sprite
	CSound *m_pSound = nullptr;				//Pointer for the lasers sound - is played in the constructor


	bool m_bIsAlive;						//Checks if the Laser is alive
	char m_LineOfSight;						//Line of sight of the gunner

	int m_Column;							//Current column of the texture
	float m_fAnimationPhase = 0.0f;			//Calculates the animation phase

	float m_fMoveSpeed = 700.0f;			//The speed the laser is shot with


	float m_fPos_x, m_fPos_y;
	int m_Rect_x;
	SDL_Rect m_Rect;

};

