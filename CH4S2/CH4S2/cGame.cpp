#include "Global.h"
#include "cGame.h"

cGame::cGame()
{
	sound = new cSound();
	scene = new cScene();
	setting = new cSetting(sound);
}

cGame::~cGame()
{
	delete sound;
	delete scene;
	delete setting;

	system("cls");
	char motto[100] = "\1 Encourage One Another To Improve Our Full Potential \1";
	puts(""); Sleep(50);
	puts(""); Sleep(50);
	puts("      $$$$$$$\\  $$\\                                             $$\\"); Sleep(50);
	puts("      $$  __$$\\ $$ |                                            $$ |"); Sleep(50);
	puts("      $$ |  $$ |$$ |$$\\   $$\\  $$$$$$\\  $$\\  $$$$$$\\   $$$$$$$\\ $$ |  $$\\"); Sleep(50);
	puts("      $$$$$$$\\ |$$ |$$ |  $$ |$$  __$$\\ \\__| \\____$$\\ $$  _____|$$ | $$  |"); Sleep(50);
	puts("      $$  __$$\\ $$ |$$ |  $$ |$$$$$$$$ |$$\\  $$$$$$$ |$$ /      $$$$$$  /"); Sleep(50);
	puts("      $$ |  $$ |$$ |$$ |  $$ |$$   ____|$$ |$$  __$$ |$$ |      $$  _$$<"); Sleep(50);
	puts("      $$$$$$$  |$$ |\\$$$$$$  |\\$$$$$$$\\ $$ |\\$$$$$$$ |\\$$$$$$$\\ $$ | \\$$\\"); Sleep(50);
	puts("      \\_______/ \\__| \\______/  \\_______|$$ | \\_______| \\_______|\\__|  \\__|"); Sleep(50);
	puts("                                  $$\\   $$ |"); Sleep(50);
	puts("                                  \\$$$$$$  |"); Sleep(50);
	puts("                                   \\______/"); Sleep(50);
	puts(""); Sleep(50);
	puts("                       $$\\   $$$$$$\\          $$$$$$\\"); Sleep(50);
	puts("                     $$$$ | $$  __$$\\        $$  __$$\\"); Sleep(50);
	puts("                     \\_$$ | $$ /  \\__|       \\__/  $$ |"); Sleep(50);
	puts("                       $$ | $$$$$$$\\ $$$$$$\\  $$$$$$  |"); Sleep(50);
	puts("                       $$ | $$  __$$\\\\______|$$  ____/"); Sleep(50);
	puts("                       $$ | $$ /  $$ |       $$ |"); Sleep(50);
	puts("                     $$$$$$\\ $$$$$$  |       $$$$$$$$\\"); Sleep(50);
	puts("                     \\______|\\______/        \\________|"); Sleep(50);
	puts(""); Sleep(50);
	puts(""); Sleep(50);
	printf("            ");
	for (int i = 0; i < strlen(motto); i++)
	{
		printf("%c", motto[i]); Sleep(50);
	}
}

void cGame::initialize()
{
	setColor(C_WHITE);
	sound->play();
	scene->load();
}

void cGame::run()
{
	int choose = 0;
	while (choose != 4)
	{
		clearScreen();
		printf("1. Play Game\n");
		printf("2. Build Map\n");
		printf("3. Game Setting\n");
		printf("4. Exit\n");
		printf(">> ");
		scanf("%d", &choose);
		getchar();
		switch (choose)
		{
		case 1:
			break;
		case 2:
			break;
		case 3:
			setting->run();
			break;
		}
	}
}
