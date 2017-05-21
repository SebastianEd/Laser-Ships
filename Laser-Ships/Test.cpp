#include "Test.h"

CTest::CTest() {

	bla = nullptr;
	bla = new int;
	*bla = 10;

	std::cout << "Variable von bla: " << *bla << std::endl;
}


CTest::~CTest() {

	if (bla != nullptr) {
	
		bla = nullptr;
	}

	std::cout << "Destruktor von Test wurde aufgerufen\n";

}