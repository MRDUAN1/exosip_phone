// AudioMgr.cpp: implementation of the CAudioMgr class.
//
//////////////////////////////////////////////////////////////////////

#include "AudioMgr_recv.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
//#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CAudioMgr_recv::CAudioMgr_recv()
{
	init();
}

CAudioMgr_recv::~CAudioMgr_recv()
{

}

int CAudioMgr_recv::init()
{
	m_paR=0;
	m_paL=0;

	m_hAudioOut=0;
	m_hAudioIn=0;
	StartAudioPlay();
	return true;
}

int CAudioMgr_recv::destroy()
{
	StopAudioRec();
	StopAudioPlay();
	return true;
}
DWORD CAudioMgr_recv::AudioOutThreadProc(LPVOID lpParameter)
{
	CAudioMgr_recv* pMgr = (CAudioMgr_recv*)lpParameter;
	MSG msg;
	while(GetMessage(&msg,0,0,0))
	{
		switch(msg.message)
		{
		case IOM_AUDIO:
			pMgr->m_audioplay.Play((char*)msg.lParam,(int)msg.wParam);
			break;
		case WOM_DONE:
			{
				WAVEHDR* pwh=(WAVEHDR*)msg.lParam;
				waveOutUnprepareHeader((HWAVEOUT)msg.wParam,pwh,sizeof(WAVEHDR));
				delete []pwh->lpData;
				delete pwh;
			}
			break;
		}
	}
	return msg.wParam;
}


int CAudioMgr_recv::StopAudioPlay()
{
	m_audioplay.Destroy();
	if(m_hAudioOut)
	{
		int t=50;
		DWORD ExitCode;
		BOOL bEnd=FALSE;
		PostThreadMessage(m_dwAudioOutId,WM_QUIT,0,0);
		while(t)
		{
			
			GetExitCodeThread(m_hAudioOut,&ExitCode);
			if(ExitCode!= STILL_ACTIVE)
			{
				bEnd=TRUE;
				break;
			}
			else
				Sleep(10);
			t--;
		}
		if(!bEnd)
			TerminateThread(m_hAudioOut,0);
		m_hAudioOut=0;
		
	}
	if(m_paR)
	{
		delete []m_paR;
		m_paR=0;
	}
	return 0;
}

int CAudioMgr_recv::StopAudioRec()
{
	if(m_hAudioIn)
	{
		int t=50;
		DWORD ExitCode;
		BOOL bEnd=FALSE;
		PostThreadMessage(m_dwAudioInId,WM_QUIT,0,0);
		while(t)
		{
			GetExitCodeThread(m_hAudioIn,&ExitCode);
			if(ExitCode!= STILL_ACTIVE)
			{
				bEnd=TRUE;
				break;
			}
			else
				Sleep(10);
			t--;
		}
		if(!bEnd)
			TerminateThread(m_hAudioIn,0);
		m_hAudioIn=0;
		
	}
	//m_audiorec.Stop();
  //  m_audiorec.Destroy();
	
	if(m_paL)
	{
		delete []m_paL;
		m_paL=0;
	}
	return TRUE;
}
void CAudioMgr_recv::OnAudioDataOut(char *buf, int len)
{
	CopyMemory(m_paR,buf,len);
	PostThreadMessage(m_dwAudioOutId,IOM_AUDIO,len,(LPARAM)m_paR);
}
int CAudioMgr_recv::StartAudioPlay()
{
	m_hAudioOut = CreateThread(0, 0, AudioOutThreadProc, this, 0, &m_dwAudioOutId);
	if (!m_hAudioOut)
		return false;
	if (!m_audioplay.Create(0, m_dwAudioOutId, (DWORD)this, CALLBACK_THREAD))
		return false;
	m_paR = new char[SIZE_AUDIO_FRAME];
	if (!m_paR)
		return false;
	return true;
}
