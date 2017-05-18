#pragma once

#include "Framework.h"

class CSprite : public CFramework {

public:

	CSprite(const CFramework &framework, int FrameWidth, int FrameHeight, const std::string &image_path);	//Create Picture; Formats: JPG, PNG
	~CSprite();

	void drawWithoutAnimation(SDL_Rect rect);
	void drawWithAnimation(int m_RectPosition_x, int m_RectPosition_y);
	void setSpritePosition(float Pos_x, float Pos_y);

	SDL_Rect getRect() {return m_rectPosition;}

private:

	SDL_Texture *m_pTexture = nullptr;

	int m_SpritePosition_x = 0;
	int m_SpritePosition_y = 0;

	SDL_Rect m_AnimationRect;
	SDL_Rect m_rectPosition;



};
