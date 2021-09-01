#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Cow.h"
#include <cstdlib>
#include <ctime>
namespace game_framework 
{
	Cow::Cow(int _x, int _y) :Animals(_x, _y,6)
	{
		LoadBitmap();
	}

	void Cow::LoadBitmap()
	{
		WIdelD.LoadBitmap(IDB_Cow_IDEL_D, RGB(255, 255, 255));
		WIdelU.LoadBitmap(IDB_Cow_IDEL_U, RGB(255, 255, 255));
		WIdelL.LoadBitmap(IDB_Cow_IDEL_L, RGB(255, 255, 255));
		WIdelR.LoadBitmap(IDB_Cow_IDEL_R, RGB(255, 255, 255));
		char *filename[4] = { ".\\asset\\Picture\\Animals\\Cow\\Cow_W_D1.bmp",".\\asset\\Picture\\Animals\\Cow\\Cow_W_D2.bmp",".\\asset\\Picture\\Animals\\Cow\\Cow_W_D3.bmp",".\\asset\\Picture\\Animals\\Cow\\Cow_W_D4.bmp" };
		char *filename2[4] = { ".\\asset\\Picture\\Animals\\Cow\\Cow_W_L1.bmp",".\\asset\\Picture\\Animals\\Cow\\Cow_W_L2.bmp",".\\asset\\Picture\\Animals\\Cow\\Cow_W_L3.bmp",".\\asset\\Picture\\Animals\\Cow\\Cow_W_L4.bmp" };
		char *filename3[4] = { ".\\asset\\Picture\\Animals\\Cow\\Cow_W_R1.bmp",".\\asset\\Picture\\Animals\\Cow\\Cow_W_R2.bmp",".\\asset\\Picture\\Animals\\Cow\\Cow_W_R3.bmp",".\\asset\\Picture\\Animals\\Cow\\Cow_W_R4.bmp" };
		char *filename4[4] = { ".\\asset\\Picture\\Animals\\Cow\\Cow_W_U1.bmp",".\\asset\\Picture\\Animals\\Cow\\Cow_W_U2.bmp",".\\asset\\Picture\\Animals\\Cow\\Cow_W_U3.bmp",".\\asset\\Picture\\Animals\\Cow\\Cow_W_U4.bmp" };
		for (int i = 0; i < 4; i++)	// 載入動畫(由4張圖形構成)
		{
			animation_D.AddBitmap(filename[i], RGB(255, 255, 255));
			animation_L.AddBitmap(filename2[i], RGB(255, 255, 255));
			animation_R.AddBitmap(filename3[i], RGB(255, 255, 255));
			animation_U.AddBitmap(filename4[i], RGB(255, 255, 255));
		}
	}
}