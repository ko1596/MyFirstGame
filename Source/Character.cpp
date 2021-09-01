#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "UI.h"
#include "Map.h"
#include "Character.h"
#define PLAYER_X 625
#define PLAYER_Y 350
namespace game_framework {
	Character::Character() :playerX(700), playerY(500),moving(false),dire(Down), growed(false),sell(false), buy(false), heav(false) {}
	void Character::LoadBitmap()
	{
		WIdelD.LoadBitmap(IDB_MCD1, RGB(255, 255, 255));
		WIdelU.LoadBitmap(IDB_MCU1, RGB(255, 255, 255));
		WIdelL.LoadBitmap(IDB_MCL1, RGB(255, 255, 255));
		WIdelR.LoadBitmap(IDB_MCR1, RGB(255, 255, 255));
		char *filename[4] = { ".\\asset\\Picture\\MC_W_D1.bmp",".\\asset\\Picture\\MC_W_D2.bmp",".\\asset\\Picture\\MC_W_D3.bmp",".\\asset\\Picture\\MC_W_D4.bmp" };
		char *filename2[4] = { ".\\asset\\Picture\\MC_W_L1.bmp",".\\asset\\Picture\\MC_W_L2.bmp",".\\asset\\Picture\\MC_W_L3.bmp",".\\asset\\Picture\\MC_W_L4.bmp" };
		char *filename3[4] = { ".\\asset\\Picture\\MC_W_R1.bmp",".\\asset\\Picture\\MC_W_R2.bmp",".\\asset\\Picture\\MC_W_R3.bmp",".\\asset\\Picture\\MC_W_R4.bmp" };
		char *filename4[4] = { ".\\asset\\Picture\\MC_W_U1.bmp",".\\asset\\Picture\\MC_W_U2.bmp",".\\asset\\Picture\\MC_W_U3.bmp",".\\asset\\Picture\\MC_W_U4.bmp" };
		for (int i = 0; i < 4; i++)	// 載入動畫(由4張圖形構成)
		{
			animation_D.AddBitmap(filename[i], RGB(255, 255, 255));
			animation_L.AddBitmap(filename2[i], RGB(255, 255, 255));
			animation_R.AddBitmap(filename3[i], RGB(255, 255, 255));
			animation_U.AddBitmap(filename4[i], RGB(255, 255, 255));
		}
	}
	void Character::OnShow()
	{
		switch (dire)
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
	void Character::OnMove(Map* m,UI* ui, Challenge* cha)
	{
		cha->SetMoney(ui->ReturnMoney());
		moveact = up + down + left + right;
		if (moveact)
		{
			switch (dire)
			{
			case game_framework::Up:
				if (!m->IsEmpty(playerX, playerY - 3))
				{
					playerY -= 3;
					animation_U.OnMove();
				}
				break;
			case game_framework::Down:
				if (!m->IsEmpty(playerX, playerY + 3))
				{
					playerY += 3;
					animation_D.OnMove();
				}
				break;
			case game_framework::Left:
				if (!m->IsEmpty(playerX - 3, playerY))
				{
					playerX -= 3;
					animation_L.OnMove();
				}
				break;
			case game_framework::Right:
				if (!m->IsEmpty(playerX + 3, playerY))
				{
					playerX += 3;
					animation_R.OnMove();
				}
				break;
			default:
				break;
			}
		}
		if (playerX < 0) playerX = 0;
		if (playerY < 0) playerY = 0;
		if (playerX > 625) x = playerX - 625;
		if (playerY > 350) y = playerY - 350;
		m->SetScreenXY(x, y);
		m->SetPlayerXY(playerX, playerY);
		if (doing)
		{
			int fixX, fixY;
			if (playerX > 625) fixX = 625;
			else fixX = playerX;
			if (playerY > 350) fixY = 350;
			else fixY = playerY;
			switch (act)
			{
			case game_framework::Dig:
				if(ui->Gettool_select()==4)
					m->Update(playerX, playerY, 1);
				else ui->MsgBox("你用錯工具了");
				break;
			case game_framework::OpenBackpack:
				ui->ChangeState(backpack);
				break;
			case game_framework::PressEsc:
				ui->ChangeState(Esc);
				break;
			case game_framework::ToTalk:
				ui->ChangeState(talk);
				break;
			case game_framework::GrowCrop:
				if (!growed)
				{
					if (m->IsDrit(playerX, playerY))
					{
						if (ui->IsSeed())
						{
							m->Update(playerX, playerY, ui->UseItem());
							ui->MsgBox("你種了一個作物");
						}
					}
					else  ui->MsgBox("這裡不能種東西");	
					growed = true;
				}
				break;
			case game_framework::Harvest:
				if (!heav)
				{
					if (m->IsMatureCrop(playerX, playerY))
					{
						if (ui->Gettool_select() == 8)
						{
							int id = m->HarvestCrops(playerX, playerY);
							ui->MsgBox("你採收了一個作物");
							if (id == 2) ui->GetItem(50, 1);
							if (id == 3) ui->GetItem(51, 1);
							cha->AddCount(1);
						}
						else ui->MsgBox("你用錯工具了");
					}
					if (m->IsEgg(playerX, playerY))
					{
						ui->MsgBox("採收了一顆蛋");
						m->HarvestEgg(playerX, playerY);
						ui->GetItem(100, 1);
					}
					if (m->IsSheep(playerX, playerY))
					{
						if (ui->Gettool_select() == 7)
							ui->GetItem(101, 1);
						else ui->MsgBox("用錯工具了");
					}
					if (m->IsCow(playerX, playerY))
					{
						if (ui->Gettool_select() == 5)
							ui->GetItem(102, 1);
						else ui->MsgBox("用錯工具了");
					}
					heav = true;
				}
				break;
			case game_framework::Buy:
				if (!buy)
				{
					if (m->IsProduct(playerX, playerY))
					{
						int id = m->BuyProduct(playerX, playerY);

						if (id == 2)
						{
							if (ui->CostMoney(1))
							{
								ui->GetItem(2, 1);
								ui->MsgBox("你買了大麥子");
							}
						}
						if (id == 3)
						{
							if (ui->CostMoney(1))
							{
								ui->GetItem(3, 1);
								ui->MsgBox("你買了玉米種子");
							}
						}
						if (id == 4)
						{
							if (ui->CostMoney(100))
							{
								m->AddChicken(32 * 7, 32 * 27);
								ui->MsgBox("雞舍變更吵了");
								cha->AddCount(2);
							}
							else ui->MsgBox("你根本買不起這隻雞 他要100元");
						}
						if (id == 5)
						{
							if (ui->CostMoney(3000))
							{
								m->AddCow(32 * 20, 32 * 27);
								cha->AddCount(4);
								ui->MsgBox("牧場裡的牛多了一隻");
							}
							else ui->MsgBox("你根本買不起這隻牛 他要3000元");
						}
						if (id == 6)
						{
							if (ui->CostMoney(2000))
							{
								m->AddSheep(32 * 20, 32 * 27);
								cha->AddCount(3);
								ui->MsgBox("羊已經被丟到外面了");
							}
							else ui->MsgBox("你根本買不起這隻羊 他要2000元"); 
						}
					}
					buy = true;
				}
				break;
			case game_framework::Sell:
				if (!sell)
				{
					if (m->IsSeller(playerX, playerY))
						ui->SellItem();
					sell = true;
				}
				break;
			default:
				break;
			}
		}
	}
	void Character::KeyDown(direction _dire)
	{
		moving = true;
		dire = _dire;
		if (dire == Up) up = 1;
		if (dire == Down) down = 1;
		if (dire == Left) left = 1;
		if (dire == Right) right = 1;
		CAudio::Instance()->Play(8, true);
	}
	void Character::KeyDown(action _act)
	{
		doing = true;
		act = _act;
	}
	void Character::KeyUp(direction _dire)
	{
		if (_dire == Up) up = 0;
		if (_dire == Down) down = 0;
		if (_dire == Left) left = 0;
		if (_dire == Right) right = 0;
		moving = false;
	}
	void Character::KeyUp(action _act)
	{
		doing = false;

		if (_act == GrowCrop) growed = false;
		if (_act == Harvest) heav = false;
		if (_act == Buy) buy = false;
		if (_act == Sell) sell = false;
	}
	void Character::AnimationShow(CAnimation move, CMovingBitmap idel)
	{
		int fixX, fixY;

		if (playerX > 609) fixX = 609;
		else fixX = playerX - 16;
		if (playerY > 320) fixY = 320;
		else fixY = playerY - 25;

		if (moving)
		{
			move.SetTopLeft(fixX, fixY);
			move.OnShow();
		}
		else
		{
			idel.SetTopLeft(fixX, fixY);
			idel.ShowBitmap();
			CAudio::Instance()->Play(8, false);
		}
	}
}