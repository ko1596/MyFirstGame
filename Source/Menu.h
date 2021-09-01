namespace game_framework
{
	enum Buttom										//��������s
	{
		startGame, endGame, Option, nothing
	};
	class Menu
	{
		public:
			Menu();									//��������l��
			void LoadBitmap();						//���J���Ϥ�
			void OnShow();							//��ܿ��Ϥ�
			bool MouseOnButton(CMovingBitmap);		//�P�_�O�_�ƹ��b���s�W
			void ChangeButtonImage(Buttom);			//���ܹϤ����s
			void GetMouse(CPoint);					//���o�ƹ��y��
			void MouseClickDown();					//�ƹ����U�h
			void MouseClickUp();					//�ƹ���}
			int GetButtonState();					//���o���s���A
			void OpenAboutMenu();					//�}�����󭶭�
			void CloseAboutMenu();					//�������󭶭�
		protected:
			CMovingBitmap playButton[3], optionButton[3], exitButton[3];		//�C���A����A���}�����s
			CMovingBitmap  btitle, menubackground, about;						//�I���Ϥ� ���D ����
			Buttom ButtonState;						//�����ӫ��s
			int mouse_x, mouse_y;					//�ƹ���m
			bool imageLoaded;						//�ˬd�Ϥ��O�_���J
			bool mouse_Click;						//�Ϥ��O�_�I��
			bool ShowAbout;							//�O�_�������
	};
}