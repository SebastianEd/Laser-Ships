#include "LoadSprites.h"

//Construtor
//
//ConstructImage
//
CSprite::CSprite(const CFramework &framework, int FrameWidth, int FrameHeight, const std::string &image_path) :
	CFramework(framework)
{
	SDL_Surface  *surface = IMG_Load(image_path.c_str());
	if (!surface) {
		std::cerr << "Failed to create surface.\n";
	}

	m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, surface);
	if (!m_pTexture) {
		std::cerr << "Failed to create Texture.\n";
	}

	m_AnimationRect.w = FrameWidth;
	m_rectPosition.w = FrameWidth;
	m_AnimationRect.h = FrameHeight;
	m_rectPosition.h = FrameHeight;

	SDL_FreeSurface(surface);
}//ConstructImage


//Destructor
//
CSprite::~CSprite() {

	SDL_DestroyTexture(m_pTexture);

}//Destructor

//drawWithoutAnimation
//
void CSprite::drawWithoutAnimation(SDL_Rect rect) {

	m_rectPosition = rect;

	if (m_pTexture == nullptr) {
		std::cerr << "Couldn't find texture.\n";
	}
		SDL_RenderCopy(m_pRenderer, m_pTexture, nullptr, &rect);
	
}//drawWihtouAnimation


//drawWithAnimation
//
void CSprite::drawWithAnimation(int m_RectPosition_x, int m_RectPosition_y) {

		m_AnimationRect.x = m_RectPosition_x;
		m_AnimationRect.y = m_RectPosition_y;
		m_rectPosition.x = m_SpritePosition_x;
		m_rectPosition.y = m_SpritePosition_y;
		if (m_pTexture) {
			SDL_RenderCopy(m_pRenderer, m_pTexture, &m_AnimationRect, &m_rectPosition);

		}

}//drawWithAnimation

//setSpritePosition
//
//Sets the Position of the Sprite on the Screen
//
void CSprite::setSpritePosition(float Pos_x, float Pos_y) {

	m_SpritePosition_x = static_cast<int>(Pos_x);
	m_SpritePosition_y = static_cast<int>(Pos_y);

}//setSpritePosition

