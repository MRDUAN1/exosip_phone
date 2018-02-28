// WaveIn.cpp: implementation of the CWaveIn class.
//
//////////////////////////////////////////////////////////////////////


//#include "netDlg.h"
#include "WaveIn.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

void waveInErrorMsg(MMRESULT mmr,char* szTitle)
{
	WCHAR wszClassName[256];
	memset(wszClassName, 0, sizeof(wszClassName));
	MultiByteToWideChar(CP_ACP, 0, szTitle, strlen(szTitle) + 1, wszClassName,
		sizeof(wszClassName) / sizeof(wszClassName[0]));
	WCHAR txt[MAXERRORLENGTH];
	waveInGetErrorText(mmr,txt,MAXERRORLENGTH);
	MessageBox(0, txt, wszClassName, MB_OK | MB_ICONWARNING);
}

CWaveIn::CWaveIn()
{
	m_mmr=0;
	
	m_hIn=0;	
}

BOOL CWaveIn::OpenDev(WAVEFORMATEX* pfmt,DWORD dwCallback,DWORD dwCallbackInstance,DWORD fdwOpen)
{
	BOOL bRet=FALSE;
	WAVEFORMATEX wf;
	if(!pfmt)
	{
	
		
		wf.wFormatTag	= WAVE_FORMAT_PCM;
		wf.cbSize		= 0;
		wf.wBitsPerSample=16;
		wf.nSamplesPerSec=8000;
		wf.nChannels=1;
		wf.nAvgBytesPerSec	= wf.nSamplesPerSec*(wf.wBitsPerSample/8);
		wf.nBlockAlign		= wf.nChannels     *(wf.wBitsPerSample/8);
		pfmt=&wf;
	}
	MMRESULT mmr;
	
	mmr=waveInOpen(0,WAVE_MAPPER,pfmt,0,0,WAVE_FORMAT_QUERY);
	if(mmr)
	{
		SetLastMMError(mmr);
		goto RET;
	}
	mmr=waveInOpen(&m_hIn,WAVE_MAPPER,pfmt,dwCallback,dwCallbackInstance,fdwOpen);
	if(mmr)
	{
		
		
		SetLastMMError(mmr);
		goto RET;
	}
	bRet=TRUE;
RET:
	return bRet;
}






CWaveIn::operator HWAVEIN() const
{
	return m_hIn;
}

CWaveIn::~CWaveIn()
{
	
}



MMRESULT CWaveIn::GetLastMMError()
{
	return m_mmr;
}

void CWaveIn::SetLastMMError(MMRESULT mmr)
{
	m_mmr=mmr;
}

BOOL CWaveIn::CloseDev()
{
	BOOL bRet=FALSE;
	if(!m_hIn)
		goto RET;
	m_mmr=waveInReset(m_hIn);
	if(m_mmr)
		goto RET;
	m_mmr=waveInClose(m_hIn);
	if(m_mmr)
		goto RET;
	m_hIn=0;
	bRet=TRUE;
RET:
	return bRet;
}
