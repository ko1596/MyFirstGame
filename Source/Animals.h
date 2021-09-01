#ifndef ANIMALS_H
#define ANIMALS_H
namespace game_framework {
	enum direction
	{
		Up, Down, Left, Right  //列舉型別為0,1,2,3
	};
	class Animals
	{
	public:
		Animals(int,int,int);							//動物初始化
		void OnShow(int,int);							//顯示動物
		void OnMove() ;									//動物的移動
		void AnimationShow(CAnimation, CMovingBitmap);	//顯示動物的動畫
		void Sound();									//動物的聲音
		int GetX();										//取的動物的X座標
		int GetY();										//取的動物的Y座標
		virtual bool AddEgg();							//雞獨有的功能 其他物種疑慮return false
		int GetIngX();									//取得圖片寬度
		int GetIngY();									//取得圖片高度
		void SetWup(bool);								//往上撞牆判定
		void SetWdown(bool);							//往下撞牆判定
		void SetWleft(bool);							//往左撞牆判定
		void SetWright(bool);							//往右撞牆判定
		int GetSoundId();								//取的物種聲音ID
	protected:
		CMovingBitmap WIdelD, WIdelL, WIdelU, WIdelR;	//動物待命圖片
		int x, y;										//動物座標
		int sx, sy;										//螢幕座標
		int sec;										//動物移動秒數
		int countStep, walkStep;						//動物需移動步數，動物已移動步數
		int soundsec,checkSound;						//動物叫聲秒數，動物已叫幾秒
		int soundID;									//動物ID
		direction dire;									//動物方向
		CAnimation animation_D;							//動物向下動畫
		CAnimation animation_L;							//動物向左動畫
		CAnimation animation_R;							//動物向右動畫
		CAnimation animation_U;							//動物向上動畫
		bool moving,Wup,Wdown,Wleft,Wright;				//判斷是否走路，判斷撞牆
	};
}
#endif // !ANIMALS_H