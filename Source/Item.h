namespace game_framework {
	class Item
	{
	public:
		Item(int,int);				//初始化物品
		void LoadBitmap();			//物品載入圖片
		void OnShow();				//顯示物品圖片
		void SetXY(int, int);		//設定物品位置
		int GetAmount();			//取得物品數量
		int GetId();				//取得物品id
		bool GetImgLoaded();		//確認是否載入物品圖片
		void UseItema();			//使用物品
		void AddMount(int);			//更變物品數量
	private:
		int x, y;					//物品顯示座標
		int id,amount;				//物品id及數量
		CMovingBitmap ItemImg;		//物品圖片
		bool ImgLoaded;				//判斷是否載入圖片
	};
}