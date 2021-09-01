namespace game_framework 
{
	class Crop
	{
	public:
		Crop(int,int,int);				//﹍て
		void LoadBitmap();				//瓜更
		void OnShow(int, int);			//陪ボ
		void SetXY(int, int);			//砞﹚竚
		bool GetImgLoaded();			//﹚琌竒更瓜
		void Grow();					//从贺从
		int GetX();						//眔从X畒夹
		int GetY();						//眔从Y畒夹
		int GetId();					//眔从id
		int GetState();					//眔ネ篈
	private:
		int x, y;						//从畒夹
		int id;							//从id
		int state;						//从ネ篈
		CMovingBitmap cropPicture[5];	//从ネ篈き眎瓜
		bool ImgLoaded;					//耞从瓜琌更
		int growTime,maxGrowTime;		//ネ丁
	};
}