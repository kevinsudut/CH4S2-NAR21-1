// CH4S2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Global.h"
#include "cGame.h"

void console()
{
	system("mode 128,24");

	SetConsoleTitleA("SUDUT and Precious Stars - CH4S2 by SW16-2");

	RECT desktop;
	GetWindowRect(GetDesktopWindow(), &desktop);
	SetWindowPos(GetConsoleWindow(), 0, desktop.right / 4, desktop.bottom / 4, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
}

int main()
{
	console();
	srand(time(NULL));
	cGame* game = new cGame();
	game->initialize();
	game->run();
	delete game;
	getchar();
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
