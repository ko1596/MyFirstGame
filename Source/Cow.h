#include "Animals.h"
namespace game_framework {
	class Cow :public Animals	//繼承動物行為
	{
	public:
		Cow(int, int);			//初始化牛的位置
		void LoadBitmap();		//載入圖片
	};
}