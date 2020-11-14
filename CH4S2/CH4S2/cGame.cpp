#include "Global.h"
#include "cGame.h"

cGame::cGame()
{
	scene = new cScene();
	setting = new cSetting();
}

cGame::~cGame()
{
	delete scene;
	delete setting;

	system("cls");
	system("mode 80,25");

	char motto[100] = "\1 Encourage One Another To Improve Our Full Potential \1";
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
	scene->load();
}

void cGame::run()
{
	int choose = 0;
	while (choose != 5)
	{
		system("cls");
		scene->show();
		printf("\n");
		gotoxy({ 85, 5 });
		printf("1. Play Game\n");
		gotoxy({ 85, 6 });
		printf("2. Build Map\n");
		gotoxy({ 85, 7 });
		printf("3. Default Map\n");
		gotoxy({ 85, 8 });
		printf("4. Game Setting\n");
		gotoxy({ 85, 9 });
		printf("5. Exit ");
		gotoxy({ 85, 10 });
		printf(">> ");
		scanf("%d", &choose);
		getchar();
		switch (choose)
		{
		case 1:
			play = new cPlay(scene, setting);
			play->initialize();
			play->run();
			delete play;
			break;
		case 2:
			build = new cBuildMap(scene, setting);
			build->initialize();
			build->run();
			delete build;
			break;
		case 3:
			scene->load();
			break;
		case 4:
			setting->run();
			break;
		}
	}
}
