#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include <time.h>
#include <vector>
#include <string>
#include "audio.h"
#include "gamelib.h"
#include "Map.h"
#include "Item.h"
#include "UI.h"
namespace game_framework
{
	UI::UI() :
		_state(gaming),
		lastState(gaming),
		inventory_select(0),
		mouseClick(false),
		money(100000000),
		tool_select(5),
		overcount(33 * 10),
		StartOverCount(false),
		gameOver(false),
		changePageTime(0),
		page(1),
		pageBtnClick(true)
	{
		CreateItem(2, 10);
		CreateItem(3, 2);
		CreateItem(50, 6);
	}
	UI::~UI()
	{
		for (vector<Item*>::iterator i = InventoryItem.begin(); i < InventoryItem.end(); i++)
			delete *i;
	}
	void UI::ChangeState(state st)
	{
		if (lastState == st && st != Esc)
		{
			lastState = _state;
		}

		_state = st;
	}
	void UI::LoadBitmap()
	{
		for (int i = 0; i < 9; i++)
		{
			inventory[i].LoadBitmap(IDB_INVENTORY, RGB(255, 255, 255));
		}
		inventorySelect.LoadBitmap(IDB_INVENTORY_SELECT, RGB(255, 255, 255));
		inventory_line.LoadBitmap(IDB_LOAD_IVT_LINE, RGB(255, 255, 255));
		inventory_mainuse.LoadBitmap(IDB_MAINUSE, RGB(255, 255, 255));
		inventory_use1.LoadBitmap(IDB_MAINUSE2, RGB(255, 255, 255));
		inventory_use2.LoadBitmap(IDB_MAINUSE2, RGB(255, 255, 255));
		clockBar.LoadBitmap(IDB_CLOCKBAR, RGB(255, 255, 255));
		moneyBar.LoadBitmap(IDB_MONEYBAR, RGB(255, 255, 255));
		moneyIcon.LoadBitmap(IDB_MONEYICON, RGB(255, 255, 255));
		howToPlayBackground.LoadBitmap(IDB_BACKUI, RGB(255, 255, 255));
		axe.LoadBitmap(IDB_Tool_axe, RGB(255, 255, 255));
		bell.LoadBitmap(IDB_Tool_bell, RGB(255, 255, 255));
		box.LoadBitmap(IDB_Tool_box, RGB(255, 255, 255));
		hammer.LoadBitmap(IDB_Tool_hammer, RGB(255, 255, 255));
		hoe.LoadBitmap(IDB_Tool_hoe, RGB(255, 255, 255));
		milkMachine.LoadBitmap(IDB_Tool_milkMachine, RGB(255, 255, 255));
		rod.LoadBitmap(IDB_Tool_rod, RGB(255, 255, 255));
		scissor.LoadBitmap(IDB_Tool_scissor, RGB(255, 255, 255));
		sickle.LoadBitmap(IDB_Tool_sickle, RGB(255, 255, 255));
		WaterCan.LoadBitmap(IDB_Tool_WtrCan, RGB(255, 255, 255));
		none.LoadBitmap(IDB_Ach_Win_0, RGB(0, 0, 0));
		crop.LoadBitmap(IDB_Ach_Win_1, RGB(0, 0, 0));
		chicken.LoadBitmap(IDB_Ach_Win_2, RGB(0, 0, 0));
		sheep.LoadBitmap(IDB_Ach_Win_3, RGB(0, 0, 0));
		cow.LoadBitmap(IDB_Ach_Win_4, RGB(0, 0, 0));
		moneyPIC.LoadBitmap(IDB_Ach_Win_5, RGB(0, 0, 0));
		cropM.LoadBitmap(IDB_Ach_Des_Crop, RGB(0, 0, 0));
		chickenM.LoadBitmap(IDB_Ach_Des_Chicken, RGB(0, 0, 0));
		sheepM.LoadBitmap(IDB_Ach_Des_Sheep, RGB(0, 0, 0));
		cowM.LoadBitmap(IDB_Ach_Des_Cow, RGB(0, 0, 0));
		moneyPICM.LoadBitmap(IDB_Ach_Des_Money, RGB(0, 0, 0));
		overImg.LoadBitmap(IDB_Over_Win_YorN, RGB(0, 0, 0));
		overImgOver.LoadBitmap(IDB_Over_Win_YorN_NClick, RGB(0, 0, 0));
		overImgKeep.LoadBitmap(IDB_Over_Win_YorN_YClick, RGB(0, 0, 0));
		page1.LoadBitmap(IDB_B_Des_P1);
		page2.LoadBitmap(IDB_B_Des_P2);
		page3.LoadBitmap(IDB_B_Des_P3);
		page4.LoadBitmap(IDB_B_Des_P4);
		page5.LoadBitmap(IDB_B_Des_P5);
	}
	void UI::OnShow(int GameTime, Challenge* cha)
	{
		if (cha->GetState() == 5)
			StartOverCount = true;
		if (StartOverCount)
			overcount--;
		if (overcount == 0)
			_state = over;
		switch (_state)
		{
			case game_framework::Esc:
				_state = lastState;
				break;
			case game_framework::backpack:
				switch (cha->GetState())
				{
				case 0:
					none.SetTopLeft((SIZE_X - none.Width()) / 2, (SIZE_Y - none.Height()) / 2);
					none.ShowBitmap();
					break;
				case 1:
					crop.SetTopLeft((SIZE_X - none.Width()) / 2, (SIZE_Y - none.Height()) / 2);
					crop.ShowBitmap();
					break;
				case 2:
					chicken.SetTopLeft((SIZE_X - none.Width()) / 2, (SIZE_Y - none.Height()) / 2);
					chicken.ShowBitmap();
					break;
				case 3:
					sheep.SetTopLeft((SIZE_X - none.Width()) / 2, (SIZE_Y - none.Height()) / 2);
					sheep.ShowBitmap();
					break;
				case 4:
					cow.SetTopLeft((SIZE_X - none.Width()) / 2, (SIZE_Y - none.Height()) / 2);
					cow.ShowBitmap();
					break;
				case 5:
					moneyPIC.SetTopLeft((SIZE_X - none.Width()) / 2, (SIZE_Y - none.Height()) / 2);
					moneyPIC.ShowBitmap();
					break;
				default:
					break;
				}
				ShowChaItem();
				break;
			case game_framework::talk:
            
				switch (page)
				{
				case 1:
					page1.SetTopLeft((SIZE_X - page1.Width()) / 2, (SIZE_Y - page1.Height()) / 2);
					page1.ShowBitmap();
					break;
				case 2:
					page2.SetTopLeft((SIZE_X - page1.Width()) / 2, (SIZE_Y - page1.Height()) / 2);
					page2.ShowBitmap();
					break;
				case 3:
					page3.SetTopLeft((SIZE_X - page1.Width()) / 2, (SIZE_Y - page1.Height()) / 2);
					page3.ShowBitmap();
					break;
				case 4:
					page4.SetTopLeft((SIZE_X - page1.Width()) / 2, (SIZE_Y - page1.Height()) / 2);
					page4.ShowBitmap();
					break;
				case 5:
					page5.SetTopLeft((SIZE_X - page1.Width()) / 2, (SIZE_Y - page1.Height()) / 2);
					page5.ShowBitmap();
					break;
				default:
					break;
				}
				if (page > 1 && msx > 16 && msy > 614 && msx < 60 && msy < 661 && mouseClick && pageBtnClick)
				{
					page--;
					changePageTime = 1*20;
					CAudio::Instance()->Play(10, true);
					pageBtnClick = false;
				}
				if (page < 5 && msx > 1174 && msy > 614 && msx < 1221 && msy < 661 && mouseClick && pageBtnClick)
				{
					page++;
					changePageTime = 1 * 20;
					CAudio::Instance()->Play(10, true);
					pageBtnClick = false;
				}
				if (changePageTime != 0)
				{
					changePageTime--;
				}
				else if (changePageTime == 0)
				{
					CAudio::Instance()->Play(10, false);
				}
				break;
			case game_framework::gaming:
				for (int i = 0; i < 9; i++)
				{
					inventory[i].SetTopLeft(625 + i * 70, 625);
					inventory[i].ShowBitmap();

					if (ClickInventory(inventory[i]))
					{
						inventory_select = i;
					}
				}
				inventorySelect.SetTopLeft(inventory[inventory_select].Left(), 625);
				inventorySelect.ShowBitmap();
				inventory_line.SetTopLeft(50, 625);
				inventory_line.ShowBitmap();
				inventory_mainuse.SetTopLeft(160, 605);
				inventory_mainuse.ShowBitmap();
				inventory_use1.SetTopLeft(88, 620);
				inventory_use1.ShowBitmap();
				inventory_use2.SetTopLeft(260, 620);
				inventory_use2.ShowBitmap();
				ShowTime(GameTime);
				ShowItem();
				ShowMoney();
				ShowHowToPlay();
				Msg();
				ShowAllTool();
				break;
			case game_framework::over:
				overImg.SetTopLeft((SIZE_X - overImg.Width()) / 2, (SIZE_Y - overImg.Height()) / 2);
				overImgOver.SetTopLeft((SIZE_X - overImg.Width()) / 2, (SIZE_Y - overImg.Height()) / 2);
				overImgKeep.SetTopLeft((SIZE_X - overImg.Width()) / 2, (SIZE_Y - overImg.Height()) / 2);
				if (msx > 299 && msy > 416 && msx < 522 && msy < 500)
				{
					overImgKeep.ShowBitmap();
					if (mouseClick)
						_state = gaming;
				}
				else if (msx > 706 && msy > 416 && msx < 928 && msy < 500)
				{
					overImgOver.ShowBitmap();
					if (mouseClick)
						gameOver = true;
				}
				else
					overImg.ShowBitmap();			
				break;
			default:
				break;
		}
		size = InventoryItem.size();
	}
	void UI::ShowTime(int GameTime)
	{
		clockBar.SetTopLeft(SIZE_X - 250, 50);
		clockBar.ShowBitmap();
		time_t tt = time(0); //獲取當前時間
		struct tm* pst = localtime(&tt); //把time_t類型轉換為struct tm類型
		CDC* pDC = CDDraw::GetBackCDC();			// 取得 Back Plain 的 CDC
		CFont f, *fp;
		f.CreatePointFont(140, "Microsoft JhengHei");	// 產生 font f; 150表示15 point的字
		fp = pDC->SelectObject(&f);					// 選用 font f
		pDC->SetBkColor(RGB(187, 144, 108));
		pDC->SetTextColor(RGB(255, 255, 255));
		char str[80];								// Demo 數字對字串的轉換
		sprintf(str, "%02d : %02d", pst->tm_hour, pst->tm_min);
		pDC->TextOut(clockBar.Left() + 78, clockBar.Top() + 23, str);
		pDC->SelectObject(fp);						// 放掉 font f (千萬不要漏了放掉)
		CDDraw::ReleaseBackCDC();					// 放掉 Back Plain 的 CDC
	}
	void UI::CreateItem(int id, int amount)
	{
		InventoryItem.push_back(new Item(id, amount));
	}
	void UI::ShowItem()
	{
		int numItem = 0;
		deleteNonItem();
		for (vector<Item*>::iterator i = InventoryItem.begin(); i < InventoryItem.end(); i++)
		{
			if ((*i)->GetImgLoaded())
			{
				(*i)->SetXY(inventory[numItem].Left() + 14, inventory[numItem].Top() + 14);
				(*i)->OnShow();
				CDC* pDC = CDDraw::GetBackCDC();			// 取得 Back Plain 的 CDC
				CFont f, *fp;
				f.CreatePointFont(90, "Times New Roman");	// 產生 font f; 160表示16 point的字
				fp = pDC->SelectObject(&f);					// 選用 font f
				pDC->SetBkColor(RGB(197, 197, 155));
				pDC->SetTextColor(RGB(0, 0, 0));
				char str[80];								// Demo 數字對字串的轉換
				sprintf(str, "%d", (*i)->GetAmount());
				pDC->TextOut(inventory[numItem].Left() + 40, inventory[numItem].Top() + 40, str);
				pDC->SelectObject(fp);						// 放掉 font f (千萬不要漏了放掉)
				CDDraw::ReleaseBackCDC();					// 放掉 Back Plain 的 CDC
				numItem++;
			}
			else (*i)->LoadBitmap();
		}
	}
	void UI::SetInventorySelect(int num)
	{
		inventory_select = num;
	}
	void UI::MouseClickDown(CPoint point)
	{
		mouseX = point.x;
		mouseY = point.y;
		mouseClick = true;
		ClickSwitch();
	}
	void UI::MouseClickUp()
	{
		pageBtnClick = true;
		mouseClick = false;
	}
	bool UI::ClickInventory(CMovingBitmap inv)
	{
		if (mouseX > inv.Left() && mouseX < inv.Left() + inv.Width() && mouseY > inv.Top() && mouseY < inv.Top() + inv.Height())
			return true;
		else
			return false;
	}
	int UI::UseItem()
	{
		if (InventoryItem.size() != 0)
		{
			int size = InventoryItem.size();
			int select = inventory_select;
			bool compare = select < size;
			if (compare)
			{
				InventoryItem[inventory_select]->UseItema();
				return InventoryItem[inventory_select]->GetId();
			}
		}
		return -1;
	}

