#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Sheep.h"
#include <cstdlib>
#include <ctime>
namespace game_framework
{
	Sheep::Sheep(int _x, int _y) :Animals(_x, _y,5)
	{
		LoadBitmap();
	}
	void Sheep::LoadBitmap()
	{
		WIdelD.LoadBitmap(IDB_Sheep_IDEL_D, RGB(255, 255, 255));
		WIdelU.LoadBitmap(IDB_Sheep_IDEL_U, RGB(255, 255, 255));
		WIdelL.LoadBitmap(IDB_Sheep_IDEL_L, RGB(255, 255, 255));
		WIdelR.LoadBitmap(IDB_Sheep_IDEL_R, RGB(255, 255, 255));
		char *filename[4] = { ".\\asset\\Picture\\Animals\\Sheep\\Sheep_WalkD_1.bmp",".\\asset\\Picture\\Animals\\Sheep\\Sheep_WalkD_2.bmp",".\\asset\\Picture\\Animals\\Sheep\\Sheep_WalkD_3.bmp",".\\asset\\Picture\\Animals\\Sheep\\Sheep_WalkD_4.bmp" };
		char *filename2[4] = { ".\\asset\\Picture\\Animals\\Sheep\\Sheep_WalkL_1.bmp",".\\asset\\Picture\\Animals\\Sheep\\Sheep_WalkL_2.bmp",".\\asset\\Picture\\Animals\\Sheep\\Sheep_WalkL_3.bmp",".\\asset\\Picture\\Animals\\Sheep\\Sheep_WalkL_4.bmp" };
		char *filename3[4] = { ".\\asset\\Picture\\Animals\\Sheep\\Sheep_WalkR_1.bmp",".\\asset\\Picture\\Animals\\Sheep\\Sheep_WalkR_2.bmp",".\\asset\\Picture\\Animals\\Sheep\\Sheep_WalkR_3.bmp",".\\asset\\Picture\\Animals\\Sheep\\Sheep_WalkR_4.bmp" };
		char *filename4[4] = { ".\\asset\\Picture\\Animals\\Sheep\\Sheep_WalkU_1.bmp",".\\asset\\Picture\\Animals\\Sheep\\Sheep_WalkU_2.bmp",".\\asset\\Picture\\Animals\\Sheep\\Sheep_WalkU_3.bmp",".\\asset\\Picture\\Animals\\Sheep\\Sheep_WalkU_4.bmp" };
		for (int i = 0; i < 4; i++)	// 載入動畫(由4張圖形構成)
		{
			animation_D.AddBitmap(filename[i], RGB(255, 255, 255));
			animation_L.AddBitmap(filename2[i], RGB(255, 255, 255));
			animation_R.AddBitmap(filename3[i], RGB(255, 255, 255));
			animation_U.AddBitmap(filename4[i], RGB(255, 255, 255));
		}
	}
}
