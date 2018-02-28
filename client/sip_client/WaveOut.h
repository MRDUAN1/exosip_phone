#ifndef _WAVEOUT_H_
#define _WAVEOUT_H_
#include "БъЭЗ.h"
void waveOutErrorMsg(MMRESULT mmr,char* szTitle);

class CWaveOut
{
public:
	BOOL CloseDev();
	void SetLastMMError(MMRESULT mmr);
	MMRESULT GetLastMMError();
	
	virtual  ~CWaveOut();

	CWaveOut();
	
	BOOL OpenDev(WAVEFORMATEX* pfmt,DWORD dwCallback,DWORD dwCallbackInstance,DWORD fdwOpen);
	operator HWAVEOUT() const;
protected:

	MMRESULT m_mmr;

	HWAVEOUT m_hOut;

	
};


#endif