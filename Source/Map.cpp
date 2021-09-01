#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include <vector>
#include "audio.h"
#include "gamelib.h"
#include "Crop.h"
#include "Animals.h"
#include "Chicken.h"
#include "Cow.h"
#include "Sheep.h"
#include "Map.h"
#include <cstdlib>
#include <ctime>
namespace game_framework
{
	Map::Map() : X(0), Y(0), time(1234), crop_created(false)
	{
		/*初始化地圖草地*/
		for (int i = 0; i < 100; i++)
			for (int j = 0; j < 100; j++)
				map[i][j] = 1;
		for (int i = 0; i < 100; i++)
			for (int j = 0; j < 100; j++)
				mapObject[i][j] = 0;
		/*	1: 商人	      | 2: 大麥	   | 1007: 草叢1| 1008: 草叢2
			1000: 下排柵欄| 1005: 左下 | 1002: 直   | 1003: 左上
			1004: 上排	  | 1001: 右上 | 1006: 右下 | 3: 商店
			10: 雞舍牆壁  | 11: 雞舍地板| 12: 雞舍飼料盒 |*/
		srand(time * (NULL));
		int bush1 = 0, bush2 = 0, bush3 = 0, bush4 = 0;
		/*	農場外圍的柵欄	*/
		mapObject[0][0] = 1003;	// 左上
		mapObject[99][0] = 1001;// 右上
		mapObject[0][99] = 1005;// 左下
		mapObject[99][99] = 1006;// 右下
		for (int i = 1; i < 99; i++)	// 上排
		{
			mapObject[0][i] = 1004;
		}
		for (int i = 1; i < 99; i++)	// 左排
		{
			mapObject[i][0] = 1002;
		}
		for (int i = 1; i < 99; i++)	// 右排
		{
			mapObject[i][99] = 1002;
		}
		for (int i = 1; i < 99; i++)	// 下排
		{
			mapObject[99][i] = 1000;
		}
		for (int i = 0; i < 8; i++)	  /*	放置草叢	*/
		{
			bush1 = i % 100;
			bush2 = rand() % 100;
			if (map[bush1][bush2] == 1)
			{
				mapObject[bush1][bush2] = 1007;	// 放置草叢1
			}
			bush3 = i % 100;
			bush4 = rand() % 100;
			if (map[bush3][bush4] == 1)
			{
				mapObject[bush3][bush4] = 1008;	// 放置草叢2
			}
		}
		mapObject[4][11] = 1;		// 商人
		/*		幹道
		12:	中下的路 13: 中間的路(沒有邊緣) 14:	中左的路 15: 中右的路 16: 中上的路  17:	左下角的路
		18: 左上角的路 19: 右下角的路 20: 右上角的路*/
		for (int i = 12; i < 17; i++)
		{
			map[i][5] = 14;
		}
		for (int i = 12; i < 17; i++)
		{
			map[i][6] = 13;
		}
		for (int i = 12; i < 15; i++)
		{
			map[i][7] = 15;
		}
		map[17][5] = 17;
		map[15][7] = 13;

		for (int i = 8; i < 99; i++)
		{
			map[15][i] = 16;
		}
		for (int i = 6; i < 99; i++)
		{
			map[16][i] = 13;
		}
		for (int i = 6; i < 99; i++)
		{
			map[17][i] = 12;
		}
		/*	商店的圍牆	*/
		for (int i = 0; i < 12; i++)
			for (int j = 0; j < 12; j++)
			{
				map[j + 1][i + 1] = 3;
			}
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 9; j++)
			{
				map[i + 4][j + 3] = 1;
			}
		for (int i = 0; i < 3; i++)
			map[12][5 + i] = 2;
		/*	牧場的圍牆	*/
		for (int i = 0; i < 13; i++)
			for (int j = 0; j < 13; j++)
				map[i + 22][j + 1] = 9;
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 10; j++)
				map[i + 23][j + 2] = 1;
		/*		往雞舍的路		*/
		/* 12:	中下的路 13: 中間的路(沒有邊緣) 14:	中左的路 15: 中右的路 16: 中上的路  17:	左下角的路
		18: 左上角的路 19: 右下角的路 20: 右上角的路*/
		for (int i = 12; i < 16; i++)
		{
			map[27][i] = 16;
		}
		for (int i = 12; i < 17; i++)
		{
			map[28][i] = 12;
		}
		map[28][17] = 19;
		for (int i = 18; i < 28; i++)
		{
			map[i][16] = 14;
		}
		map[17][16] = 13;
		map[17][17] = 13;
		map[27][16] = 13;
		map[13][29] = 14;
		map[14][29] = 14;
		map[13][30] = 15;
		map[14][30] = 15;
		map[15][29] = 13;
		map[15][30] = 13;
		for (int i = 18; i < 28; i++)
		{
			map[i][17] = 15;
		}
		/*	商店貨架上的商品	*/
		map[4][3] = 4;	// 大麥
		map[5][3] = 5;	// 玉米
		map[6][3] = 6;	// 蘿蔔
		map[7][3] = 7;	// 雞 (商品狀態)
		map[8][3] = 24;	// 羊
		map[9][3] = 25; // 牛
		map[4][7] = 8;	// 收銀台
		/*	 雞舍	10: 雞舍牆壁  | 11: 雞舍地板| 12: 飼料盒左邊| 13: 飼料盒中間| 14: 飼料盒右邊*/
		for (int i = 2; i < 13; i++)		// 牆壁的起始位置
		{
			for (int j = 23; j < 26; j++)
			{
				map[j][i] = 10;
			}
		}
		for (int i = 2; i < 13; i++)	// 地板的起始位置
		{
			for (int j = 25; j < 34; j++)
			{
				map[j][i] = 11;
			}
		}
		mapObject[25][2] = 12;	// 雞舍飼料盒

		for (int i = 3; i < 12; i++)
		{
			mapObject[25][i] = 13;
		}
		mapObject[25][12] = 14;
		/*			家			*/
		// 家  地板:21 | 牆壁: 22 | 牆壁底部: 23 | 食物: 24 | 水壺: 25 | 窩: 26 | 電視: 27
		int Width = 34;	// 寬: 10格 高: 12格
		for (int i = 25; i <= Width; i++)		// 牆壁的起始位置
		{
			for (int j = 1; j <= 2; j++)
			{
				map[j][i] = 22;
			}
		}
		for (int i = 25; i <= Width; i++)		// 牆壁底部
		{
			for (int j = 3; j <= 3; j++)
			{
				map[j][i] = 23;
			}
		}
		for (int i = 25; i <= Width; i++)		// 地板
		{
			for (int j = 4; j <= 12; j++)
			{
				map[j][i] = 21;
			}
		}
		mapObject[2][27] = 25;
		mapObject[4][26] = 27;
		mapObject[4][28] = 24;
		mapObject[4][32] = 26;
	}
	Map::~Map()
	{
		for (vector<Crop*>::iterator i = map_Crop.begin(); i < map_Crop.end(); i++)
			delete *i;

		for (vector<Animals*>::iterator i = map_Animals.begin(); i < map_Animals.end(); i++)
			delete *i;
	}
	void Map::Update(int x, int y, int command)
	{
		switch (command)
		{
			case 1:
				map[(y) / 32][(x) / 32] = 2;
				break;
			case 2:
				GrowCrop(x / 32, y / 32, 2);
				break;
			case 3:
				GrowCrop(x / 32, y / 32, 3);
				break;
			case -1:
				break;
			default:
				break;
		}
	}
	void Map::LoadBitmap()
	{
		bus.LoadBitmap();
		map_Animals.push_back(new Chicken(32 * 7, 32 * 27));
		map_Animals.push_back(new Chicken(32 * 7, 32 * 27));
		map_Animals.push_back(new Chicken(32 * 7, 32 * 27));
		map_Animals.push_back(new Chicken(32 * 7, 32 * 27));
		map_Animals.push_back(new Chicken(32 * 7, 32 * 27));
		map_Animals.push_back(new Chicken(32 * 7, 32 * 27));
		map_Animals.push_back(new Chicken(32 * 7, 32 * 27));
		map_Animals.push_back(new Chicken(32 * 7, 32 * 27));
		map_Animals.push_back(new Chicken(32 * 7, 32 * 27));
		map_Animals.push_back(new Chicken(32 * 7, 32 * 27));
		map_Animals.push_back(new Chicken(32 * 7, 32 * 27));
		map_Animals.push_back(new Cow(700, 500));
		map_Animals.push_back(new Sheep(700, 500));
		grass.LoadBitmap(IDB_GRASS);
		dryDirt.LoadBitmap(IDB_DRY_DIRT, RGB(255, 255, 255));
		Road_Center.LoadBitmap(IDB_Road_Center);
		Road_CDown.LoadBitmap(IDB_Road_CDown);
		Road_CUp.LoadBitmap(IDB_Road_CUp);
		Road_CLeft.LoadBitmap(IDB_Road_CLeft);
		Road_CRight.LoadBitmap(IDB_Road_CRight);
		Road_LDownCorner.LoadBitmap(IDB_Road_LDownCorner);
		Road_LUpCorner.LoadBitmap(IDB_Road_LUpCorner);
		Road_RDownCorner.LoadBitmap(IDB_Road_RDownCorner);
		Road_RUpCorner.LoadBitmap(IDB_Road_RUpCorner);
		Bush1.LoadBitmap(IDB_BUSH1, RGB(255, 255, 255));
		Bush2.LoadBitmap(IDB_BUSH2, RGB(255, 255, 255));
		Fence.LoadBitmap(IDB_FENCE, RGB(255, 255, 255));	// 柵欄
		Fence_Back.LoadBitmap(IDB_FENCE_BACK, RGB(255, 255, 255));
		Fence_LUnder.LoadBitmap(IDB_FENCE_LUNDER, RGB(255, 255, 255));
		Fence_LUp.LoadBitmap(IDB_FENCE_LUP, RGB(255, 255, 255));
		Fence_RUnder.LoadBitmap(IDB_FENCE_RUNDER, RGB(255, 255, 255));
		Fence_RUp.LoadBitmap(IDB_FENCE_RUP, RGB(255, 255, 255));
		Fence_Str.LoadBitmap(IDB_FENCE_STR, RGB(255, 255, 255));
		store.LoadBitmap(IDB_STORE, RGB(255, 255, 255));	// 商店
		store_house.LoadBitmap(IDB_STOREHouse, RGB(0, 0, 0));	// 商店外觀
		Chicken_House.LoadBitmap(IDB_ChHouse, RGB(0, 0, 0));	// 雞舍
		ChHouse_Gnd.LoadBitmap(IDB_ChGnd);
		ChHouse_Wall.LoadBitmap(IDB_ChWell);
		ChHouse_Feedbox1.LoadBitmap(IDB_ChFeedbox1, RGB(255, 255, 255));
		ChHouse_Feedbox2.LoadBitmap(IDB_ChFeedbox2, RGB(255, 255, 255));
		ChHouse_Feedbox3.LoadBitmap(IDB_ChFeedbox3, RGB(255, 255, 255));
		home_house.LoadBitmap(IDB_HmHouse);
		HmGnd.LoadBitmap(IDB_HmGnd);		// 家  21
		HmWall.LoadBitmap(IDB_HmWall);		// 22
		HmWallBtm.LoadBitmap(IDB_HmWallBtm);// 23
		HmFood.LoadBitmap(IDB_HmFood, RGB(255, 255, 255));// 24
		HmKettle.LoadBitmap(IDB_HmKettle, RGB(255, 255, 255));// 25
		HmNst.LoadBitmap(IDB_HmNst, RGB(255, 255, 255));//26
		HmTV.LoadBitmap(IDB_HmTV, RGB(255, 255, 255));//27
		Tool_axe.LoadBitmap(IDB_Tool_axe, RGB(255, 255, 255));	//工具
		Tool_bell.LoadBitmap(IDB_Tool_bell, RGB(255, 255, 255));
		Tool_hammer.LoadBitmap(IDB_Tool_hammer, RGB(255, 255, 255));
		Tool_hoe.LoadBitmap(IDB_Tool_hoe, RGB(255, 255, 255));
		Tool_milkMachine.LoadBitmap(IDB_Tool_milkMachine, RGB(255, 255, 255));
		Tool_rod.LoadBitmap(IDB_Tool_rod, RGB(255, 255, 255));
		Tool_scissor.LoadBitmap(IDB_Tool_scissor, RGB(255, 255, 255));
		Tool_sickle.LoadBitmap(IDB_Tool_sickle, RGB(255, 255, 255));
		Tool_WtrCan.LoadBitmap(IDB_Tool_WtrCan, RGB(255, 255, 255));
		Tool_box.LoadBitmap(IDB_Tool_box, RGB(255, 255, 255));
		test.LoadBitmap(IDB_CHIC_IDEL_D);		// 雞
		egg.LoadBitmap(IDB_EGG, RGB(255, 255, 255));
		MainPoint.LoadBitmap(IDB_MAIN_POINT, RGB(255, 255, 255));
	}
	void Map::OnShow()
	{
		for (int i = 0; i < 100; i++)
			for (int j = 0; j < 100; j++)
			{
				X = i * 32 - sx;
				Y = j * 32 - sy;
				switch (map[j][i])
				{
					case 1:
						grass.SetTopLeft(X, Y);
						grass.ShowBitmap();
						break;
					case 2:
						dryDirt.SetTopLeft(X, Y);
						dryDirt.ShowBitmap();
						break;
					case 3:
						break;
					case 4:
						break;
					case 5:
						break;
					case 6:
						break;
					case 7:
						break;
					case 8:
						break;
					case 9:
						grass.SetTopLeft(X, Y);
						grass.ShowBitmap();
						break;
					// 10: 雞舍牆壁  | 11: 雞舍地板
					case 10:
						ChHouse_Wall.SetTopLeft(X, Y);
						ChHouse_Wall.ShowBitmap();
						break;
					case 11:
						ChHouse_Gnd.SetTopLeft(X, Y);
						ChHouse_Gnd.ShowBitmap();
						break;
					case 12:	// 中下的路
						Road_CDown.SetTopLeft(X, Y);
						Road_CDown.ShowBitmap();
						break;
					case 13:	// 中間的路(沒有邊緣)
						Road_Center.SetTopLeft(X, Y);
						Road_Center.ShowBitmap();
						break;
					case 14:	// 中左的路
						Road_CLeft.SetTopLeft(X, Y);
						Road_CLeft.ShowBitmap();
						break;
					case 15:	// 中右的路
						Road_CRight.SetTopLeft(X, Y);
						Road_CRight.ShowBitmap();
						break;
					case 16:	// 中下的路
						Road_CUp.SetTopLeft(X, Y);
						Road_CUp.ShowBitmap();
						break;
					case 17:	// 左下角的路
						Road_LDownCorner.SetTopLeft(X, Y);
						Road_LDownCorner.ShowBitmap();
						break;
					case 18:	// 左上角的路
						Road_LUpCorner.SetTopLeft(X, Y);
						Road_LUpCorner.ShowBitmap();
						break;
					case 19:	// 右下角的路
						Road_RDownCorner.SetTopLeft(X, Y);
						Road_RDownCorner.ShowBitmap();
						break;
					case 20:	// 右上角的路
						Road_RUpCorner.SetTopLeft(X, Y);
						Road_RUpCorner.ShowBitmap();
						break;
					case 21:
						HmGnd.SetTopLeft(X, Y);
						HmGnd.ShowBitmap();
						break;
					case 22:
						HmWall.SetTopLeft(X, Y);
						HmWall.ShowBitmap();
						break;
					case 23:
						HmWallBtm.SetTopLeft(X, Y);
						HmWallBtm.ShowBitmap();
						break;
					case 24:
						break;
					case 25:
						break;
					default:
						ASSERT(0);
				}
			}
		for (int i = 0; i < 100; i++)
			for (int j = 0; j < 100; j++)
			{
				switch (mapObject[i][j])
				{
					/*		放置型工具		*/
					case 11:
						Tool_box.SetTopLeft(j * 32 - sx, i * 32 - sy);
						Tool_box.ShowBitmap();
						break;
					/*			雞舍		*/
					case 12:
						ChHouse_Feedbox1.SetTopLeft(j * 32 - sx, i * 32 - sy);
						ChHouse_Feedbox1.ShowBitmap();
						break;
					case 13:
						ChHouse_Feedbox2.SetTopLeft(j * 32 - sx, i * 32 - sy);
						ChHouse_Feedbox2.ShowBitmap();
						break;
					case 14:
						ChHouse_Feedbox3.SetTopLeft(j * 32 - sx, i * 32 - sy);
						ChHouse_Feedbox3.ShowBitmap();
						break;
					/*			家			*/
					case 15:
						HmWall.SetTopLeft(j * 32 - sx, i * 32 - sy);
						HmWall.ShowBitmap();
						break;
					case 16:
						HmWallBtm.SetTopLeft(j * 32 - sx, i * 32 - sy);
						HmWallBtm.ShowBitmap();
						break;
					case 17:
						HmGnd.SetTopLeft(j * 32 - sx, i * 32 - sy);
						HmGnd.ShowBitmap();
						break;
					case 22:
						store_house.SetTopLeft(j * 32 - sx, i * 32 - sy);
						store_house.ShowBitmap();
						break;
					case 23:
						Chicken_House.SetTopLeft(j * 32 - sx, i * 32 - sy);
						Chicken_House.ShowBitmap();
						break;
					case 24:
						HmFood.SetTopLeft(j * 32 - sx, i * 32 - sy);
						HmFood.ShowBitmap();
						break;
					case 25:
						HmKettle.SetTopLeft(j * 32 - sx, i * 32 - sy);
						HmKettle.ShowBitmap();
						break;
					case 26:
						HmNst.SetTopLeft(j * 32 - sx, i * 32 - sy);
						HmNst.ShowBitmap();
						break;
					case 27:
						HmTV.SetTopLeft(j * 32 - sx, i * 32 - sy);
						HmTV.ShowBitmap();
						break;
					case 28:
						home_house.SetTopLeft(j * 32 - sx, i * 32 - sy);
						home_house.ShowBitmap();
						break;
					/*		柵欄		*/
					case 100:
						egg.SetTopLeft(j * 32 - sx, i * 32 - sy);
						egg.ShowBitmap();
						break;
					case 1000:
						Fence.SetTopLeft(j * 32 - sx, i * 32 - sy);
						Fence.ShowBitmap();
						break;
					case 1001:
						Fence_LUnder.SetTopLeft(j * 32 - sx, i * 32 - sy);
						Fence_LUnder.ShowBitmap();
						break;
					case 1002:
						Fence_Str.SetTopLeft(j * 32 - sx, i * 32 - sy);
						Fence_Str.ShowBitmap();
						break;
					case 1003:
						Fence_LUp.SetTopLeft(j * 32 - sx, i * 32 - sy);
						Fence_LUp.ShowBitmap();
						break;
					case 1004:
						Fence_Back.SetTopLeft(j * 32 - sx, i * 32 - sy);
						Fence_Back.ShowBitmap();
						break;
					case 1005:
						Fence_RUp.SetTopLeft(j * 32 - sx, i * 32 - sy);
						Fence_RUp.ShowBitmap();
						break;
					case 1006:
						Fence_RUnder.SetTopLeft(j * 32 - sx, i * 32 - sy);
						Fence_RUnder.ShowBitmap();
						break;
					/*		草叢		*/
					case 1007:
						Bush1.SetTopLeft(j * 32 - sx, i * 32 - sy);
						Bush1.ShowBitmap();
						break;
					case 1008:
						Bush2.SetTopLeft(j * 32 - sx, i * 32 - sy);
						Bush2.ShowBitmap();
						break;
					case 1009:
						MainPoint.SetTopLeft(j * 32 - sx, i * 32 - sy);
						MainPoint.ShowBitmap();
						break;
					default:
						break;
				}
			}
		for (vector<Crop*>::iterator j = map_Crop.begin(); j < map_Crop.end(); j++)
		{
			(*j)->OnShow(sx, sy);
		}
		store.SetTopLeft(1 * 32 - sx, 1 * 32 - sy);
		store.ShowBitmap();
		MainPoint.SetTopLeft(7 * 32 - sx, 4 * 32 + 10 - sy);
		MainPoint.ShowBitmap();
		MainPoint.SetTopLeft(3 * 32 - sx, 4 * 32 + 10 - sy);
		MainPoint.ShowBitmap();
		MainPoint.SetTopLeft(3 * 32 - sx, 5 * 32 + 10 - sy);
		MainPoint.ShowBitmap();
		MainPoint.SetTopLeft(3 * 32 - sx, 7 * 32 + 10 - sy);
		MainPoint.ShowBitmap();
		MainPoint.SetTopLeft(3 * 32 - sx, 8 * 32 + 10 - sy);
		MainPoint.ShowBitmap();
		MainPoint.SetTopLeft(3 * 32 - sx, 9 * 32 + 10 - sy);
		MainPoint.ShowBitmap();
		for (vector<Animals*>::iterator j = map_Animals.begin(); j < map_Animals.end(); j++)
		{
			(*j)->OnShow(sx, sy);
			if (AnimalsJail((*j)->GetX(), (*j)->GetY() - 1)) (*j)->SetWup(false);
			else  (*j)->SetWup(true);
			if (AnimalsJail((*j)->GetX(), (*j)->GetY() + (*j)->GetIngY() + 1)) (*j)->SetWdown(false);
			else  (*j)->SetWdown(true);
			if (AnimalsJail((*j)->GetX() - 1, (*j)->GetY())) (*j)->SetWleft(false);
			else  (*j)->SetWleft(true);
			if (AnimalsJail((*j)->GetX() + (*j)->GetIngX() + 1, (*j)->GetY() - 1)) (*j)->SetWright(false);
			else  (*j)->SetWright(true);
		}
		SpawnEgg();
		bus.OnShow(sx, sy);
		ShowHouse();
	}
	bool Map::IsEmpty(int x, int y) // (x, y) 為地圖的點座標
	{
		int gx = x / 32; // 轉換為格座標(整數除法)
		int gy = y / 32; // 轉換為格座標(整數除法)
		return map[gy][gx] == 3; // 假設 3代表牆壁
	}
	bool Map::AnimalsJail(int x, int y)
	{
		int gx = x / 32; // 轉換為格座標(整數除法)
		int gy = y / 32; // 轉換為格座標(整數除法)
		return map[gy][gx] == 9; // 假設 代表動物柵欄
	}
	void Map::SetScreenXY(int x, int y)
	{
		sx = x;
		sy = y;
	}
	void Map::SetObjectXY(int* x, int* y)
	{
		for (int i = 0; i < 100; i++)
			for (int j = 0; j < 100; j++)
			{
				switch (mapObject[i][j])
				{
					case 1:
						*x = j * 32 - sx;
						*y = i * 32 - sy;
						break;

					default:
						break;
				}
			}
	}
	void Map::GrowCrop(int blcok_x, int block_y, int id)
	{
		map_Crop.push_back(new Crop(blcok_x, block_y, id));
	}
	void Map::AddChicken(int blcok_x, int block_y)
	{
		map_Animals.push_back(new Chicken(blcok_x, block_y));
	}
	void Map::AddCow(int blcok_x, int block_y)
	{
		map_Animals.push_back(new Cow(blcok_x, block_y));
	}
	void Map::AddSheep(int blcok_x, int block_y)
	{
		map_Animals.push_back(new Sheep(blcok_x, block_y));
	}
	bool Map::IsDrit(int player_x, int player_y)
	{
		if (map[player_y / 32][player_x / 32] == 2)		//是不是土
		{
			if (!IsCrop(player_x, player_y))		//有沒有種東西
				return true;
			else
				return false;
		}
		else
		{
			return false;
		}
	}

	bool Map::IsCrop(int player_x, int player_y)
	{
		for (vector<Crop*>::iterator j = map_Crop.begin(); j < map_Crop.end(); j++)
		{
			if (((*j)->GetX()) == player_x / 32 && ((*j)->GetY()) == player_y / 32)  return true;
		}
		return false;
	}
	int Map::HarvestCrops(int player_x, int player_y)
	{
		for (vector<Crop*>::iterator j = map_Crop.begin(); j < map_Crop.end(); j++)
		{
			if (((*j)->GetX()) == player_x / 32 && ((*j)->GetY()) == player_y / 32)
			{
				int id;
				id = (*j)->GetId();
				delete *j;
				map_Crop.erase(j);
				return id;
			}
		}
		return 0;
	}
	bool Map::IsMatureCrop(int player_x, int player_y)
	{
		for (vector<Crop*>::iterator j = map_Crop.begin(); j < map_Crop.end(); j++)
		{
			if (((*j)->GetX()) == player_x / 32 && ((*j)->GetY()) == player_y / 32)
				if ((*j)->GetState() == 4)
					return true;
				else return false;
		}
		return false;
	}
	int Map::BuyProduct(int player_x, int player_y)
	{
		if (player_y / 32 == 4)return 2;	//買大麥
		if (player_y / 32 == 5)return 3;	//買玉米
		if (player_y / 32 == 7)return 4;	//買雞
		if (player_y / 32 == 8)return 5;	//買羊
		if (player_y / 32 == 9)return 6;	//買牛
		return 0;
	}
	bool Map::IsProduct(int player_x, int player_y)
	{
		if ((map[player_y / 32][player_x / 32] >= 4 && map[player_y / 32][player_x / 32] <= 7) || map[player_y / 32][player_x / 32] == 24 || map[player_y / 32][player_x / 32] == 25)return true;
		else return false;
	}
	bool Map::IsSeller(int player_x, int player_y)
	{
		if (map[player_y / 32][player_x / 32] == 8) return true;
		else return false;
	}
	void Map::SpawnEgg()
	{
		for (vector<Animals*>::iterator j = map_Animals.begin(); j < map_Animals.end(); j++)
		{
			if ((*j)->AddEgg()) mapObject[(*j)->GetY() / 32][(*j)->GetX() / 32] = 100;
		}
	}
	void Map::HarvestEgg(int player_x, int player_y)
	{
		mapObject[player_y / 32][player_x / 32] = 0;
	}
	bool Map::IsEgg(int player_x, int player_y)
	{
		if (mapObject[player_y / 32][player_x / 32] == 100) return true;
		else return false;
	}
	bool Map::IsSheep(int player_x, int player_y)
	{
		for (vector<Animals*>::iterator j = map_Animals.begin(); j < map_Animals.end(); j++)
		{
			if (
				player_x > (*j)->GetX() &&
				player_x < (*j)->GetX() + (*j)->GetIngX() &&
				player_y > (*j)->GetY() &&
				player_y < (*j)->GetY() + (*j)->GetIngY() &&
				(*j)->GetSoundId() == 5
			)
			return true;
		}
		return false;
	}
	bool Map::IsCow(int player_x, int player_y)
	{
		for (vector<Animals*>::iterator j = map_Animals.begin(); j < map_Animals.end(); j++)
		{
			if (
				player_x > (*j)->GetX() &&
				player_x < (*j)->GetX() + (*j)->GetIngX() &&
				player_y > (*j)->GetY() &&
				player_y < (*j)->GetY() + (*j)->GetIngY() &&
				(*j)->GetSoundId() == 6
			)
				return true;
		}
		return false;
	}
	void Map::ShowHouse()
	{
		if (!
				(playerX > 32 &&
				 playerX < 32 + store_house.Width() &&
				 playerY > 32 &&
				 playerY < 32 + store.Height()
				)
		   )
		{
			store_house.SetTopLeft( 32 - sx,  32 - sy);
			store_house.ShowBitmap();
		}

		if (!
				(playerX > 2 * 32 &&
				 playerX < 2 * 32 + Chicken_House.Width() &&
				 playerY > 23 * 32 &&
				 playerY < 23 * 32 + Chicken_House.Height()
				)
		   )
		{
			Chicken_House.SetTopLeft(2 * 32 - sx, 23 * 32 - sy);
			Chicken_House.ShowBitmap();
		}

		if (!
				(playerX > 25 * 32 &&
				 playerX < 25 * 32 + home_house.Width() &&
				 playerY > 1 * 32 &&
				 playerY < 1 * 32 + home_house.Height()
				)
		   )
		{
			home_house.SetTopLeft(25 * 32 - sx, 1 * 32 - sy);
			home_house.ShowBitmap();
		}
	}
	void Map::SetPlayerXY(int _x, int _y)
	{
		playerX = _x;
		playerY = _y;
	}
}