#include "Challenge.h"
namespace game_framework 
{
	enum action												//多個叫色行為
	{
		Dig, OpenBackpack, PressEsc, ToTalk, GrowCrop, Harvest, Buy, Sell
	};
	class UI;
	class Character
	{
	public:
		Character();										//腳色初始化
		virtual void LoadBitmap();							//腳色圖片載入
		virtual void OnShow();								//顯示腳色
		virtual void OnMove(Map*,UI*, Challenge*);			//腳色移動以及其他動作
		void KeyDown(direction);							//按下方向鍵
		void KeyDown(action);								//按下功能鍵
		void KeyUp(direction);								//放開方向鍵
		void KeyUp(action);									//放開功能鍵
		void AnimationShow(CAnimation, CMovingBitmap);		//腳色移動動畫								
	protected:
		CMovingBitmap WIdelD, WIdelL, WIdelU, WIdelR;		//腳色待命圖片
		int x, y,playerX,playerY;							//腳色位置
		bool moving;										//移動狀態
		bool doing;											//動作狀態
		bool growed, sell, buy, heav;						//判斷是否按下動作，避免重複觸發
		direction dire;										//腳色方向
		action act;											//腳色行為
		CAnimation animation_D;								//腳色動畫
		CAnimation animation_L;								//腳色動畫
		CAnimation animation_R;								//腳色動畫
		CAnimation animation_U;								//腳色動畫
		int moveact;										//腳色移動加權，可同時多按鍵走路的判斷數
		int up = 0, down = 0, left = 0, right = 0;			//個方向加權
	};
}