#include "LoadSprites.h"

//Construtor
//
//ConstructImage
//
CSprite::CSprite(const CFramework &framework, int FrameWidth, int FrameHeight, const std::string &image_path) :
	CFramework(framework)
{

	//Load Texture
	SDL_Surface  *surface = IMG_Load(image_path.c_str());
	if (!surface) {
		std::cerr << "Failed to create surface.\n";
	}

	m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, surface);
	if (!m_pTexture) {
		std::cerr << "Failed to create Texture.\n";
	}//Load Texture

	//Set Width and Height of the Rects
	configFrameSize(FrameWidth, FrameHeight);

	SDL_FreeSurface(surface);

	std::cout << "Loaded Sprite\n";
}//ConstructImage




//Destructor
//
CSprite::~CSprite() {

	SDL_DestroyTexture(m_pTexture);

}//Destructor




//drawWithoutAnimation
//
//Parameter is the Rect of the Texture (x- and y-Coordinates of the Texture, Widht and Height of the whole Texture)
//
void CSprite::drawWithoutAnimation(SDL_Rect rect) {

	m_PositionRect = rect;

	if (m_pTexture == nullptr) {
		std::cerr << "Couldn't find texture.\n";
	}
		SDL_RenderCopy(m_pRenderer, m_pTexture, nullptr, &rect);
	
}//drawWihtouAnimation





//drawWithAnimation
//
//Parameters:	m_RectPosition_x is the x Position of the rect which crops the rect from the whole Texture
//				m_RectPosition_y is the y Position of the rect which crops the rect from the whole Texture
//
void CSprite::drawWithAnimation(int m_RectPosition_x, int m_RectPosition_y) {

		m_cropRect.x = m_RectPosition_x;
		m_cropRect.y = m_RectPosition_y;

		//m_SpritePosition_x can be set with the function of CSprite: setSpritePosition(float Pos_x, float Pos_y)
		//This is calculated if something moves its x and y position on the screen (e.g. Player mobing around)
		m_PositionRect.x = m_SpritePosition_x;
		m_PositionRect.y = m_SpritePosition_y;
		if (m_pTexture) {
			SDL_RenderCopy(m_pRenderer, m_pTexture, &m_cropRect, &m_PositionRect);

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




//configFrameSize
//
//the function helps you to set the frame size of a texture.
//it sets width and height of the cropRect and the PositionRect
//
void CSprite::configFrameSize(int FrameWidth, int FrameHeight) {

	m_cropRect.w = FrameWidth;
	m_PositionRect.w = FrameWidth;
	m_cropRect.h = FrameHeight;
	m_PositionRect.h = FrameHeight;

}//configFrameSize
