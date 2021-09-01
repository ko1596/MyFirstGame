#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Menu.h"
#define BUTTON_LEFT_WIDTH 100
#define BUTTON1_TOP_HEIGHT 300
#define BUTTON2_TOP_HEIGHT 400
#define BUTTON3_TOP_HEIGHT 500
namespace game_framework
{
	Menu::Menu(): mouse_x(0), mouse_y(0), ButtonState(nothing), imageLoaded(false), mouse_Click(false), ShowAbout(false) {}
	void Menu::LoadBitmap()
	{
		btitle.LoadBitmap(IDB_BTitle, RGB(255, 255, 255));
		menubackground.LoadBitmap(IDB_MENUBACKGROUND);
		playButton[0].LoadBitmap(IDB_B_S, RGB(255, 255, 255));
		playButton[1].LoadBitmap(IDB_B_S_H, RGB(255, 255, 255));
		playButton[2].LoadBitmap(IDB_B_S_C, RGB(255, 255, 255));
		optionButton[0].LoadBitmap(IDB_B_O, RGB(255, 255, 255));
		optionButton[1].LoadBitmap(IDB_B_O_H, RGB(255, 255, 255));
		optionButton[2].LoadBitmap(IDB_B_O_C, RGB(255, 255, 255));
		exitButton[0].LoadBitmap(IDB_B_E, RGB(255, 255, 255));
		exitButton[1].LoadBitmap(IDB_B_E_H, RGB(255, 255, 255));
		exitButton[2].LoadBitmap(IDB_B_E_C, RGB(255, 255, 255));
		imageLoaded = true;
		about.LoadBitmap(IDB_B_About, RGB(255, 255, 255));
	}
	void Menu::OnShow()
	{
		menubackground.SetTopLeft(0, 0);
		menubackground.ShowBitmap();
		btitle.SetTopLeft((SIZE_X - btitle.Width()) / 2, SIZE_Y - 50);
		btitle.ShowBitmap();

		if (imageLoaded)
		{
			int mouseState = 0;
			if (MouseOnButton(playButton[0]) && mouse_Click)
			{
				mouseState = 2;
				ButtonState = startGame;
			}
			else if (MouseOnButton(playButton[0])) mouseState = 1;
			else mouseState = 0;
			playButton[mouseState].SetTopLeft((SIZE_X - playButton[mouseState].Width()) / 2, BUTTON1_TOP_HEIGHT);
			playButton[mouseState].ShowBitmap();
			if (MouseOnButton(optionButton[0]) && mouse_Click)
			{
				mouseState = 2;
				ButtonState = Option;
			}
			else if (MouseOnButton(optionButton[0])) mouseState = 1;
			else mouseState = 0;
			optionButton[mouseState].SetTopLeft((SIZE_X - optionButton[mouseState].Width()) / 2, BUTTON2_TOP_HEIGHT);
			optionButton[mouseState].ShowBitmap();
			if (MouseOnButton(exitButton[0]) && mouse_Click)
			{
				mouseState = 2;
				ButtonState = endGame;
			}
			else if (MouseOnButton(exitButton[0])) mouseState = 1;
			else mouseState = 0;
			exitButton[mouseState].SetTopLeft((SIZE_X - exitButton[mouseState].Width()) / 2, BUTTON3_TOP_HEIGHT);
			exitButton[mouseState].ShowBitmap();
			if (ShowAbout)
			{
				about.SetTopLeft(0, 0);
				about.ShowBitmap();
			}
			CloseAboutMenu();
		}
	}
	void Menu::ChangeButtonImage(Buttom but)
	{
		ButtonState = but;
	}
	bool Menu::MouseOnButton(CMovingBitmap pict)
	{
		if (mouse_x > pict.Left() && mouse_x < pict.Width() + pict.Left() && mouse_y > pict.Top() && mouse_y < pict.Top() + pict.Height())
			return true;
		else
			return false;
	}
	void Menu::GetMouse(CPoint posi)
	{
		mouse_x = posi.x;
		mouse_y = posi.y;
	}
	void Menu::MouseClickDown()
	{
		mouse_Click = true;
	}
	void Menu::MouseClickUp()
	{
		mouse_Click = false;
	}
	int Menu::GetButtonState()
	{
		switch (ButtonState)
		{
			case game_framework::startGame:
				return 0;
				break;

			case game_framework::endGame:
				return 1;
				break;

			case game_framework::Option:
				return 2;
				break;

			case game_framework::nothing:
				return 3;
				break;
			default:
				return 3;
				break;
		}
	}
	void Menu::OpenAboutMenu()
	{
		ShowAbout = true;
	}
	void Menu::CloseAboutMenu()
	{
		if (mouse_Click && mouse_x > 1191 && mouse_x < 1236 && mouse_y > 2 && mouse_y < 44)
		{
			ShowAbout = false;
			ButtonState = nothing;
		}
	}
}
