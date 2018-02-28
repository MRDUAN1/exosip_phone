#ifndef _AUDIOPLAY_H_
#define _AUDIOPLAY_H_

#include "WaveOut.h"



class CAudioPlay:public CWaveOut
{
public:
	BOOL Destroy();
	virtual  ~CAudioPlay();
	BOOL Create(WAVEFORMATEX *pwf,DWORD dwCallBack,DWORD dwInst,DWORD fdwOpen );
	BOOL Play(char* buf,UINT uSize);
	CAudioPlay();
	friend void CALLBACK waveOutProc(HWAVEOUT hwo,UINT uMsg,DWORD dwInstance,DWORD dwParam1,DWORD dwParam2);
protected:

};



#endif