#include "Laser.h"

//Constructor
//
CLaser::CLaser(CSprite *pShotSprite, float fPos_x, float fPos_y) :
	m_pShotSprite(pShotSprite), m_fPos_x(fPos_x), m_fPos_y(fPos_y){

	m_pShotSprite->configFrameSize(LaserFrameWidth, LaserFrameHeight);

	m_Rect.x = static_cast<int>(fPos_x);
	m_Rect.y = static_cast<int>(fPos_y);

	m_bIsAlive = true;
	m_LineOfSight = 'r';	//Default line of sight

	
	m_pSound = nullptr;
	m_pSound = new CSound;
	m_pSound->playSoundEffect("resources/shot.wav");

	//std::cout << "CLaser Konstruktor aufgerufen\n";

}//Constructor




//Destructor
//
//Only used for debugging since yet.
//
CLaser::~CLaser() {

	//std::cout << "CLaser Destruktor aufgerufen\n";

}//Destructor




//freeResources
//
//Needed, because there's a bug (I assume within the CPlayer class) which calls the Destructor of CLaser too early 
//and when one time again, when it should be called.
//
void CLaser::freeResources() {

	if ((m_pSound != nullptr)) {
		delete(m_pSound);
		m_pSound = nullptr;
	}

}//freeResources




//setDirection
//
//sets the line of sight. Can be either a char 'r' or 'l'
//
void CLaser::setDirection(char Direction){
	
	if ((Direction != 'r') && (Direction != 'l')) {
		std::cerr << "Error: Direction of function 'setDirection' called from the class CLaser must be either 'r' or 'l'!\n";
	}
	else {
		m_LineOfSight = Direction;
	}

}//setDirection




//Animation
//
//Handles the AnimationPhase of the lasers sprite
//
void CLaser::Animation() {

	//Handles the columns
	if (m_fAnimationPhase >= max_Column) {
		m_fAnimationPhase = m_fAnimationPhase - max_Column;
	}

	if (m_Column >= max_Column) {
		m_Column = 1;
	}
	else {

		m_Column = static_cast<int>(m_fAnimationPhase);
		m_fAnimationPhase += 200 * g_pTimer->GetElapsed();
	}

}//Animation




//Update
//
//Moves laser
//
void CLaser::Update() {

	Animation();

	//Line of sight: LEFT
	if(m_LineOfSight == 'l'){
		m_fPos_x -= m_fMoveSpeed * g_pTimer->GetElapsed();
		m_Rect.x = static_cast<int>(m_fPos_x);
	
		if (m_fPos_x < 0.0f) {
			m_bIsAlive = false;
		}
		m_pShotSprite->setSpritePosition(m_fPos_x, m_fPos_y);
	}//Line of sight: LEFT


	 //Line of sight: RIGHT
	if (m_LineOfSight == 'r') {
		m_fPos_x += m_fMoveSpeed * g_pTimer->GetElapsed();
		m_Rect.x = static_cast<int>(m_fPos_x);

		if (m_fPos_x > 1080.0f) {
			m_bIsAlive = false;
		}
		m_pShotSprite->setSpritePosition(m_fPos_x, m_fPos_y);
	}//Line of sight: RIGHT
}//Update





//Render laser
//
void CLaser::Render() {
	if (m_bIsAlive == true) {

		m_Rect_x = 25 * m_Column;
		m_pShotSprite->drawWithAnimation(m_Rect_x, 0);
	}
}//Render



