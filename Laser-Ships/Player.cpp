#include "Player.h"

//Constructor
//
CPlayer::CPlayer(const CFramework &framework, int Column, int Row, int FrameWidth, int FrameHeight) :
	CFramework(framework), m_FrameWidth(FrameWidth), m_FrameHeight(FrameHeight), m_Column(Column), m_Row(Row), m_fAnimationPhase(Column)
{

	m_pPlayer = new CSprite(framework, 0, 0, 0, 0, "resources/NPC 02.png");

}//Constructor


//PlayerRender
//
void CPlayer::PlayerRender() {

	m_RectPosition_x = m_FrameWidth * (m_Column - 1);
	m_RectPosition_y = m_FrameHeight * (m_Row - 1);

	m_pPlayer->drawWithAnimation(m_RectPosition_x, m_RectPosition_y, m_FrameWidth, m_FrameHeight);

}//PlayerRender

//SetPlayerPosition
//
void CPlayer::PlayerPostion(float fPos_x, float fPos_y) {

	m_fPlayerPostion_x = fPos_x;
	m_fPlayerPostion_y = fPos_y;

	m_pPlayer->setSpritePosition(m_fPlayerPostion_x, m_fPlayerPostion_y);

}//PlayerPosition


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

}

//PlayerMoving
//
void CPlayer::PlayerMoving() {

	keyState = SDL_GetKeyboardState(NULL);

	PlayerCheckPosition(1080, 720);


	//Pressing Right Key
	//Move Right Direction
	if (keyState[SDL_SCANCODE_RIGHT]){
		
		m_Row = 3;
		m_fPlayerPostion_x += (m_fMoveSpeed * g_pTimer->GetElapsed());
		PlayerAnimation();
		m_pPlayer->setSpritePosition(static_cast<int>(m_fPlayerPostion_x), static_cast<int>(m_fPlayerPostion_y));
	}

	//Pressing Left Key
	//Move Left Direction
	if (keyState[SDL_SCANCODE_LEFT]) {
		m_fPlayerPostion_x -= m_fMoveSpeed * g_pTimer->GetElapsed();
		m_Row = 2;

		PlayerAnimation();

		m_pPlayer->setSpritePosition(m_fPlayerPostion_x, m_fPlayerPostion_y);
	}

	//Pressing Up Key
	//Move Up Direction
	if (keyState[SDL_SCANCODE_UP]) {
		m_fPlayerPostion_y -= m_fMoveSpeed *  g_pTimer->GetElapsed();
		m_Row = 4;

		PlayerAnimation();

		m_pPlayer->setSpritePosition(m_fPlayerPostion_x, m_fPlayerPostion_y);
	}

	//Pressing Down Key
	//Move Down Direction
	if (keyState[SDL_SCANCODE_DOWN]) {
		m_fPlayerPostion_y += m_fMoveSpeed *  g_pTimer->GetElapsed();
		m_Row = 1;

		PlayerAnimation();

		m_pPlayer->setSpritePosition(m_fPlayerPostion_x, m_fPlayerPostion_y);
	}

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
		m_fPlayerPostion_x = (ScreenWidht - m_FrameWidth);
	}

	//Checks top and bottom borders
	if (m_fPlayerPostion_y < 0) {
		m_fPlayerPostion_y = 0.0f;
	}
	else if (m_fPlayerPostion_y > (ScreenHeight - m_FrameHeight)) {
		m_fPlayerPostion_y = (ScreenHeight - m_FrameHeight);
	}

}//PlayerCheckPosition