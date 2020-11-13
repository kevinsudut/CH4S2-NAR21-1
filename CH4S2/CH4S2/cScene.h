#pragma once

#include "cConsole.h"

#define X_MAX 80
#define Y_MAX 23
#define FLOOR '0'
#define WALL '1'

class cScene : public cConsole
{
private:
	char map[Y_MAX][X_MAX];
public:
	cScene();
	~cScene();
	void load();
	void show();
};
