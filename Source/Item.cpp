#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Map.h"
#include "Item.h"
namespace game_framework
{
	Item::Item(int _id, int _amount):id(_id),amount(_amount),ImgLoaded(false){}
	void Item::LoadBitmap()
	{
		if (id == 2) ItemImg.LoadBitmap(IDB_BARLEY1,RGB(255,255,255));
		else if (id == 3) ItemImg.LoadBitmap(IDB_CORN1, RGB(255, 255, 255));
		else if (id == 50) ItemImg.LoadBitmap(IDB_BARLEY_ONHAND, RGB(255, 255, 255));
		else if (id == 51) ItemImg.LoadBitmap(IDB_CORN_ONHAND, RGB(255, 255, 255));
		else if (id == 100) ItemImg.LoadBitmap(IDB_EGG, RGB(255, 255, 255));
		else if (id == 101) ItemImg.LoadBitmap(IDB_Product_Fleece, RGB(255, 255, 255));
		else if (id == 102) ItemImg.LoadBitmap(IDB_Product_Milk, RGB(255, 255, 255));
		ImgLoaded = true;
	}
	void Item::OnShow()
	{
		ItemImg.SetTopLeft(x, y);
		ItemImg.ShowBitmap();
	}
	void Item::SetXY(int _x, int _y)
	{
		x = _x;
		y = _y;
	}
	int Item::GetAmount()
	{
		return amount;
	}
	int Item::GetId()
	{
		return id;
	}
	bool Item::GetImgLoaded()
	{
		return ImgLoaded;
	}
	void Item::UseItema()
	{
		amount--;
	}
	void Item::AddMount(int _amount)
	{
		amount += _amount;
	}
}