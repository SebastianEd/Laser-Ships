#pragma once

#include "Framework.h"

class CSprite : public CFramework {

public:

	//Create Picture; Formats: JPG, PNG
	CSprite(const CFramework &framework, int FrameWidth, int FrameHeight, const std::string &image_path);	
	~CSprite();

	//Param: Rect of the whole Texture
	void drawWithoutAnimation(SDL_Rect rect);

	//Params: Position of the Rect which crops the right frame from a texture
	void drawWithAnimation(int m_RectPosition_x, int m_RectPosition_y);

	//sets Position of the Sprite on the screen
	void setSpritePosition(float Pos_x, float Pos_y);

	//the function helps you to set the frame size of a texture.
	void configFrameSize(int FrameHeight, int FrameWidth);

private:

	SDL_Texture *m_pTexture = nullptr;

	int m_textureWidth;
	int m_FrameWidth;
	int m_FrameHeight;
	float m_fFrameCounter;

	int m_SpritePosition_x = 0;
	int m_SpritePosition_y = 0;

	SDL_Rect m_cropRect;
	SDL_Rect m_PositionRect;



};
