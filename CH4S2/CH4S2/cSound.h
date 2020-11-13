#pragma once

class cSound
{
private:
	bool isPlay = false;
public:
	cSound();
	~cSound();
	bool getIsPlay();
	char* getStatus();
	void play();
	void stop();
};
