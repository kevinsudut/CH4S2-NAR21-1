#pragma once
#include "cConsole.h"
#include "cNode.h"
#include "cScene.h"
#include "cSetting.h"

struct Track
{
	COORD c;
	Track* parent, * next;
};

class cPlay : public cConsole
{
private:
	Track* head, * tail, * bHead;
	COORD player;
	int star;
	cNode map[Y_MAX][X_MAX];
	cScene* scene;
	cSetting* setting;
public:
	cPlay();
	cPlay(cScene* scene, cSetting* setting);
	~cPlay();
	
	Track* createTrack(COORD c)
	{
		Track* temp = (Track*)malloc(sizeof(Track));
		temp->c = c;
		temp->next = NULL;
	}
	
	void pushTrack(COORD c, Track* curr)
	{
		Track* temp = createTrack(c);
		if (!head)
		{
			head = tail = temp;
			head->parent = curr;
		}
		else
		{
			tail->next = temp;
			tail = temp;
			tail->parent = curr;
		}
	}
	
	void pushBackTrack(COORD c)
	{
		Track* temp = createTrack(c);
		if (!bHead)
		{
			bHead = temp;
		}
		else
		{
			temp->next = bHead;
			bHead = temp;
		}
	}
	
	void popTrack()
	{
		while (head)
		{
			Track* curr = head;
			head = head->next;
			free(curr);
		}
	}
	
	void popBackTrack()
	{
		while (bHead)
		{
			Track* curr = bHead;
			bHead = bHead->next;
			free(curr);
		}
	}
	
	void initialize();
	void show();
	void generate();
	void run();
	void catchStar();
	bool openPath(Track* curr);
};