	void UI::deleteNonItem()
	{
		for (vector<Item*>::iterator i = InventoryItem.begin(); i < InventoryItem.end();)
		{
			if ((*i)->GetAmount() == 0)
			{
				delete(*i);
				InventoryItem.erase(i);
				break;
			}
			else
				i++;
		}
	}
	void UI::GetItem(int id, int amount)
	{
		if (HaveThisItem(id))
			for (vector<Item*>::iterator i = InventoryItem.begin(); i < InventoryItem.end(); i++)
			{
				if ((*i)->GetId() == id) (*i)->AddMount(amount);
			}
		else CreateItem(id, amount);
	}
	bool UI::HaveThisItem(int id)
	{
		for (vector<Item*>::iterator i = InventoryItem.begin(); i < InventoryItem.end(); i++)
			if ((*i)->GetId() == id) return true;
		
		return false;
	}
	bool UI::IsSeed()
	{
		if (InventoryItem[inventory_select]->GetId() == 2 || InventoryItem[inventory_select]->GetId() == 3)  return true;
		else return false;
	}
	void UI::ShowMoney()
	{
		moneyBar.SetTopLeft(SIZE_X - 300, clockBar.Top() + 65);
		moneyBar.ShowBitmap();
		moneyIcon.SetTopLeft(moneyBar.Left() + 16, moneyBar.Top() + 23);
		moneyIcon.ShowBitmap();
		CDC* pDC = CDDraw::GetBackCDC();			// 取得 Back Plain 的 CDC
		CFont f, *fp;
		f.CreatePointFont(140, "Microsoft JhengHei");	// 產生 font f; 150表示15 point的字
		fp = pDC->SelectObject(&f);					// 選用 font f
		pDC->SetBkColor(RGB(187, 144, 108));
		pDC->SetTextColor(RGB(255, 255, 255));
		char str[80];								// Demo 數字對字串的轉換
		sprintf(str, "%d", money);
		pDC->TextOut(moneyBar.Left() + 78, moneyBar.Top() + 23, str);
		pDC->SelectObject(fp);						// 放掉 font f (千萬不要漏了放掉)
		CDDraw::ReleaseBackCDC();					// 放掉 Back Plain 的 CDC}
	}
	bool UI::CostMoney(int _costMoney)
	{
		if (money - _costMoney >= 0)
		{
			money -= _costMoney;
			return true;
		}
		else return false;
	}
	void UI::GetMoney(int _getMoney)
	{
		money += _getMoney;
	}
	void UI::SellItem()
	{
		if (inventory_select < size)
		{
			switch (InventoryItem[inventory_select]->GetId())
			{
			case 2:
				MsgBox("You Sell 1 大麥種子 get 1$");
				money++;
				break;
			case 3:
				MsgBox("You Sell 1 玉米種子 get 1$");
				money++;
				break;
			case 50:
				MsgBox("You Sell 1 大麥 get 10$");
				money += 10;
				break;
			case 51:
				MsgBox("You Sell 1 玉米 get 30$");
				money += 30;
				break;
			case 100:
				MsgBox("You Sell 1 雞蛋 get 50$");
				money += 50;
				break;
			case 101:
				MsgBox("You Sell 1 羊毛 get 90$");
				money += 90;
				break;
			case 102:
				MsgBox("You Sell 1 牛奶 get 95$");
				money += 95;
				break;
			default:
				break;
			}
			InventoryItem[inventory_select]->AddMount(-1);
		}
	}
	void UI::ShowHowToPlay()
	{
		howToPlayBackground.SetTopLeft(SIZE_X - 330, moneyBar.Top() + 80);
		howToPlayBackground.ShowBitmap();
		CDC* pDC = CDDraw::GetBackCDC();			// 取得 Back Plain 的 CDC
		CFont f, *fp;
		f.CreatePointFont(130, "Microsoft JhengHei");	// 產生 font f; 150表示15 point的字
		fp = pDC->SelectObject(&f);					// 選用 font f
		pDC->SetBkColor(RGB(127, 165, 118));
		pDC->SetTextColor(RGB(255, 255, 255));
		char str[80];								// Demo 數字對字串的轉換
		sprintf(str, "Press ESC 回到遊戲");
		pDC->TextOut(SIZE_X - 310, moneyBar.Top() + 100, str);
		sprintf(str, "Press S 打開成就面板");
		pDC->TextOut(SIZE_X - 310, moneyBar.Top() + 123, str);
		sprintf(str, "Press X 挖掘土塊");
		pDC->TextOut(SIZE_X - 310, moneyBar.Top() + 146, str);
		sprintf(str, "Press Z 打開說明文件");
		pDC->TextOut(SIZE_X - 310, moneyBar.Top() + 169, str);
		sprintf(str, "Press C 種種子");
		pDC->TextOut(SIZE_X - 310, moneyBar.Top() + 192, str);
		sprintf(str, "Press D 採收產物");
		pDC->TextOut(SIZE_X - 310, moneyBar.Top() + 215, str);
		sprintf(str, "Press B 購買");
		pDC->TextOut(SIZE_X - 310, moneyBar.Top() + 238, str);
		sprintf(str, "Press V 販賣");
		pDC->TextOut(SIZE_X - 310, moneyBar.Top() + 261, str);
		pDC->SelectObject(fp);						// 放掉 font f (千萬不要漏了放掉)
		CDDraw::ReleaseBackCDC();					// 放掉 Back Plain 的 CDC}
	}
	void UI::MsgBox(string inputMsg)
	{
		msg = inputMsg;
		msgResetTime = 3 * 33;
	}
	void UI::Msg()
	{
		if (msgResetTime > 0)
		{
			int strLong = msg.length();
			CDC* pDC = CDDraw::GetBackCDC();			// 取得 Back Plain 的 CDC
			CFont f, *fp;
			f.CreatePointFont(130, "Microsoft JhengHei");	// 產生 font f; 150表示15 point的字
			fp = pDC->SelectObject(&f);					// 選用 font f
			pDC->SetBkColor(RGB(127, 165, 118));
			pDC->SetTextColor(RGB(255, 255, 255));
			char str[80];
			char msg2[80];
			strcpy(msg2, msg.c_str());
			sprintf(str, "%s", msg2);
			pDC->TextOut(SIZE_X - 310, SIZE_Y - 250, str);
			pDC->SelectObject(fp);						// 放掉 font f (千萬不要漏了放掉)
			CDDraw::ReleaseBackCDC();					// 放掉 Back Plain 的 CDC}
			msgResetTime--;
		}
	}
	void UI::ShowTool(int id, int x, int y)
	{
		switch (id)
		{
			case 0:
				axe.SetTopLeft(x, y);
				axe.ShowBitmap();
				break;
			case 1:
				bell.SetTopLeft(x, y);
				bell.ShowBitmap();
				break;
			case 2:
				box.SetTopLeft(x, y);
				box.ShowBitmap();
				break;
			case 3:
				hammer.SetTopLeft(x, y);
				hammer.ShowBitmap();
				break;
			case 4:
				hoe.SetTopLeft(x, y);
				hoe.ShowBitmap();
				break;
			case 5:
				milkMachine.SetTopLeft(x, y);
				milkMachine.ShowBitmap();
				break;
			case 6:
				rod.SetTopLeft(x, y);
				rod.ShowBitmap();
				break;
			case 7:
				scissor.SetTopLeft(x, y);
				scissor.ShowBitmap();
				break;
			case 8:
				sickle.SetTopLeft(x, y);
				sickle.ShowBitmap();
				break;
			case 9:
				WaterCan.SetTopLeft(x, y);
				WaterCan.ShowBitmap();
				break;
			default:
				break;
		}
	}
	void UI::ShowAllTool()
	{
		ShowTool(tool_select, 180, 635);
		if (tool_select == 0)
		{
			ShowTool(9, 107, 640);
		}
		else
		{
			ShowTool(tool_select - 1, 95, 635);
		}
		if (tool_select == 9)
		{
			ShowTool(0, 280, 640);
		}
		else
		{
			ShowTool(tool_select + 1, 270, 635);
		}
	}
	void UI::ClickSwitch()
	{
		if (mouseX > 60 && mouseX < 76 && mouseY > 650 && mouseX < 664)
			if (tool_select == 0) tool_select = 9;
			else tool_select--;
		if (mouseX > 334 && mouseX < 361 && mouseY > 643 && mouseX < 667)
			if (tool_select == 9) tool_select = 0;
			else tool_select++;
	}
	int UI::Gettool_select()
	{
		return tool_select;
	}
	int UI::ReturnMoney()
	{
		return money;
	}
	void UI::SetMouseXY(int _x, int _y)
	{
		msx = _x;
		msy = _y;
	}
	void UI::ShowChaItem()
	{
		if (msx > 184 && msx < 184 + 113 && msy >312 && msy < 312 + 91)
		{
			cropM.SetTopLeft(msx + 10, msy + 10);
			cropM.ShowBitmap();
		}
		if (msx > 387 && msx < 387 + 113 && msy >312 && msy < 312 + 91)
		{
			chickenM.SetTopLeft(msx + 10, msy + 10);
			chickenM.ShowBitmap();
		}
		if (msx > 583 && msx < 583 + 113 && msy >312 && msy < 312 + 91)
		{
			sheepM.SetTopLeft(msx + 10, msy + 10);
			sheepM.ShowBitmap();
		}
		if (msx > 779 && msx < 779 + 113 && msy >312 && msy < 312 + 91)
		{
			cowM.SetTopLeft(msx + 10, msy + 10);
			cowM.ShowBitmap();
		}
		if (msx > 972 && msx < 972 + 113 && msy >312 && msy < 312 + 91)
		{
			moneyPICM.SetTopLeft(msx + 10, msy + 10);
			moneyPICM.ShowBitmap();
		}
	}
	bool UI::GetGameOver()
	{
		return gameOver;
	}
	void UI::SetRunState()
	{
		gameOver = false;
		_state = gaming;
	
	}
}