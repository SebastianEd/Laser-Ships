#pragma once

#include "Framework.h"
#include "LoadSprites.h"
#include "Player.h"
#include "Sound.h"
#include "Astroid.h"
#include <list>

class Game{

public:
	
	Game();
	void Init();
	void Run();
	
	//Astroids
	void spawnAstroids();
	void renderAstroids();
	void checkCollision();

private:	

	CFramework *m_pWindow;

	//Player
	CPlayer *m_pPlayer;

	//Background Image
	CSprite *m_pBackground;
	SDL_Rect m_BackgroundRect;

	//Background Music (BGM)
	CSound *m_pBGM;

	//Astroids
	CSprite *m_pSpriteAstroid;
	float m_fTimerAstroid;
	std::list<CAstroid> m_AstroidList;
	std::list<CLaser> *m_LaserList;
};