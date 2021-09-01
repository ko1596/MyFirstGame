#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Chicken.h"
#include <cstdlib>
#include <ctime>
namespace game_framework 
{
	Chicken::Chicken(int _x,int _y):Animals(_x,_y,7)
	{
		LoadBitmap();
	}
	void Chicken::LoadBitmap()
	{
		WIdelD.LoadBitmap(IDB_CHIC_IDEL_D, RGB(255, 255, 255));
		WIdelU.LoadBitmap(IDB_CHIC_IDEL_U, RGB(255, 255, 255));
		WIdelL.LoadBitmap(IDB_CHIC_IDEL_L, RGB(255, 255, 255));
		WIdelR.LoadBitmap(IDB_CHIC_IDEL_R, RGB(255, 255, 255));

		char *filename[4] = { ".\\asset\\Picture\\Animals\\Chicken\\Chicken_W_D1.bmp",".\\asset\\Picture\\Animals\\Chicken\\Chicken_W_D2.bmp",".\\asset\\Picture\\Animals\\Chicken\\Chicken_W_D3.bmp",".\\asset\\Picture\\Animals\\Chicken\\Chicken_W_D4.bmp" };
		char *filename2[4] = { ".\\asset\\Picture\\Animals\\Chicken\\Chicken_W_L1.bmp",".\\asset\\Picture\\Animals\\Chicken\\Chicken_W_L2.bmp",".\\asset\\Picture\\Animals\\Chicken\\Chicken_W_L3.bmp",".\\asset\\Picture\\Animals\\Chicken\\Chicken_W_L4.bmp" };
		char *filename3[4] = { ".\\asset\\Picture\\Animals\\Chicken\\Chicken_W_R1.bmp",".\\asset\\Picture\\Animals\\Chicken\\Chicken_W_R2.bmp",".\\asset\\Picture\\Animals\\Chicken\\Chicken_W_R3.bmp",".\\asset\\Picture\\Animals\\Chicken\\Chicken_W_R4.bmp" };
		char *filename4[4] = { ".\\asset\\Picture\\Animals\\Chicken\\Chicken_W_U1.bmp",".\\asset\\Picture\\Animals\\Chicken\\Chicken_W_U2.bmp",".\\asset\\Picture\\Animals\\Chicken\\Chicken_W_U3.bmp",".\\asset\\Picture\\Animals\\Chicken\\Chicken_W_U4.bmp" };
		for (int i = 0; i < 4; i++)	// 載入動畫(由4張圖形構成)
		{
			animation_D.AddBitmap(filename[i], RGB(255, 255, 255));
			animation_L.AddBitmap(filename2[i], RGB(255, 255, 255));
			animation_R.AddBitmap(filename3[i], RGB(255, 255, 255));
			animation_U.AddBitmap(filename4[i], RGB(255, 255, 255));
		}
	}
	bool Chicken::AddEgg()
	{
		if (spawnEggTime > 0)
		{
			spawnEggTime--;
			return false;
		}
		else
		{
			spawnEggTime = 33 * 3;
			if (rand() % 100 < 5) return true;
			else return false;
		}
	}
}