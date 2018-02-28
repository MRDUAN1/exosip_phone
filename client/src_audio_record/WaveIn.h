// WaveIn.h: interface for the CWaveIn class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_WAVEIN_H__E76B9871_60AB_44A9_A64E_56C1E46A3237__INCLUDED_)
#define AFX_WAVEIN_H__E76B9871_60AB_44A9_A64E_56C1E46A3237__INCLUDED_
#include "БъЭЗ.h"
#pragma comment(lib,"Winmm")

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CWaveIn  
{
public:
	CWaveIn();
	virtual ~CWaveIn();
	BOOL CloseDev();
	void SetLastMMError(MMRESULT mmr);
	MMRESULT GetLastMMError();

	BOOL OpenDev(WAVEFORMATEX* pfmt,DWORD dwCallback,DWORD dwCallbackInstance,DWORD fdwOpen);
	operator HWAVEIN() const;
protected:

	MMRESULT m_mmr;
	
	HWAVEIN m_hIn;

};

#endif // !defined(AFX_WAVEIN_H__E76B9871_60AB_44A9_A64E_56C1E46A3237__INCLUDED_)
