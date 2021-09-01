#ifndef ANIMALS_H
#define ANIMALS_H
namespace game_framework {
	enum direction
	{
		Up, Down, Left, Right  //�C�|���O��0,1,2,3
	};
	class Animals
	{
	public:
		Animals(int,int,int);							//�ʪ���l��
		void OnShow(int,int);							//��ܰʪ�
		void OnMove() ;									//�ʪ�������
		void AnimationShow(CAnimation, CMovingBitmap);	//��ܰʪ����ʵe
		void Sound();									//�ʪ����n��
		int GetX();										//�����ʪ���X�y��
		int GetY();										//�����ʪ���Y�y��
		virtual bool AddEgg();							//���W�����\�� ��L���غü{return false
		int GetIngX();									//���o�Ϥ��e��
		int GetIngY();									//���o�Ϥ�����
		void SetWup(bool);								//���W����P�w
		void SetWdown(bool);							//���U����P�w
		void SetWleft(bool);							//��������P�w
		void SetWright(bool);							//���k����P�w
		int GetSoundId();								//���������n��ID
	protected:
		CMovingBitmap WIdelD, WIdelL, WIdelU, WIdelR;	//�ʪ��ݩR�Ϥ�
		int x, y;										//�ʪ��y��
		int sx, sy;										//�ù��y��
		int sec;										//�ʪ����ʬ��
		int countStep, walkStep;						//�ʪ��ݲ��ʨB�ơA�ʪ��w���ʨB��
		int soundsec,checkSound;						//�ʪ��s�n��ơA�ʪ��w�s�X��
		int soundID;									//�ʪ�ID
		direction dire;									//�ʪ���V
		CAnimation animation_D;							//�ʪ��V�U�ʵe
		CAnimation animation_L;							//�ʪ��V���ʵe
		CAnimation animation_R;							//�ʪ��V�k�ʵe
		CAnimation animation_U;							//�ʪ��V�W�ʵe
		bool moving,Wup,Wdown,Wleft,Wright;				//�P�_�O�_�����A�P�_����
	};
}
#endif // !ANIMALS_H