#include "Game.h"

//Constructor
//
Game::Game() {
	m_pWindow = nullptr;
	m_pWindow = new CFramework(1080, 720, false);
}//Constructor




//Init
//
void Game::Init() {

	//Initialize pointer to nullptr
	m_pSpriteAstroid = nullptr;
	m_pPlayer = nullptr;
	m_pBackground = nullptr;
	m_pBGM = nullptr;

	//Initialize classes
	m_pPlayer = new CPlayer(*m_pWindow, 5, 1, 34, 18);

	//Initialize Background
	m_pBackground = new CSprite(*m_pWindow, 1920, 1200, "resources/background.jpg");
	m_BackgroundRect = { 0, 0, 1080, 720 };

	//Initialize Backgroundmusic
	m_pBGM = new CSound;

	//Initialize Sprites
	m_pSpriteAstroid = new CSprite(*m_pWindow, 25, 20, "resources/LaserAnimated3.png");
	
	//Play BGM
	m_pBGM->playBGM("resources/Numb.mp3");
	
	//set Player start Position
	m_pPlayer->PlayerPostion(300, 350);

	//reset Astroid spawn timer
	m_fTimerAstroid = 0.0f;

}//Init




//Run
//
void Game::Run() {

	while (!(m_pWindow->isClosed())) {

		m_pBackground->drawWithoutAnimation(m_BackgroundRect);
		m_pPlayer->PlayerUpdate();
		spawnAstroids();
		checkCollision();
		renderAstroids();
		m_pWindow->Update();
	}

	m_pBGM->CleanUp();

}//Run




//renderAstroids
//
void Game::renderAstroids() {

	std::list<CAstroid>::iterator it;

	for (it = m_AstroidList.begin(); it != m_AstroidList.end(); ++it) {
		it->Update();
		it->Render();
	}

}//renderAstroids


//spawnAstroids
//
void Game::spawnAstroids() {

	m_fTimerAstroid += g_pTimer->GetElapsed();

	if (m_fTimerAstroid >= 3.0) {

		int PosY = rand() %700;
		CAstroid Astroid(m_pSpriteAstroid, 1080.0f, static_cast<float>(PosY));
		m_AstroidList.push_back(Astroid);
		m_fTimerAstroid = 0.0f;
	}
}//spawnAstroids


void Game::checkCollision() {

	std::list<CLaser> *LaserList = m_pPlayer->getLaserList();

	std::list<CAstroid>::iterator ItAstroid = m_AstroidList.begin();
	std::list<CLaser>::iterator ItLaser;

	SDL_Rect RectAstroid;
	SDL_Rect RectLaser;

	while (ItAstroid != m_AstroidList.end()) {

		RectAstroid = ItAstroid->getRect();

		for (ItLaser = LaserList->begin(); ItLaser != LaserList->end(); ++ItLaser) {
			RectLaser = ItLaser->getRect();

			if ((RectLaser.x + RectLaser.w < RectAstroid.x) ||
				(RectLaser.x > RectAstroid.x + RectAstroid.w) ||
				(RectLaser.y + RectLaser.h < RectAstroid.y) ||
				(RectLaser.y > RectAstroid.y + RectLaser.h)) {

			}
			else{
				ItAstroid->setIsAlive(false);
				ItLaser->setIsAlive(false);
			}
		}

		if (ItAstroid->IsAlive())
			ItAstroid++;
		else
			ItAstroid = m_AstroidList.erase(ItAstroid);

	}//while Schleife


}