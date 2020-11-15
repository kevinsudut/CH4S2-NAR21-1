#pragma once
#include "cConsole.h"
#include "cNode.h"
#include "cScene.h"
#include "cSetting.h"

class cBuildMap : public cConsole
{
private:
	cNode temp[Y_MAX][X_MAX];
	cScene* scene;
	cSetting* setting;
	int block;
public:
	cBuildMap();
	cBuildMap(cScene* scene, cSetting* setting);
	~cBuildMap();
	void initialize();
	void run();
	void showLegend();
	void showBlockStatus();
	void floodFill(int x, int y);
	bool validate();
	bool save();
	void fill(COORD c);
	void moveCursor(COORD &c);
};

