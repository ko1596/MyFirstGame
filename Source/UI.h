#include "Challenge.h"
namespace game_framework {
	enum state								//遊戲ui顯示狀態
	{
		Esc, backpack, talk, gaming,over
	};
	class Map;
	class Item;
	class UI
	{
	public:
		UI();								//ui初始化
		~UI();								//刪除物品
		void LoadBitmap();					//載入ui圖片
		void OnShow(int, Challenge*);		//顯示ui畫面
		void ChangeState(state);			//切換ui狀態
		void ShowTime(int);					//顯示時間
		void CreateItem(int,int);			//新增物品
		void ShowItem();					//顯示物品
		void SetInventorySelect(int);		//設定物品欄選取位置
		void MouseClickDown(CPoint);		//滑鼠點擊
		void MouseClickUp();				//滑鼠放開
		bool ClickInventory(CMovingBitmap);	//點擊物品欄
		int UseItem();						//使用物品
		void deleteNonItem();				//刪除物品
		void GetItem(int, int);				//獲得物品
		bool HaveThisItem(int);				//是否已擁有物品
		bool IsSeed();						//是否手上有種子
		void ShowMoney();					//顯示金錢
		bool CostMoney(int);				//花費金錢
		void GetMoney(int);					//取得金錢
		void SellItem();					//販賣物品
		void ShowHowToPlay();				//顯示按鍵提示
		void MsgBox(string);				//輸入提示訊息
		void Msg();							//顯示提示訊息
		void ShowTool(int, int, int);		//顯示單個工具
		void ShowAllTool();					//控制所有工具
		void ClickSwitch();					//點擊工具切換按鈕
		int Gettool_select();				//取得目前選取工具id
		int ReturnMoney();					//取得金錢
		void SetMouseXY(int, int);			//設定滑鼠位置
		void ShowChaItem();					//顯示成就
		bool GetGameOver();					//設定遊戲結束
		void SetRunState();					//設定遊戲狀態
	protected:
		CMovingBitmap inventory[9];																		//物品欄圖片
		CMovingBitmap inventorySelect;																	//物品欄選擇
		CMovingBitmap inventory_line,clockBar;															//工具欄
		CMovingBitmap inventory_mainuse, inventory_use1, inventory_use2;								//左中右工具欄圓圈														
		CMovingBitmap moneyBar, moneyIcon, howToPlayBackground;											//金錢列 金幣圖示 遊戲按鍵背景
		CMovingBitmap axe, bell, box, hammer, hoe, milkMachine, rod, scissor, sickle, WaterCan;			//各種工具圖片
		CMovingBitmap none,crop, chicken, sheep, cow, moneyPIC;											//各種成就圖片
		CMovingBitmap cropM, chickenM, sheepM, cowM, moneyPICM;											//各種滑鼠跟隨成就圖片
		CMovingBitmap overImg, overImgOver, overImgKeep;												//是否結束遊戲
		CMovingBitmap page1, page2, page3, page4, page5;												//遊戲介紹頁面
		state _state,lastState;					//遊戲ui狀態
		vector<Item*> InventoryItem;			//物品欄陣列
		string msg;								//資訊欄
		int inventory_select, tool_select;		//物品欄工具欄選擇id
		int mouseX, mouseY;						//滑鼠位置
		bool mouseClick;						//滑鼠是否點擊
		int money;								//玩家金錢	
		int msgResetTime;						//訊息重置時間
		int size;								//物品欄大小
		int msx, msy;							//滑鼠位置
		int overcount;							//完成所有成就 跳出是否結束的倒數
		bool StartOverCount;					//是否開始結束倒數
		int changePageTime;						//換頁音效撥放時間
		bool gameOver;							//遊戲是否結束
		int page;								//目前遊戲介紹頁面
		bool pageBtnClick;						//切換頁數按鈕
	};
}
