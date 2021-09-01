#include "Businessman.h"
#include "Animals.h"
namespace game_framework
{
	class Crop;
	class Chicken;
	class Map
		{
			public:
				Map();							//�a�Ϫ�l��
				~Map();							//�R���a�Ϫ���
				void LoadBitmap();				//���J�a�ϹϤ�
				void OnShow();					//��ܦa�ϹϤ�
				void Update(int, int, int);		//�}���s�a��
				bool IsEmpty(int, int);			//����
				bool AnimalsJail(int, int);		//�ʪ�����
				void SetScreenXY(int, int);		//�]�w�ù����
				void SetObjectXY(int*, int*);	//�]�w�a�Ϫ����m
				void GrowCrop(int, int, int);	//�غؤl
				bool IsDrit(int, int);			//�P�_�O�_�O�d�g
				bool IsCrop(int, int);			//�P�_�@��
				int HarvestCrops(int, int);		//�Ħ��Ӫ�
				bool IsMatureCrop(int, int);	//�P�_�O�_����
				int BuyProduct(int, int);		//�ʶR���~
				bool IsProduct(int, int);		//�P�_�O�_�i�H�ʶR���~
				bool IsSeller(int, int);		//�P�_�O�_���ӤH
				void AddChicken(int, int);		//�b�a�ϳЫ�������
				void AddCow(int, int);			//�b�a�ϳЫؤ�����
				void AddSheep(int, int);		//�b�a�ϳЫئϪ���
				void SpawnEgg();				//�b�a�ϳЫسJ
				void HarvestEgg(int, int);		//���a�Ħ��J
				bool IsEgg(int, int);			//�P�_�O�_���J
				bool IsSheep(int, int);			//�P�_�O�_����
				bool IsCow(int, int);			//�P�_�O�_����
				void ShowHouse();				//��ܩФl�B�n
				void SetPlayerXY(int, int);		//�]�w���a��m
			protected:
				CMovingBitmap grass, dryDirt, Bush1, Bush2;
				CMovingBitmap egg, test, Fence, Fence_Back, Fence_LUnder, Fence_LUp, Fence_RUnder, Fence_RUp, Fence_Str;
				CMovingBitmap store, store_house, Chicken_House, ChHouse_Gnd, ChHouse_Wall, ChHouse_Feedbox1, ChHouse_Feedbox2, ChHouse_Feedbox3; // �ө�
				CMovingBitmap home_house, HmFood, HmGnd, HmKettle, HmNst, HmTV, HmWallBtm, HmWall;	// �a
				CMovingBitmap Tool_axe, Tool_bell, Tool_hammer, Tool_hoe, Tool_milkMachine, Tool_rod, Tool_scissor, Tool_sickle, Tool_WtrCan;	// �u��
				CMovingBitmap Tool_box;	// ��m���u��
				CMovingBitmap Road_Center, Road_CDown, Road_CUp, Road_CLeft, Road_CRight,  Road_LDownCorner, Road_LUpCorner, Road_RDownCorner, Road_RUpCorner;	// ��
				Businessman bus;				//�ӤH
				CMovingBitmap MainPoint;		//���ܦa�I
				int map[100][100];				//�a�ϰ}�C
				int mapObject[100][100];		//�a�Ϫ���}�C
				int X, Y;						//�a�ϭI��ø�s��xy
				int sx, sy;						//�ù���m
				int playerX, playerY;			//���a��m
				int time;						//�H���𲣥ͥ�
				vector<Crop*> map_Crop;			//�a�ϤW���@���}�C
				vector<Animals*> map_Animals;	//�a�ϤW���ʪ��}�C
				bool crop_created;				//�d�ݦa�ϧ@���O�_�w�Ħ�
		};
}