#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Businessman.h"
namespace game_framework
{
	Businessman::Businessman():x(340),y(150) {}		//設定商人初始位置
	void Businessman::LoadBitmap()		//載入商人動畫
	{
		char *filename[6] = { ".\\asset\\Picture\\Business_Idel_1.bmp",".\\asset\\Picture\\Business_Idel_2.bmp",".\\asset\\Picture\\Business_Idel_3.bmp",".\\asset\\Picture\\Business_Idel_4.bmp",".\\asset\\Picture\\Business_Idel_5.bmp",".\\asset\\Picture\\Business_Idel_6.bmp" };
		for (int i = 0; i < 6; i++)
			animation_Idel.AddBitmap(filename[i], RGB(255, 255, 255));
	}
	void Businessman::OnShow(int _x,int _y)		//時時顯示商人位置
	{
		animation_Idel.SetTopLeft(x - _x, y - _y);
		animation_Idel.OnShow();
		animation_Idel.OnMove();
	}
}