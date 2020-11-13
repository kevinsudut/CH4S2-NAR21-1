#pragma once

class cSound
{
private:
	bool isPlay = false;
public:
	cSound();
	~cSound();
	bool getIsPlay()
	{
		return isPlay;
	}
	void play();
	void stop();
};
