#include "Framework.h"
#include "LoadSprites.h"
#include "Player.h"

int main(int argc, char **argv) {

	CFramework window(1080, 720, false);
	CPlayer Player(window, 1, 1, 32, 48);

	Player.PlayerPostion(492, 328);

	while (!window.isClosed()) {
	
		window.pollEvents();
		Player.PlayerUpdate();
		g_pTimer->Update();
		window.Clear();
	}



	return 0;	
}