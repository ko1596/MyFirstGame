#include "Animals.h"
namespace game_framework
{
	class Sheep :public Animals			//�~�Ӱʪ��ݩ�
	{
	public:
		Sheep(int, int);				//��l�ƦϪ���m
		void LoadBitmap();				//���J�Ϫ��Ϥ�
	};
}