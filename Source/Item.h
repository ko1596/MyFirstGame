namespace game_framework {
	class Item
	{
	public:
		Item(int,int);				//��l�ƪ��~
		void LoadBitmap();			//���~���J�Ϥ�
		void OnShow();				//��ܪ��~�Ϥ�
		void SetXY(int, int);		//�]�w���~��m
		int GetAmount();			//���o���~�ƶq
		int GetId();				//���o���~id
		bool GetImgLoaded();		//�T�{�O�_���J���~�Ϥ�
		void UseItema();			//�ϥΪ��~
		void AddMount(int);			//���ܪ��~�ƶq
	private:
		int x, y;					//���~��ܮy��
		int id,amount;				//���~id�μƶq
		CMovingBitmap ItemImg;		//���~�Ϥ�
		bool ImgLoaded;				//�P�_�O�_���J�Ϥ�
	};
}