#include "Global.h"
#include "cSound.h"

cSound::cSound()
{
}

cSound::~cSound()
{
}

bool cSound::getIsPlay()
{
	return isPlay;
}

char* cSound::getStatus()
{
	char* status = new char;
	strcpy(status, isPlay ? "Play" : "Stop");
	return status;
}

void cSound::play()
{
	PlaySound(TEXT("nar.wav"), NULL, SND_LOOP | SND_FILENAME | SND_ASYNC);
	isPlay = true;
}

void cSound::stop()
{
	PlaySound(NULL, NULL, NULL);
	isPlay = false;
}
