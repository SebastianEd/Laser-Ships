#include "Framework.h"
#include "LoadSprites.h"
#include "Player.h"


#include <iostream>

int main(int argc, char **argv) {

	CFramework window(1080, 720, false);
	CSprite sprite(window, 120, 120, 100, 100, 200, 0, 200, 255);
	CPlayer Player(window, 3, 3, 32, 48);

	Player.PlayerPostion(50, 50);

	while (!window.isClosed()) {
		
		window.pollEvents();
		Player.PlayerMoving();
		Player.PlayerRender();
		
		//std::cout << g_pTimer->GetElapsed() << std::endl;
		g_pTimer->Update();

		window.Clear();
	}



	return 0;	
}