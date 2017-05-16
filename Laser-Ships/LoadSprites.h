#pragma once

#include "Framework.h"

class CSprite : public CFramework {

public:

	CSprite(const CFramework &framework, int w, int h, int x, int y, int r, int g, int b, int a);		//Creating a colored Rect
	CSprite(const CFramework &framework, int w, int h, int x, int y, const std::string &image_path);	//Create Picture; Formats: JPG, PNG
	~CSprite();

	void drawWithoutAnimation() const;
	void drawWithAnimation(int m_RectPosition_x, int m_RectPosition_y, int FrameWidth, int FrameHeight);
	void setSpritePosition(int Pos_x, int Pos_y);


private:
	int _w, _h;
	int _x, _y;
	int _r, _g, _b, _a;
	SDL_Texture *m_pTexture = nullptr;

	int m_SpritePosition_x = 0;
	int m_SpritePosition_y = 0;

	SDL_Rect m_AnimationRect;
	SDL_Rect m_rectPosition;



};
