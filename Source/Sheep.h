#include "Animals.h"
namespace game_framework
{
	class Sheep :public Animals			//繼承動物屬性
	{
	public:
		Sheep(int, int);				//初始化羊的位置
		void LoadBitmap();				//載入羊的圖片
	};
}