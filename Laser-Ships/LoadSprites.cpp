#include "LoadSprites.h"

//Construtor
//
//Construct Rect
//
CSprite::CSprite(const CFramework &framework, int w, int h, int x, int y, int r, int g, int b, int a) :
	CFramework(framework), _w(w), _h(h), _x(x), _y(y), _r(r), _g(g), _b(b), _a(a)
{

}//Construct Rect


//Construtor
//
//ConstructImage
//
CSprite::CSprite(const CFramework &framework, int w, int h, int x, int y, const std::string &image_path) :
	CFramework(framework), _w(w), _h(h), _x(x), _y(y)
{
	SDL_Surface  *surface = IMG_Load(image_path.c_str());
	if (!surface) {
		std::cerr << "Failed to create surface.\n";
	}

	m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, surface);
	if (!m_pTexture) {
		std::cerr << "Failed to create Texture.\n";
	}


	SDL_FreeSurface(surface);
}//ConstructImage


//Destructor
//
CSprite::~CSprite() {

	SDL_DestroyTexture(m_pTexture);

}//Destructor

//drawWithoutAnimation
//
void CSprite::drawWithoutAnimation() const {

	SDL_Rect rect = { _x, _y, _w, _h };

	if(m_pTexture){
		SDL_RenderCopy(m_pRenderer, m_pTexture, nullptr, &rect);
	}
	else{
	SDL_SetRenderDrawColor(m_pRenderer, _r, _g, _b, _a);
	SDL_RenderFillRect(m_pRenderer, &rect);
	}
}//drawWihtouAnimation


//drawWithAnimation
//
void CSprite::drawWithAnimation(int m_RectPosition_x, int m_RectPosition_y, int FrameWidth, int FrameHeight) {


		SDL_Rect rect = { _x, _y, _w, _h };
		m_AnimationRect = { m_RectPosition_x, m_RectPosition_y,  FrameWidth, FrameHeight};
		m_rectPosition = { m_SpritePosition_x, m_SpritePosition_y,  FrameWidth, FrameHeight};

		if (m_pTexture) {
			SDL_RenderCopy(m_pRenderer, m_pTexture, &m_AnimationRect, &m_rectPosition);

		}

}//drawWithAnimation

//setSpritePosition
//
//Sets the Position of the Sprite on the Screen
//
void CSprite::setSpritePosition(int Pos_x, int Pos_y) {

	m_SpritePosition_x = Pos_x;
	m_SpritePosition_y = Pos_y;

}//setSpritePosition

