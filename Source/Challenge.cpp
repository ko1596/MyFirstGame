#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Challenge.h"
namespace game_framework {
	Challenge::Challenge() :cropCount(1), chickenCount(1), sheepCount(1), cowCount(1), stage(0) {}
	void Challenge::LoadBitmap()
	{
		crop.LoadBitmap(IDB_Ach_Crop, RGB(255, 255, 255));
		chicken.LoadBitmap(IDB_Ach_Chicken, RGB(255, 255, 255));
		sheep.LoadBitmap(IDB_Ach_Sheep, RGB(255, 255, 255));
		cow.LoadBitmap(IDB_Ach_Cow, RGB(255, 255, 255));
		money.LoadBitmap(IDB_Ach_Money, RGB(255, 255, 255));
	}
	void Challenge::OnShow()
	{
		ChallengeCompletedCheck();
		if (ShowTime > 0)
		{
			switch (stage)
			{
			case 1:
				crop.SetTopLeft(100, 100);
				crop.ShowBitmap();
				break;
			case 2:
				chicken.SetTopLeft(100, 100);
				chicken.ShowBitmap();
				break;
			case 3:
				sheep.SetTopLeft(100, 100);
				sheep.ShowBitmap();
				break;
			case 4:
				cow.SetTopLeft(100, 100);
				cow.ShowBitmap();
				break;
			case 5:
				money.SetTopLeft(100, 100);
				money.ShowBitmap();
				break;
			default:
				break;
			}
			ShowTime--;
		}	
		else if (ShowTime == 0)
		{
			CAudio::Instance()->Play(9, false);
		}
	}
	void Challenge::AddCount(int id)
	{
		switch (id)
		{
		case 1:
			cropCount++;
			break;
		case 2:
			chickenCount++;
			break;
		case 3:
			sheepCount++;
			break;
		case 4:
			cowCount++;
			break;
		default:
			break;
		}
	}
	void Challenge::ChallengeCompletedCheck()
	{
		if (stage == 0 && cropCount > 10)
		{
			stage++;
			CAudio::Instance()->Play(9, true);
			ShowTime = 33 * 7;
		}
		if (stage == 1 && chickenCount > 10)
		{
			stage++;
			CAudio::Instance()->Play(9, true);
			ShowTime = 33 * 7;
		}
		if (stage == 2 && sheepCount > 10)
		{
			stage++;
			CAudio::Instance()->Play(9, true);
			ShowTime = 33 * 7;
		}
		if (stage == 3 && cowCount > 10)
		{
			stage++;
			CAudio::Instance()->Play(9, true);
			ShowTime = 33 * 7;
		}
		if (stage == 4 && ctm >= 1000000)
		{
			stage++;
			CAudio::Instance()->Play(9, true);
			ShowTime = 33 * 7;
		}	
	}
	void Challenge::SetMoney(int _money)
	{
		ctm = _money;
	}
	int Challenge::GetState()
	{
		return stage;
	}
}