namespace game_framework 
{
	class Crop
	{
	public:
		Crop(int,int,int);				//�@����l��
		void LoadBitmap();				//�@���Ϥ����J
		void OnShow(int, int);			//��ܧ@��
		void SetXY(int, int);			//�]�w�@����m
		bool GetImgLoaded();			//�P�w�O�_�w�g���J�Ϥ�
		void Grow();					//�Ӫ��ش�
		int GetX();						//���o�Ӫ�X�y��
		int GetY();						//���o�Ӫ�Y�y��
		int GetId();					//���o�Ӫ�id
		int GetState();					//���o�@���ͪ����A
	private:
		int x, y;						//�Ӫ��y��
		int id;							//�Ӫ�id
		int state;						//�Ӫ��ͪ����A
		CMovingBitmap cropPicture[5];	//�Ӫ��ͪ����A�����i�Ϥ�
		bool ImgLoaded;					//�P�_�Ӫ��Ϥ��O�_���J
		int growTime,maxGrowTime;		//�ͪ��ɶ�
	};
}