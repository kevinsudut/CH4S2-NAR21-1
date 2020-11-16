#include "Global.h"
#include "cScene.h"

cScene::cScene()
{
}

cScene::~cScene()
{
}

cNode cScene::getNode(int x, int y)
{
	return map[y][x];
}

void cScene::load()
{
	FILE* file = fopen("map.sw", "r");
	if (file)
	{
		int index = 0;
		char t_map[Y_MAX][X_MAX];
		while (!feof(file))
		{
			fscanf(file, "%[^\n]\n", t_map[index++]);
		}
		for (int i = 0; i < Y_MAX; i++)
		{
			for (int j = 0; j < X_MAX; j++)
			{
				if (t_map[i][j] == FLOOR)
				{
					map[i][j] = cNode(t_map[i][j], false);	
				}
				else if (t_map[i][j] == WALL)
				{
					map[i][j] = cNode(t_map[i][j], true);
				}
			}
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
			switch (map[i][j].getStatus())
			{
			case FLOOR:
				setColor(C_WHITE);
				printf(" ");
				break;
			case WALL:
				setColor(C_GREEN);
				printf("%c", 178);
				break;
			}
		}
		printf("\n");
	}
}

void cScene::set(cNode map[Y_MAX][X_MAX])
{
	for (int i = 0; i < Y_MAX; i++)
	{
		for (int j = 0; j < X_MAX; j++)
		{
			this->map[i][j] = map[i][j];
		}
	}
}
