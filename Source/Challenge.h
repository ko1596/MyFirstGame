#ifndef CHALLENGE_H
#define CHALLENGE_H
namespace game_framework {
	class Challenge
	{
	public:
		Challenge();										//成就初始化
		void LoadBitmap();									//載入成就圖片
		void OnShow();										//成就圖片顯示
		void AddCount(int);									//成就計數
		void ChallengeCompletedCheck();						//檢查成就是否完成
		void SetMoney(int);									//設定成就中的金錢
		int GetState();										//取得目前成就進度
	private:
		CMovingBitmap crop, chicken, sheep, cow, money;		//各種成就圖片
		int stage;											//關卡進度
		int cropCount, chickenCount, sheepCount, cowCount;	//成就計數
		int ShowTime;										//顯示時間
		int ctm;											//遊戲中金錢
	};
}
#endif // !CHALLENGE_H