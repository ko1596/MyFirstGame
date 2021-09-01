#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Animals.h"
namespace game_framework {
	Animals::Animals(int _x, int _y, int _soundid) :x(_x),y(_y),dire(Down), sec(0), moving(true), soundID(_soundid), soundsec(0){}
	void Animals::OnShow(int screenX, int screenY)		//��ܰʪ�����
	{
		sx = screenX;		//�]�w�ù�����
		sy = screenY;
		OnMove();
		switch (dire)			//�]�w��V
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
		if (soundsec == 0)			//���񭵼�
		{
			soundsec = ((rand() % 10) + 5) * 33;
			checkSound = soundsec;
			Sound();
		}
		else if (soundsec < checkSound-5)		//���ּ���
		{
			soundsec--;
		}
		else			//���ּ��񧹦�
		{
			soundsec--;
			CAudio::Instance()->Play(soundID, false);
		}
		if (sec < 0)		//�s���@������
		{
			sec = (rand() % 5) * 33;		//���h�[�ɶ�
			int random_dir = 0;
			random_dir = (rand() % 4);		//��V
			walkStep = 0;
			countStep = 0;
			walkStep = (rand() % 100);		//���h�֨B(�i�ਫ���ɶ��٨S��N�w�g�ܦ��R��A)
			switch (random_dir)		//�]�w��V
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
			if (countStep < walkStep)		//�}�l����
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
			else moving = false;		//�����
			sec--;
			countStep++;
		}
	}
	void Animals::AnimationShow(CAnimation move, CMovingBitmap idel)		//��ܰʵe
	{
		if (moving)		//�������ʵe
		{
			move.SetTopLeft(x - sx, y - sy);
			move.OnShow();
		}
		else		//�ݩR���ʵe
		{
			idel.SetTopLeft(x - sx, y - sy);
			idel.ShowBitmap();
		}
	}
	int Animals::GetX()		//�����ʪ��y��X
	{
		return x;
	}
	int Animals::GetY()		//�����ʪ��y��Y
	{
		return y;
	}
	bool Animals::AddEgg()	//���W�����\�� ��L���غü{return false
	{
		return false;
	}
	int Animals:: GetIngX()	//���o�Ϲ��e��
	{
		return WIdelD.Width();
	}
	int Animals::GetIngY()	//���o�Ϲ��e��
	{
		return WIdelD.Height();
	}
	void Animals::SetWup(bool w)		//�P�_�O�_����
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
	void Animals::Sound()		//����Ӫ��ح���
	{
		CAudio::Instance()->Play(soundID, true);
	}
	int Animals::GetSoundId()	//�����Ӫ��ت�����ID
	{
		return soundID;
	}
}