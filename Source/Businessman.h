namespace game_framework
{
	class Businessman
	{
	public:
		Businessman();					//商人初始化
		virtual void LoadBitmap();		//商人圖片load
		virtual void OnShow(int,int);	//顯示商人
	protected:
		int x, y;						//商人位置
		CAnimation animation_Idel;		//商人靜止動畫
	};
}