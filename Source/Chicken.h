#include "Animals.h"
namespace game_framework 
{
	class Chicken:public Animals
	{
	public:
		Chicken(int, int);		//������m��l��
		void LoadBitmap();		//���J���o�Ϥ�
		bool AddEgg();			//�P�_���U�J
	protected:
		int spawnEggTime;		//���U�J�ɶ�
	};
}