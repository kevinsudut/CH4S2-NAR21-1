#pragma once

class cSound
{
private:
	bool isPlay;
public:
	cSound();
	~cSound();
	bool getIsPlay();
	char* getStatus();
	void play();
	void stop();
};
