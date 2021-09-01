#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Animals.h"
namespace game_framework {
	Animals::Animals(int _x, int _y, int _soundid) :x(_x),y(_y),dire(Down), sec(0), moving(true), soundID(_soundid), soundsec(0){}
	void Animals::OnShow(int screenX, int screenY)		//顯示動物本體
	{
		sx = screenX;		//設定螢幕偏移
		sy = screenY;
		OnMove();
		switch (dire)			//設定方向
		{
		case game_framework::Up:
			AnimationShow(animation_U, WIdelU);
			break;
		case game_framework::Down:
			AnimationShow(animation_D, WIdelD);
			break;
		case game_framework::Left:
			AnimationShow(animation_L, WIdelL);
			break;
		case game_framework::Right:
			AnimationShow(animation_R, WIdelR);
			break;
		default:
			break;
		}
	}
	void Animals::OnMove()
	{
		if (soundsec == 0)			//撥放音樂
		{
			soundsec = ((rand() % 10) + 5) * 33;
			checkSound = soundsec;
			Sound();
		}
		else if (soundsec < checkSound-5)		//音樂撥放中
		{
			soundsec--;
		}
		else			//音樂撥放完成
		{
			soundsec--;
			CAudio::Instance()->Play(soundID, false);
		}
		if (sec < 0)		//新的一輪走路
		{
			sec = (rand() % 5) * 33;		//走多久時間
			int random_dir = 0;
			random_dir = (rand() % 4);		//方向
			walkStep = 0;
			countStep = 0;
			walkStep = (rand() % 100);		//走多少步(可能走路時間還沒到就已經變成靜止狀態)
			switch (random_dir)		//設定方向
			{
			case 1:
				dire = Down;
				break;
			case 2:
				dire = Left;
				break;
			case 3:
				dire = Right;
				break;
			case 4:
				dire = Up;
				break;
			default:
				break;
			}
			moving = true;
		}
		else
		{
			if (countStep < walkStep)		//開始走路
				switch (dire)
				{
				case game_framework::Up:
					if (Wup)
					{
						y--;
						animation_U.OnMove();
					}
					break;
				case game_framework::Down:
					if (Wdown)
					{
						y++;
						animation_D.OnMove();
					}
					break;
				case game_framework::Left:
					if (Wleft)
					{
						x--;
						animation_L.OnMove();
					}
					
					break;
				case game_framework::Right:
					if (Wright)
					{
						x++;
						animation_R.OnMove();
					}
					break;
				default:
					break;
				}
			else moving = false;		//停止走路
			sec--;
			countStep++;
		}
	}
	void Animals::AnimationShow(CAnimation move, CMovingBitmap idel)		//顯示動畫
	{
		if (moving)		//走路中動畫
		{
			move.SetTopLeft(x - sx, y - sy);
			move.OnShow();
		}
		else		//待命中動畫
		{
			idel.SetTopLeft(x - sx, y - sy);
			idel.ShowBitmap();
		}
	}
	int Animals::GetX()		//取的動物座標X
	{
		return x;
	}
	int Animals::GetY()		//取的動物座標Y
	{
		return y;
	}
	bool Animals::AddEgg()	//雞獨有的功能 其他物種疑慮return false
	{
		return false;
	}
	int Animals:: GetIngX()	//取得圖像寬度
	{
		return WIdelD.Width();
	}
	int Animals::GetIngY()	//取得圖像寬度
	{
		return WIdelD.Height();
	}
	void Animals::SetWup(bool w)		//判斷是否撞牆
	{
		Wup = w;
	}
	void Animals::SetWdown(bool w)
	{
		Wdown = w;
	}
	void Animals::SetWleft(bool w)
	{
		Wleft = w;
	}
	void Animals::SetWright(bool w)
	{
		Wright = w;
	}
	void Animals::Sound()		//撥放該物種音效
	{
		CAudio::Instance()->Play(soundID, true);
	}
	int Animals::GetSoundId()	//取的該物種的音效ID
	{
		return soundID;
	}
}