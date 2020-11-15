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
	system("mode 61,26");

	char motto[100] = "\1 Encourage One Another To Improve Our Full Potential \1";
	setColor(C_RED);
	printf("\n"); Sleep(50);          
	printf("                      ###############\n"); Sleep(50);         
	printf("               #######################\n"); Sleep(50);         
	printf("          ###########################\n"); Sleep(50);         
	printf("         ###########         ####\n"); Sleep(50);         
	printf("        ######\n"); Sleep(50);         
	printf("        #####"); 
	setColor(C_AQUA); 
	printf("     ((   ((((((((((((\n"); Sleep(50);
	setColor(C_RED);         
	printf("        #############");
	setColor(C_AQUA);
	printf("(((((((((((((((          (((((       ((\n"); Sleep(50);         
	printf("            ((("); 
	setColor(C_RED); 
	printf("##############"); 
	setColor(C_AQUA); 
	printf("(((((((        (((((((     ((((\n"); Sleep(50);         
	printf("           (((((((((((    "); 
	setColor(C_RED); 
	printf("######"); 
	setColor(C_AQUA); 
	printf("((((      (((((((.     (((((\n"); Sleep(50);  
	printf("           (((((            "); 
	setColor(C_RED); 
	printf("#####"); 
	setColor(C_AQUA); 
	printf("(     .((((((((       (((( \n"); Sleep(50);         
	setColor(C_RED);
	printf("                        ########"); 
	setColor(C_AQUA); 
	printf("     (((((((((       (((((\n"); Sleep(50); 
	setColor(C_RED);        
	printf("  #############################");
	setColor(C_AQUA);
	printf("    (((((((((.       (((((\n"); Sleep(50); 
	setColor(C_RED);                
	printf(" ##########################");
	setColor(C_AQUA);
	printf("(    (((((((((((       (((((\n"); Sleep(50);  
	setColor(C_RED);                       
	printf("  ##################");
	setColor(C_AQUA);
	printf("((((((    ((((( (((((       ((((((\n"); Sleep(50);         
	printf("                  ((((((   ((((((  (((((      ((((((\n"); Sleep(50);         
	printf("                ((((((  ((((((     ((((    (((((((\n"); Sleep(50);         
	printf("               (((((((((((((      ((((((((((((((\n"); Sleep(50);         
	printf("                (((((((((          ((((((((((\n"); Sleep(50);         
	printf("                  ((((               ((((\n"); Sleep(50);      
	printf("\n"); Sleep(50);
	setColor(C_WHITE);
	printf("\n                SW16-2 ## Kevin Surya Wahyudi\n"); Sleep(50);
	printf("\n   "); Sleep(50);
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
		setColor(C_WHITE);
		gotoxy({ 89, 4 });
		printf("%c", 201);
		for (int i = 0; i < 25; i++)
		{
			printf("%c", 205);
		}
		printf("%c", 187);
		gotoxy({ 89, 5 });
		printf("%c SUDUT and Precious Star %c", 186, 186);
		gotoxy({ 89, 6 });
		printf("%c", 200);
		for (int i = 0; i < 25; i++)
		{
			printf("%c", 205);
		}
		printf("%c", 188);
		gotoxy({ 85, 9 });
		printf("1. Play Game\n");
		gotoxy({ 85, 10 });
		printf("2. Build Map\n");
		gotoxy({ 85, 11 });
		printf("3. Default Map\n");
		gotoxy({ 85, 12 });
		printf("4. Game Setting\n");
		gotoxy({ 85, 13 });
		printf("5. Exit ");
		gotoxy({ 85, 14 });
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
