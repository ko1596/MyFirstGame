#include "Animals.h"
namespace game_framework 
{
	class Chicken:public Animals
	{
	public:
		Chicken(int, int);		//機的位置初始化
		void LoadBitmap();		//載入雞得圖片
		bool AddEgg();			//判斷雞下蛋
	protected:
		int spawnEggTime;		//雞下蛋時間
	};
}