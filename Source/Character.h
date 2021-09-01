#include "Challenge.h"
namespace game_framework 
{
	enum action												//�h�ӥs��欰
	{
		Dig, OpenBackpack, PressEsc, ToTalk, GrowCrop, Harvest, Buy, Sell
	};
	class UI;
	class Character
	{
	public:
		Character();										//�}���l��
		virtual void LoadBitmap();							//�}��Ϥ����J
		virtual void OnShow();								//��ܸ}��
		virtual void OnMove(Map*,UI*, Challenge*);			//�}�Ⲿ�ʥH�Ψ�L�ʧ@
		void KeyDown(direction);							//���U��V��
		void KeyDown(action);								//���U�\����
		void KeyUp(direction);								//��}��V��
		void KeyUp(action);									//��}�\����
		void AnimationShow(CAnimation, CMovingBitmap);		//�}�Ⲿ�ʰʵe								
	protected:
		CMovingBitmap WIdelD, WIdelL, WIdelU, WIdelR;		//�}��ݩR�Ϥ�
		int x, y,playerX,playerY;							//�}���m
		bool moving;										//���ʪ��A
		bool doing;											//�ʧ@���A
		bool growed, sell, buy, heav;						//�P�_�O�_���U�ʧ@�A�קK����Ĳ�o
		direction dire;										//�}���V
		action act;											//�}��欰
		CAnimation animation_D;								//�}��ʵe
		CAnimation animation_L;								//�}��ʵe
		CAnimation animation_R;								//�}��ʵe
		CAnimation animation_U;								//�}��ʵe
		int moveact;										//�}�Ⲿ�ʥ[�v�A�i�P�ɦh���䨫�����P�_��
		int up = 0, down = 0, left = 0, right = 0;			//�Ӥ�V�[�v
	};
}