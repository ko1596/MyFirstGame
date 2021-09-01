namespace game_framework
{
	enum Buttom										//選取的按鈕
	{
		startGame, endGame, Option, nothing
	};
	class Menu
	{
		public:
			Menu();									//首頁選單初始化
			void LoadBitmap();						//載入選單圖片
			void OnShow();							//顯示選單圖片
			bool MouseOnButton(CMovingBitmap);		//判斷是否滑鼠在按鈕上
			void ChangeButtonImage(Buttom);			//改變圖片按鈕
			void GetMouse(CPoint);					//取得滑鼠座標
			void MouseClickDown();					//滑鼠按下去
			void MouseClickUp();					//滑鼠放開
			int GetButtonState();					//取得按鈕狀態
			void OpenAboutMenu();					//開啟關於頁面
			void CloseAboutMenu();					//關閉關於頁面
		protected:
			CMovingBitmap playButton[3], optionButton[3], exitButton[3];		//遊玩，關於，離開的按鈕
			CMovingBitmap  btitle, menubackground, about;						//背景圖片 標題 關於
			Buttom ButtonState;						//選到哪個按鈕
			int mouse_x, mouse_y;					//滑鼠位置
			bool imageLoaded;						//檢查圖片是否載入
			bool mouse_Click;						//圖片是否點擊
			bool ShowAbout;							//是否顯示關於
	};
}