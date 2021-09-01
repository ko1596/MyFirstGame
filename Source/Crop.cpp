#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Crop.h"
namespace game_framework {
	Crop::Crop(int _x,int _y, int _id):id(_id), x(_x), y(_y) , state(0), ImgLoaded(false),growTime(0)
	{
		LoadBitmap();
	}
	void Crop::LoadBitmap()
	{
		if (id == 2)
		{
			cropPicture[0].LoadBitmap(IDB_BARLEY1,RGB(255,255,255));
			cropPicture[1].LoadBitmap(IDB_BARLEY2, RGB(255, 255, 255));
			cropPicture[2].LoadBitmap(IDB_BARLEY3, RGB(255, 255, 255));
			cropPicture[3].LoadBitmap(IDB_BARLEY4, RGB(255, 255, 255));
			cropPicture[4].LoadBitmap(IDB_BARLEY5, RGB(255, 255, 255));
			maxGrowTime = 2;
		}
		if (id == 3)
		{
			cropPicture[0].LoadBitmap(IDB_CORN1 , RGB(255, 255, 255));
			cropPicture[1].LoadBitmap(IDB_CORN2, RGB(255, 255, 255));
			cropPicture[2].LoadBitmap(IDB_CORN3, RGB(255, 255, 255));
			cropPicture[3].LoadBitmap(IDB_CORN4, RGB(255, 255, 255));
			cropPicture[4].LoadBitmap(IDB_CORN5, RGB(255, 255, 255));
			maxGrowTime = 20;
		}
		ImgLoaded = true;
	}
	void Crop::OnShow(int sx,int sy)
	{
			cropPicture[state].SetTopLeft(x*32 - sx, y*32 - sy);
			cropPicture[state].ShowBitmap();
			Grow();
	}
	void Crop::SetXY(int _x, int _y)
	{
		x = _x;
		y = _y;
	}
	bool Crop::GetImgLoaded()
	{
		return ImgLoaded;
	}
	void Crop::Grow()
	{
		growTime++;
		if (growTime / 33 > maxGrowTime)
		{
			state = 4;
		}
		else if (growTime / 33 > maxGrowTime*0.75)
		{
			state = 3;
		}
		else if (growTime / 33 > maxGrowTime*0.5)
		{
			state = 2;
		}
		else if (growTime / 33 > maxGrowTime*0.25)
		{
			state = 1;
		}
	}
	int Crop::GetX()
	{
		return x;
	}
	int Crop::GetY()
	{
		return y;
	}
	int Crop::GetId()
	{
		return id;
	}
	int Crop::GetState()
	{
		return state;
	}
}