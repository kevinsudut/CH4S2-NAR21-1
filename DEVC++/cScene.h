#pragma once

#include "cConsole.h"
#include "cNode.h"

#define X_MAX 80
#define Y_MAX 23
#define FLOOR '0'
#define WALL '1'
#define PLAYER '2'
#define STAR '3'
#define OPEN_PATH '4'
#define PATH '5'

class cScene : public cConsole
{
private:
	cNode map[Y_MAX][X_MAX];
public:
	cScene();
	~cScene();
	cNode getNode(int x, int y);
	void load();
	void show();
	void set(cNode map[Y_MAX][X_MAX]);
};
