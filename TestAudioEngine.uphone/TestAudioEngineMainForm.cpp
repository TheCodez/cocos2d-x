// Application main form file.
 
// Original file name: TestAudioEngineMainForm.cpp
// Generated by TOPS Builder:Project wizard,Date:2010-9-29
 

 
#include  "TestAudioEngineMainForm.h"
#include  "testaudioengine_res_def.h"
#include  "TestAudioEngineUnicodeScript_str.h"
#include  "SimpleAudioEngine.h"
#include  <cassert>

using namespace CocosDenshion;

TMainForm::TMainForm(TApplication * pApp):TWindow(pApp)
, m_nEffect2ID(0)
{
	Create(TESTAU_ID_Form1002);
}

TMainForm::~TMainForm()
{
	SimpleAudioEngine::sharedEngine()->end();
}

Boolean TMainForm::EventHandler(TApplication * pApp, EventType * pEvent)
{
	Boolean bHandled = FALSE;

	switch(pEvent->eType)
	{
	case EVENT_WinInit:
		{
            SimpleAudioEngine::setResourcePath("/NEWPLUS/TDA_DATA/Data/APPS/TestAudioEngine/");
            SimpleAudioEngine::sharedEngine()->setBackgroundMusicVolume(30);
            SimpleAudioEngine::sharedEngine()->setEffectsVolume(30);
			bHandled = TRUE;
		}
		break;
	case EVENT_WinPaint:
		{
			DrawWindow();
			bHandled = TRUE;
		}
		break;
	case EVENT_CtrlSelect:
		{
			//switch(pEvent->sParam1)
			//{
			//case RES_SYSTEM_WINDOW_TITLE_BUTTON_ID:
			//	bHandled = TRUE;
			//	break;			
			//}
            bHandled = CtrlSelected(pApp, pEvent);
		}
		break;
	case EVENT_WinClose:
		{
			// Stop the application since the main form has been closed
			pApp->SendStopEvent();
		}
		break;
	}
	
	if (FALSE == bHandled)
	{
		return TWindow::EventHandler(pApp,pEvent);
	}
	return bHandled;
}

Boolean TMainForm::CtrlSelected(TApplication * pApp, EventType * pEvent)
{
    Boolean bHandled = FALSE;
    SimpleAudioEngine* pAudioEngine = SimpleAudioEngine::sharedEngine();

    switch (pEvent->sParam1)
    {
    case TESTAU_ID_Form1002_PlayBack:
        // play background music
        pAudioEngine->playBackgroundMusic("background.mp3", true);
        bHandled = TRUE;
        break;

    case TESTAU_ID_Form1002_PauseBack:
        // pause background music
        pAudioEngine->pauseBackgroundMusic();
        bHandled = TRUE;
        break;

    case TESTAU_ID_Form1002_StopBack:
        // stop background music
        pAudioEngine->stopBackgroundMusic();
        bHandled = TRUE;
        break;

    case TESTAU_ID_Form1002_BackVolumeUp:
        {
            int nCurVolume = pAudioEngine->getBackgroundMusicVolume();
            pAudioEngine->setBackgroundMusicVolume(nCurVolume + 5);
            bHandled = TRUE;
        }
        break;

    case TESTAU_ID_Form1002_BackVolumeDown:
        {
            int nCurVolume = pAudioEngine->getBackgroundMusicVolume();
            pAudioEngine->setBackgroundMusicVolume(nCurVolume - 5);
            bHandled = TRUE;
        }
        break;

    case TESTAU_ID_Form1002_LoadEffect:
        // load effect1
        pAudioEngine->preloadEffect("Effect1.wav");
        bHandled = TRUE;
        break;

    case TESTAU_ID_Form1002_UnLoadBtn:
        // unload effect1
        pAudioEngine->unloadEffect("Effect1.wav");
        bHandled = TRUE;
        break;

    case TESTAU_ID_Form1002_PlayEffect:
        // play effect2
        m_nEffect2ID = pAudioEngine->playEffect("Effect2.wav");
/*        assert(m_nEffect2ID >= 0);*/
        bHandled = TRUE;
        break;

    case TESTAU_ID_Form1002_EffectVolumeUp:
        {
            int nCurVolume = pAudioEngine->getEffectsVolume();
            pAudioEngine->setEffectsVolume(nCurVolume + 5);
            bHandled = TRUE;
        }
        break;

    case TESTAU_ID_Form1002_EffectVolumeDown:
        {
            int nCurVolume = pAudioEngine->getEffectsVolume();
            pAudioEngine->setEffectsVolume(nCurVolume - 5);
            bHandled = TRUE;
        }
        break;
    default:
        break;
    }

    return bHandled;
}
