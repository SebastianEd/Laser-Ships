#include "Laser.h"



//Constructor
//
CLaser::CLaser(CSprite *pShotSprite, float fPos_x, float fPos_y) :
	m_pShotSprite(pShotSprite), m_fPos_x(fPos_x), m_fPos_y(fPos_y){

	m_Rect.x = static_cast<int>(fPos_x);
	m_Rect.y = static_cast<int>(fPos_y);

	setFrameSize();

	m_bIsAlive = true;

}//Constructor

void CLaser::setDirection(char Direction){
	m_look_direction = Direction;
}

//Update
//
//Moves Shot
//
void CLaser::Update() {

	if (m_fAnimationPhase >= max_Row) {
		m_fAnimationPhase = m_fAnimationPhase - max_Row;
	}

	if (m_Row >= max_Row) {
		m_Row = 1;
	}
	else {

		m_Row = static_cast<int>(m_fAnimationPhase);
		m_fAnimationPhase += 150 * g_pTimer->GetElapsed();

	}


	
	if(m_look_direction == 'l'){
		m_fPos_x -= m_fMoveSpeed * g_pTimer->GetElapsed();
		m_Rect.x = static_cast<int>(m_fPos_x);
	
		if (m_fPos_x < 0.0f) {
			m_bIsAlive = false;
		}
	}

	if (m_look_direction == 'r') {
		m_fPos_x += m_fMoveSpeed * g_pTimer->GetElapsed();
		m_Rect.x = static_cast<int>(m_fPos_x);

		if (m_fPos_x > 1080.0f) {
			m_bIsAlive = false;
		}

		m_pShotSprite->setSpritePosition(m_fPos_x, m_fPos_y);
	}
}//Update


//Render Shot
//
void CLaser::Render(int x, int y) {
	if (m_bIsAlive == true) {

		m_Rect.x = m_fPos_x + x;
		m_Rect.y = m_fPos_y + y;
		
		m_pShotSprite->drawWithoutAnimation(m_Rect);
	}
}//Render



