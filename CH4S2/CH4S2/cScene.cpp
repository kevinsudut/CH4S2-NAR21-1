#include "Global.h"
#include "cScene.h"

cScene::cScene()
{
}

cScene::~cScene()
{
}

void cScene::load()
{
	FILE* file = fopen("map.sw", "r");
	if (file)
	{
		int index = 0;
		while (!feof(file))
		{
			fscanf(file, "%[^\n]\n", map[index++]);
		}
		fclose(file);
		return;
	}

	printf("Failed load map\n");
	exit(1);
}

void cScene::show()
{
	for (int i = 0; i < Y_MAX; i++)
	{
		for (int j = 0; j < X_MAX; j++)
		{
			switch (map[i][j])
			{
			case FLOOR:
				printf(" ");
				break;
			case WALL:
				printf("%c", 178);
				break;
			}
		}
		printf("\n");
	}
}
