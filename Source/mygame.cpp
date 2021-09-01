#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "mygame.h"
namespace game_framework
{
	CGameStateInit::CGameStateInit(CGame* g)  : CGameState(g){}
	void CGameStateInit::OnInit()
	{
		ShowInitProgress(0);	// 一開始的loading進度為0%
		initMenu.LoadBitmap();
	}
	void CGameStateInit::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
	{
		const char KEY_ESC = 27;
		const char KEY_SPACE = ' ';
		if (nChar == KEY_SPACE)
			GotoGameState(GAME_STATE_RUN);						// 切換至GAME_STATE_RUN
		else if (nChar == KEY_ESC)								// Demo 關閉遊戲的方法
			PostMessage(AfxGetMainWnd()->m_hWnd, WM_CLOSE, 0, 0);	// 關閉遊戲
	}
	void CGameStateInit::OnLButtonDown(UINT nFlags, CPoint point)
	{
		initMenu.MouseClickDown();
	}
	void CGameStateInit::OnLButtonUp(UINT nFlags, CPoint point)
	{
		initMenu.MouseClickUp();
		switch (initMenu.GetButtonState())
		{
			case 0:
				GotoGameState(GAME_STATE_RUN);
				break;
			case 1:
				PostMessage(AfxGetMainWnd()->m_hWnd, WM_CLOSE, 0, 0);
				break;
			case 2:
				initMenu.OpenAboutMenu();
				break;
			case 3:
				break;
			default:
				break;
		}
	}
	void CGameStateInit::OnMouseMove(UINT nFlags, CPoint point)
	{
		initMenu.GetMouse(point);
	}
	void CGameStateInit::OnShow()
	{
		initMenu.OnShow();
	}
	CGameStateOver::CGameStateOver(CGame* g)  : CGameState(g){}
	void CGameStateOver::OnMove()
	{
		counter--;
		if (counter < 0)
			PostMessage(AfxGetMainWnd()->m_hWnd, WM_CLOSE, 0, 0);
	}
	void CGameStateOver::OnBeginState()
	{
		counter = 30 * 10;
	}
	void CGameStateOver::OnInit()
	{
		end.LoadBitmap(IDB_Over_Win_Cul);
	}
	void CGameStateOver::OnShow()
	{
		end.SetTopLeft((SIZE_X - end.Width()) / 2, (SIZE_Y - end.Height()) / 2);
		end.ShowBitmap();
	}
	CGameStateRun::CGameStateRun(CGame* g) : CGameState(g), NUMBALLS(28){}
	CGameStateRun::~CGameStateRun(){}
	void CGameStateRun::OnBeginState()
	{
		doing = false;
		GameTime = 100000;
		CAudio::Instance()->Play(AUDIO_LAKE, true);			// 撥放 WAVE
	}
	void CGameStateRun::OnMove()							// 移動遊戲元素
	{
		SetCursor(AfxGetApp()->LoadCursor(IDC_GAMECURSOR));
		player.OnMove(&default_map, &ui,&challenge);
		GameTime++;
	}
	void CGameStateRun::OnInit()  								// 遊戲的初值及圖形設定
	{
		ShowInitProgress(33);	// 接個前一個狀態的進度，此處進度視為33%
		ShowInitProgress(50);
		player.LoadBitmap();
		CAudio::Instance()->Load(AUDIO_LAKE,  "asset\\BackgroundMusic\\HTF_BGM.mp3");	// 載入編號1的聲音lake.mp3
		CAudio::Instance()->Load(5, "asset\\Sound\\Sheep.mp3");
		CAudio::Instance()->Load(6, "asset\\Sound\\Cow.wav");
		CAudio::Instance()->Load(7, "asset\\Sound\\Chicken.mp3");
		CAudio::Instance()->Load(8, "asset\\Sound\\MC_WALK.mp3");
		CAudio::Instance()->Load(9, "asset\\Sound\\ChallengeCompleted.mp3");
		CAudio::Instance()->Load(10, "asset\\Sound\\changePage.wav");
		default_map.LoadBitmap();
		ui.LoadBitmap();
		challenge.LoadBitmap();
	}
	void CGameStateRun::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
	{
		const char KEY_LEFT  = 0x25; // keyboard左箭頭
		const char KEY_UP    = 0x26; // keyboard上箭頭
		const char KEY_RIGHT = 0x27; // keyboard右箭頭
		const char KEY_DOWN  = 0x28; // keyboard下箭頭
		const char KEY_DIG = 0x58; // keyboard_X
		const char KEY_BACKPACK = 0x53; //keyboard_S
		const char KEY_ESC = 0x1B; //keyboard_ESC
		const char KEY_Talk = 0x5a; //keyboard_Z
		const char KEY_GrowCrop = 0x43; //keyboard_C
		const char KEY_HarvestCrops = 0x44; //keyboard_D
		const char KEY_Buy = 0x42; //keyboard_B
		const char KEY_Sell = 0x56; //keyboard_V
		if (nChar == KEY_LEFT)
			player.KeyDown(Left);
		if (nChar == KEY_RIGHT)
			player.KeyDown(Right);
		if (nChar == KEY_UP)
			player.KeyDown(Up);
		if (nChar == KEY_DOWN)
			player.KeyDown(Down);
		switch (nChar)
		{
			case KEY_DIG:
				player.KeyDown(Dig);
				doing = true;
				break;
			case KEY_BACKPACK:
				player.KeyDown(OpenBackpack);
				doing = true;
				break;
			case KEY_ESC:
				player.KeyDown(PressEsc);
				doing = true;
				break;
			case KEY_Talk:
				player.KeyDown(ToTalk);
				doing = true;
				break;
			case KEY_GrowCrop:
				player.KeyDown(GrowCrop);
				doing = true;
				break;
			case KEY_HarvestCrops:
				player.KeyDown(Harvest);
				doing = true;
				break;
			case KEY_Buy:
				player.KeyDown(Buy);
				doing = true;
				break;
			case KEY_Sell:
				player.KeyDown(Sell);
				doing = true;
				break;
			default:
				break;
		}
	}
	void CGameStateRun::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
	{
		const char KEY_LEFT  = 0x25; // keyboard左箭頭
		const char KEY_UP    = 0x26; // keyboard上箭頭
		const char KEY_RIGHT = 0x27; // keyboard右箭頭
		const char KEY_DOWN  = 0x28; // keyboard下箭頭
		const char KEY_DIG = 0x58; // keyboard_X
		const char KEY_BACKPACK = 0x53; //keyboard_S
		const char KEY_ESC = 0x1B; //keyboard_ESC
		const char KEY_Talk = 0x5a; //keyboard_Z
		const char KEY_GrowCrop = 0x43; //keyboard_C
		const char KEY_HarvestCrops = 0x44; //keyboard_D
		const char KEY_Buy = 0x42; //keyboard_B
		const char KEY_Sell = 0x56; //keyboard_V
		if (nChar == KEY_LEFT)
			player.KeyUp(Left);
		if (nChar == KEY_RIGHT)
			player.KeyUp(Right);
		if (nChar == KEY_UP)
			player.KeyUp(Up);
		if (nChar == KEY_DOWN)
			player.KeyUp(Down);
		if (nChar == KEY_DIG && doing)
		{
			player.KeyUp(Dig);
			doing = false;
		}
		if (nChar == KEY_BACKPACK && doing)
		{
			player.KeyUp(OpenBackpack);
			doing = false;
		}
		if (nChar == KEY_ESC && doing)
		{
			player.KeyUp(PressEsc);
			doing = false;
		}
		if (nChar == KEY_Talk && doing)
		{
			player.KeyUp(ToTalk);
			doing = false;
		}
		if (nChar == KEY_GrowCrop && doing)
		{
			player.KeyUp(GrowCrop);
			doing = false;
		}
		if (nChar == KEY_HarvestCrops && doing)
		{
			player.KeyUp(Harvest);
			doing = false;
		}
		if (nChar == KEY_Buy && doing)
		{
			player.KeyUp(Buy);
			doing = false;
		}
		if (nChar == KEY_Sell && doing)
		{
			player.KeyUp(Sell);
			doing = false;
		}
	}
	void CGameStateRun::OnLButtonDown(UINT nFlags, CPoint point)  // 處理滑鼠的動作
	{
		ui.MouseClickDown(point);
	}
	void CGameStateRun::OnLButtonUp(UINT nFlags, CPoint point)	// 處理滑鼠的動作
	{
		ui.MouseClickUp();
	}
	void CGameStateRun::OnMouseMove(UINT nFlags, CPoint point)	// 處理滑鼠的動作
	{
		ui.SetMouseXY(point.x, point.y);
	}
	void CGameStateRun::OnShow()
	{
		default_map.OnShow();
		player.OnShow();
		ui.OnShow(GameTime, &challenge);
		challenge.OnShow();
		if (ui.GetGameOver())
		{
			ui.SetRunState();
			GotoGameState(GAME_STATE_OVER);
		
		}
	}
}