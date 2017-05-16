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

	m_PlayerPostion_x = fPos_x;
	m_PlayerPostion_y = fPos_y;

	m_pPlayer->setSpritePosition(m_PlayerPostion_x, m_PlayerPostion_y);

}//PlayerPosition


void CPlayer::PlayerAnimation() {
	
	if (m_fAnimationPhase >= 5.0f) {
		m_fAnimationPhase = m_fAnimationPhase - 4.0f;
	}

	if (m_Column >= 5) {
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

	if (keyState[SDL_SCANCODE_RIGHT]){
		
		m_PlayerPostion_x += (m_fMoveSpeed * g_pTimer->GetElapsed());
		m_Row = 3;

		PlayerAnimation();

		m_pPlayer->setSpritePosition(static_cast<int>(m_PlayerPostion_x), static_cast<int>(m_PlayerPostion_y));
	}

	if (keyState[SDL_SCANCODE_LEFT]) {
		m_PlayerPostion_x -= m_fMoveSpeed * g_pTimer->GetElapsed();
		m_Row = 2;

		PlayerAnimation();

		m_pPlayer->setSpritePosition(m_PlayerPostion_x, m_PlayerPostion_y);
	}

	if (keyState[SDL_SCANCODE_UP]) {
		m_PlayerPostion_y -= m_fMoveSpeed *  g_pTimer->GetElapsed();
		m_Row = 4;

		PlayerAnimation();

		m_pPlayer->setSpritePosition(m_PlayerPostion_x, m_PlayerPostion_y);
	}

	if (keyState[SDL_SCANCODE_DOWN]) {
		m_PlayerPostion_y += m_fMoveSpeed *  g_pTimer->GetElapsed();
		m_Row = 1;

		PlayerAnimation();

		m_pPlayer->setSpritePosition(m_PlayerPostion_x, m_PlayerPostion_y);
	}

}//PlayerMoving
