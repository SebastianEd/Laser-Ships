#include "Framework.h"
#include "LoadSprites.h"
#include "Player.h"

int main(int argc, char **argv) {

	CFramework window(1080, 720, false);
	CPlayer Player(window, 5, 1, 34, 18);

	//Renders Background
	CSprite Background(window, 1920, 1200, "resources/background.jpg");
	SDL_Rect bg{0, 0, 1080, 720};

	Player.PlayerPostion(492, 328);

	while (!window.isClosed()) {

		Background.drawWithoutAnimation(bg);
		Player.PlayerUpdate();
		window.Update();
	}



	return 0;	
}