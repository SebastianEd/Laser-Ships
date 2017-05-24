#include "Astroid.h"

CAstroid::CAstroid(CSprite *pSpriteAstroid, float fPos_x, float fPos_y) {

	m_pSpriteAstroid = pSpriteAstroid;
	m_fPos_x = fPos_x;
	m_fPos_y = fPos_y;

	m_fAnimationPhase = 0.0f;

	m_Rect.x = static_cast<int>(fPos_x);
	m_Rect.y = static_cast<int>(fPos_y);
	m_Rect.w = 25;
	m_Rect.h = 20;

	m_bIsAlive = true;
}

void CAstroid::Animation() {

	//Handles the columns
	if (m_fAnimationPhase >= max_ColumnAstroid) {
		m_fAnimationPhase = m_fAnimationPhase - max_ColumnAstroid;
	}

	if (m_Column >= max_ColumnAstroid) {
		m_Column = 1;
	}
	else {

		m_Column = static_cast<int>(m_fAnimationPhase);
		m_fAnimationPhase += 200 * g_pTimer->GetElapsed();
	}

}

void CAstroid::Update() {

	Animation();

	m_fPos_x -= m_fMoveSpeed * g_pTimer->GetElapsed();
	m_Rect.x = static_cast<int>(m_fPos_x);
	if (m_fPos_x < - 50.0f) {
		m_bIsAlive = false;
	}
	m_pSpriteAstroid->setSpritePosition(m_fPos_x, m_fPos_y);

}

void CAstroid::Render() {

	if (m_bIsAlive == true) {

		m_Rect_x = 25 * m_Column;
		m_Rect.y = static_cast<int>(m_fPos_y);
		m_Rect.x = static_cast<int>(m_fPos_x);

		m_pSpriteAstroid->drawWithAnimation(m_Rect_x, 0);
	}
}