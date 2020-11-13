#include "Global.h"
#include "cSound.h"

cSound::cSound()
{
}

cSound::~cSound()
{
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
