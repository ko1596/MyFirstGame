#ifndef CHALLENGE_H
#define CHALLENGE_H
namespace game_framework {
	class Challenge
	{
	public:
		Challenge();										//���N��l��
		void LoadBitmap();									//���J���N�Ϥ�
		void OnShow();										//���N�Ϥ����
		void AddCount(int);									//���N�p��
		void ChallengeCompletedCheck();						//�ˬd���N�O�_����
		void SetMoney(int);									//�]�w���N��������
		int GetState();										//���o�ثe���N�i��
	private:
		CMovingBitmap crop, chicken, sheep, cow, money;		//�U�ئ��N�Ϥ�
		int stage;											//���d�i��
		int cropCount, chickenCount, sheepCount, cowCount;	//���N�p��
		int ShowTime;										//��ܮɶ�
		int ctm;											//�C��������
	};
}
#endif // !CHALLENGE_H