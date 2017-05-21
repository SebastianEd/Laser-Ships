#include "Player.h"

//Constructor
//
CPlayer::CPlayer(const CFramework &framework, int Column, int Row, int FrameWidth, int FrameHeight) :
	CFramework(framework), m_FrameWidth(FrameWidth), m_FrameHeight(FrameHeight), m_Column(Column), m_Row(Row), m_fAnimationPhase(static_cast<float>(Column))
{

	m_pPlayer = new CSprite(framework, FrameWidth, FrameHeight,  "resources/SpaceShip.png");
	m_pLaser = new CSprite(framework, 0, 0, "resources/LaserAnimated3.png");


	keyState = SDL_GetKeyboardState(NULL);

}//Constructor




//Destructor
//
CPlayer::~CPlayer() {

	if (m_pPlayer != nullptr) {
		delete (m_pPlayer);
		m_pPlayer = nullptr;
	}

	if (m_pLaser != nullptr) {
		delete (m_pLaser);
		m_pLaser = nullptr;
	}

}//Destructor




//PlayerUpdate
//
//Updates player functions like moving, shooting and rendering
//
void CPlayer::PlayerUpdate() {
	PlayerMoving();
	PlayerShooting();
	PlayerRender();

}//PlayerUpdate




//PlayerRender
//
void CPlayer::PlayerRender() {

	//Renders Shots
	//
	std::list<CLaser>::iterator it = m_LaserList.begin();

	while (it != m_LaserList.end()) {

		it->Update();

		if (it->isAlive()) {

			it->Render();
			it++;
		}
		else {
			it->freeResources();
			it = m_LaserList.erase(it);
		}

	}//Render Shots 
	
	m_RectPosition_x = m_FrameWidth * (m_Column - 1);
	m_RectPosition_y = m_FrameHeight * (m_Row - 1);

	m_pPlayer->drawWithAnimation(m_RectPosition_x, m_RectPosition_y);


}//PlayerRender




//SetPlayerPosition
//
void CPlayer::PlayerPostion(float fPos_x, float fPos_y) {

	m_fPlayerPostion_x = fPos_x;
	m_fPlayerPostion_y = fPos_y;

	m_pPlayer->setSpritePosition(m_fPlayerPostion_x, m_fPlayerPostion_y);

}//PlayerPosition




//PlayerAnimation()
//
void CPlayer::PlayerAnimation() {
	
	if (m_fAnimationPhase >= max_ColumnPlayer + 1) {
		m_fAnimationPhase = m_fAnimationPhase - max_ColumnPlayer;
	}

	if (m_Column >= max_ColumnPlayer + 1) {
		m_Column = 1;
	}
	else {

		m_Column = static_cast<int>(m_fAnimationPhase);
		m_fAnimationPhase += 15 * g_pTimer->GetElapsed();

	}

}//PlayerAnimation




//PlayerMoving
//
void CPlayer::PlayerMoving() {

	PlayerCheckPosition(1080, 720);




	//Pressing Right Key
	//Move Right Direction
	if (keyState[SDL_SCANCODE_RIGHT]){
		
		//m_Row = 3;
		m_LineOfSight = 'r';

		m_Column = 5;

		m_fPlayerPostion_x += (m_fMoveSpeed * g_pTimer->GetElapsed());
		//PlayerAnimation();
		m_pPlayer->setSpritePosition(m_fPlayerPostion_x, m_fPlayerPostion_y);
	
	}//Pressing Right Key




	//Pressing Left Key
	//Move Left Direction
	if (keyState[SDL_SCANCODE_LEFT]) {
		m_fPlayerPostion_x -= m_fMoveSpeed * g_pTimer->GetElapsed();
		//m_Row = 2;
		m_LineOfSight = 'l';

		m_Column = 2;
		//PlayerAnimation();

		m_pPlayer->setSpritePosition(m_fPlayerPostion_x, m_fPlayerPostion_y);
	
	}//Pressing Left Key




	//Pressing Up Key
	//Move Up Direction
	if (keyState[SDL_SCANCODE_UP]) {
		m_fPlayerPostion_y -= m_fMoveSpeed *  g_pTimer->GetElapsed();

		//PlayerAnimation();

		if (m_LineOfSight == 'r') {
			m_Column = 4;
		}
		else {
			m_Column = 3;
		}

		m_pPlayer->setSpritePosition(m_fPlayerPostion_x, m_fPlayerPostion_y);
	
	}//Pressing Up Key




	//Pressing Down Key
	//Move Down Direction
	if (keyState[SDL_SCANCODE_DOWN]) {
		m_fPlayerPostion_y += m_fMoveSpeed *  g_pTimer->GetElapsed();

		if (m_LineOfSight == 'r') {
			m_Column = 6;
		}
		else {
			m_Column = 1;
		}

		//PlayerAnimation();

		m_pPlayer->setSpritePosition(m_fPlayerPostion_x, m_fPlayerPostion_y);
	
	}//Pressing Down Key



	//Set Sprite back to normal AnimationRect Position
	//
	if ( !(keyState[SDL_SCANCODE_UP] || keyState [SDL_SCANCODE_DOWN]) ) {
		switch (m_LineOfSight) {
		case 'r':
			m_Column = 5;
			break;

		case 'l':
			m_Column = 2;
			break;
		}
	}//Set Sprite to normal Pos


}//PlayerMoving




//PlayerCheckPosition
//
//Checks if Player is out of Screen
//
void CPlayer::PlayerCheckPosition(int ScreenWidht, int ScreenHeight) {

	//Checks left and right borders
	if (m_fPlayerPostion_x < 0.0f) {
		m_fPlayerPostion_x = 0.0f;
	}
	else if (m_fPlayerPostion_x > (ScreenWidht - m_FrameWidth)) {
		m_fPlayerPostion_x = static_cast<float>(ScreenWidht - m_FrameWidth);
	}

	//Checks top and bottom borders
	if (m_fPlayerPostion_y < 0) {
		m_fPlayerPostion_y = 0.0f;
	}
	else if (m_fPlayerPostion_y > (ScreenHeight - m_FrameHeight)) {
		m_fPlayerPostion_y = static_cast<float>(ScreenHeight - m_FrameHeight);
	}

}//PlayerCheckPosition




//PlayerShooting
//
void CPlayer::PlayerShooting() {

	if (keyState[SDL_SCANCODE_SPACE] && (m_bShotLock == false)) {

		if (m_LineOfSight == 'r') {
			m_fLaserPosition_x = m_fPlayerPostion_x + (m_FrameWidth);
			m_fLaserPosition_y = m_fPlayerPostion_y - 5;
		}
		else {
			m_fLaserPosition_x = m_fPlayerPostion_x - 15;
			m_fLaserPosition_y = m_fPlayerPostion_y - 5;
		}

		CLaser Laser(m_pLaser,  m_fLaserPosition_x, m_fLaserPosition_y);
	

		if (m_LineOfSight == 'l') {
			Laser.setDirection('l');
		}
		else if (m_LineOfSight == 'r'){
			Laser.setDirection('r');
		}

		m_LaserList.push_back(Laser);
		m_bShotLock = true;
		
	}

	if (!keyState[SDL_SCANCODE_SPACE]) {
		m_bShotLock = false;
	}

}