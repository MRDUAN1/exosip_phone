// AudioMgr.h: interface for the CAudioMgr class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_AUDIOMGR_H__C1EA3A59_327E_4E81_BA78_CCD7A3F20F24__INCLUDED_)
#define AFX_AUDIOMGR_H__C1EA3A59_327E_4E81_BA78_CCD7A3F20F24__INCLUDED_

#include "AudioRec.h"	// Added by ClassView
//#include "AudioPlay.h"	// Added by ClassView

#define SIZE_AUDIO_FRAME	960
#define SIZE_AUDIO_CODEC	60

#define IOM_AUDIO			WM_USER+100
#define AUDIO_DECODE		WM_USER+13
#define AUDIO_CODE			WM_USER+14

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
class CMediaCtrl;
class CAudioMgr_send  
{
public:
	//void OnAudioDataOut(char* buf,int len);
	void OnAudioDataIn(char* buf,int len);
	int destroy();
	int init();
	int StopAudioRec();
	//int StopAudioPlay();
	int StartAudioRec();
	//int StartAudioPlay();
	CAudioMgr_send();
	virtual ~CAudioMgr_send();

protected:
	//CMediaCtrl* m_pMediaCtrl;
	char* m_paR;
	char* m_paL;
	DWORD m_dwAudioOutId;
	DWORD m_dwAudioInId;
	HANDLE m_hAudioOut;
	
	CAudioRec m_audiorec;
//	CAudioPlay m_audioplay;
private:
	static DWORD WINAPI AudioOutThreadProc(LPVOID lpParameter);
	static DWORD WINAPI AudioInThreadProc(LPVOID lpParameter);
};

#endif // !defined(AFX_AUDIOMGR_H__C1EA3A59_327E_4E81_BA78_CCD7A3F20F24__INCLUDED_)
