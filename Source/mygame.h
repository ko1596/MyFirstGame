#include "UI.h"
#include "Map.h"
#include "Character.h"
#include "Menu.h"
#include "Challenge.h"
namespace game_framework
{
	enum AUDIO_ID  				// 定義各種音效的編號
	{
		AUDIO_LAKE,				// 1
		AUDIO_COW// 3
	};
	class CGameStateInit : public CGameState
	{
		public:
			CGameStateInit(CGame* g);
			void OnInit();  								// 遊戲的初值及圖形設定
			void OnKeyUp(UINT, UINT, UINT); 				// 處理鍵盤Up的動作
			void OnLButtonDown(UINT nFlags, CPoint point);  // 處理滑鼠的動作
			void OnLButtonUp(UINT nFlags, CPoint point);  // 處理滑鼠的動作
			void OnMouseMove(UINT nFlags, CPoint point);
		protected:
			void OnShow();									// 顯示這個狀態的遊戲畫面
		private:
			CMovingBitmap logo, btitle, menubackground;
			Menu initMenu;
	};
	class CGameStateRun : public CGameState
	{
		public:
			CGameStateRun(CGame* g);
			~CGameStateRun();
			void OnBeginState();							// 設定每次重玩所需的變數
			void OnInit();  								// 遊戲的初值及圖形設定
			void OnKeyDown(UINT, UINT, UINT);
			void OnKeyUp(UINT, UINT, UINT);
			void OnLButtonDown(UINT nFlags, CPoint point);  // 處理滑鼠的動作
			void OnLButtonUp(UINT nFlags, CPoint point);	// 處理滑鼠的動作
			void OnMouseMove(UINT nFlags, CPoint point);	// 處理滑鼠的動作
		protected:
			void OnMove();									// 移動遊戲元素
			void OnShow();									// 顯示這個狀態的遊戲畫面
		private:
			const int		NUMBALLS;	// 球的總數
			int GameTime;
			CMovingBitmap	background;	// 背景圖
			CMovingBitmap	help;		// 說明圖
			CMovingBitmap	corner;		// 角落圖
			CInteger		hits_left;	// 剩下的撞擊數
			Map				default_map;//宣告初始地圖
			Character		player;		//宣告玩家
			UI				ui;			//宣告ui
			Challenge		challenge;	//宣告成就系統
			bool doing;					//滑鼠是否點擊
	};
	class CGameStateOver : public CGameState
	{
		public:
			CGameStateOver(CGame* g);
			void OnBeginState();							// 設定每次重玩所需的變數
			void OnInit();
		protected:
			void OnMove();									// 移動遊戲元素
			void OnShow();									// 顯示這個狀態的遊戲畫面
		private:
			int counter;	// 倒數之計數器
			CMovingBitmap end;
	};
}