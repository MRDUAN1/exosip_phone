// AudioMgr.cpp: implementation of the CAudioMgr class.
//
//////////////////////////////////////////////////////////////////////
//#include "标头.h"
#include "va_g729a.h"
#include <string>
#include "WaveIn.h"
#include <stdint.h>
#include "标头.h"
#include "AudioMgr_send.h"
#include "jrtp_send.h"
using namespace jrtplib;
HANDLE m_hAudioIn;
static RTPSession *sess;
using std::string;
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
//#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CAudioMgr_send::CAudioMgr_send()
{
	va_g729a_init_encoder();
	init();
}

CAudioMgr_send::~CAudioMgr_send()
{

}

int CAudioMgr_send::init()
{
	//m_pMediaCtrl = (CMediaCtrl*)lpParameter;
	//if(m_pMediaCtrl==NULL)
	//	return false;
	sess = jrtp_send::return_rtp_send_session();
	m_paR=0;
	m_paL=0;

	m_hAudioOut=0;
	m_hAudioIn=0;
	StartAudioRec();
	return true;
}

int CAudioMgr_send::destroy()
{
	StopAudioRec();
	//StopAudioPlay();
	return true;
}

DWORD CAudioMgr_send::AudioInThreadProc(LPVOID lpParameter)
{
	
	CAudioMgr_send* pMgr = (CAudioMgr_send*)lpParameter;
	MSG msg;
	char bytes[800] = { 0 };
	while(GetMessage(&msg,0,0,0))
	{
		switch(msg.message)
		{
		case WIM_DATA:
			{
				WAVEHDR* pWH=(WAVEHDR*)msg.lParam;
				waveInUnprepareHeader((HWAVEIN)msg.wParam,pWH,sizeof(WAVEHDR));
							
				if(pWH->dwBytesRecorded!=SIZE_AUDIO_FRAME)
					break;
				
			std::string buffer_tx;
			std::string buffer_tx_compress;
			short input_short[1000] = { 0 };
			buffer_tx.append(pWH->lpData, SIZE_AUDIO_FRAME);
			for (int i = 0; i < buffer_tx.length() / (L_FRAME * 2); i++)
			{
				for (int j = 0; j < L_FRAME; j++)
				{
					input_short[j] = (uint8_t)buffer_tx[2 * j + i * L_FRAME * 2] |
						(((uint8_t)buffer_tx[2 * j + 1 + i * L_FRAME * 2]) << 8);
				}
				va_g729a_encoder(input_short, (unsigned char *)bytes);
				buffer_tx_compress.append(bytes, L_FRAME_COMPRESSED);
			}
			int hh = sess->SendPacket(buffer_tx_compress.data(), buffer_tx_compress.size());
				waveInPrepareHeader((HWAVEIN)msg.wParam,pWH,sizeof(WAVEHDR));
				waveInAddBuffer((HWAVEIN)msg.wParam,pWH,sizeof(WAVEHDR));
			}
			break;
		}
	}	
	return msg.wParam;
}




int CAudioMgr_send::StartAudioRec()
{
	
	m_hAudioIn=CreateThread(0,0,AudioInThreadProc,this,0,&m_dwAudioInId);
	if (!m_hAudioIn)
		return false;
	if (!m_audiorec.Create(0, m_dwAudioInId, (DWORD)this, CALLBACK_THREAD, SIZE_AUDIO_FRAME))
		return false;
	if (!m_audiorec.Start())
		return false;
	m_paL = new char[SIZE_AUDIO_FRAME];
	if (!m_paL)
		return false;
	
	
	return true;
}



int CAudioMgr_send::StopAudioRec()
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
	m_audiorec.Stop();
    m_audiorec.Destroy();
	
	if(m_paL)
	{
		delete []m_paL;
		m_paL=0;
	}
	return TRUE;
}


