#include "Businessman.h"
#include "Animals.h"
namespace game_framework
{
	class Crop;
	class Chicken;
	class Map
		{
			public:
				Map();							//地圖初始化
				~Map();							//刪除地圖物件
				void LoadBitmap();				//載入地圖圖片
				void OnShow();					//顯示地圖圖片
				void Update(int, int, int);		//腳色更新地圖
				bool IsEmpty(int, int);			//路障
				bool AnimalsJail(int, int);		//動物路障
				void SetScreenXY(int, int);		//設定螢幕顯示
				void SetObjectXY(int*, int*);	//設定地圖物件位置
				void GrowCrop(int, int, int);	//種種子
				bool IsDrit(int, int);			//判斷是否是泥土
				bool IsCrop(int, int);			//判斷作物
				int HarvestCrops(int, int);		//採收植物
				bool IsMatureCrop(int, int);	//判斷是否成熟
				int BuyProduct(int, int);		//購買物品
				bool IsProduct(int, int);		//判斷是否可以購買物品
				bool IsSeller(int, int);		//判斷是否為商人
				void AddChicken(int, int);		//在地圖創建雞物件
				void AddCow(int, int);			//在地圖創建牛物件
				void AddSheep(int, int);		//在地圖創建羊物件
				void SpawnEgg();				//在地圖創建蛋
				void HarvestEgg(int, int);		//玩家採收蛋
				bool IsEgg(int, int);			//判斷是否為蛋
				bool IsSheep(int, int);			//判斷是否為羊
				bool IsCow(int, int);			//判斷是否為牛
				void ShowHouse();				//顯示房子遮罩
				void SetPlayerXY(int, int);		//設定玩家位置
			protected:
				CMovingBitmap grass, dryDirt, Bush1, Bush2;
				CMovingBitmap egg, test, Fence, Fence_Back, Fence_LUnder, Fence_LUp, Fence_RUnder, Fence_RUp, Fence_Str;
				CMovingBitmap store, store_house, Chicken_House, ChHouse_Gnd, ChHouse_Wall, ChHouse_Feedbox1, ChHouse_Feedbox2, ChHouse_Feedbox3; // 商店
				CMovingBitmap home_house, HmFood, HmGnd, HmKettle, HmNst, HmTV, HmWallBtm, HmWall;	// 家
				CMovingBitmap Tool_axe, Tool_bell, Tool_hammer, Tool_hoe, Tool_milkMachine, Tool_rod, Tool_scissor, Tool_sickle, Tool_WtrCan;	// 工具
				CMovingBitmap Tool_box;	// 放置型工具
				CMovingBitmap Road_Center, Road_CDown, Road_CUp, Road_CLeft, Road_CRight,  Road_LDownCorner, Road_LUpCorner, Road_RDownCorner, Road_RUpCorner;	// 路
				Businessman bus;				//商人
				CMovingBitmap MainPoint;		//提示地點
				int map[100][100];				//地圖陣列
				int mapObject[100][100];		//地圖物件陣列
				int X, Y;						//地圖背景繪製用xy
				int sx, sy;						//螢幕位置
				int playerX, playerY;			//玩家位置
				int time;						//隨機樹產生用
				vector<Crop*> map_Crop;			//地圖上的作物陣列
				vector<Animals*> map_Animals;	//地圖上的動物陣列
				bool crop_created;				//查看地圖作物是否已採收
		};
}