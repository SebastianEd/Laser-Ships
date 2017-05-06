#include "Framework.h"
#include <iostream>

int main(int argc, char **argv) {

	CFramework window;

	window.Init(800, 600, false);

	while (!window.isClosed()) {
		window.pollEvents();
	}



	return 0;	
}