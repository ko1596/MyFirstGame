namespace game_framework
{
	class Businessman
	{
	public:
		Businessman();					//�ӤH��l��
		virtual void LoadBitmap();		//�ӤH�Ϥ�load
		virtual void OnShow(int,int);	//��ܰӤH
	protected:
		int x, y;						//�ӤH��m
		CAnimation animation_Idel;		//�ӤH�R��ʵe
	};
}