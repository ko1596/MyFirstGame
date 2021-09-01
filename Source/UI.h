#include "Challenge.h"
namespace game_framework {
	enum state								//�C��ui��ܪ��A
	{
		Esc, backpack, talk, gaming,over
	};
	class Map;
	class Item;
	class UI
	{
	public:
		UI();								//ui��l��
		~UI();								//�R�����~
		void LoadBitmap();					//���Jui�Ϥ�
		void OnShow(int, Challenge*);		//���ui�e��
		void ChangeState(state);			//����ui���A
		void ShowTime(int);					//��ܮɶ�
		void CreateItem(int,int);			//�s�W���~
		void ShowItem();					//��ܪ��~
		void SetInventorySelect(int);		//�]�w���~������m
		void MouseClickDown(CPoint);		//�ƹ��I��
		void MouseClickUp();				//�ƹ���}
		bool ClickInventory(CMovingBitmap);	//�I�����~��
		int UseItem();						//�ϥΪ��~
		void deleteNonItem();				//�R�����~
		void GetItem(int, int);				//��o���~
		bool HaveThisItem(int);				//�O�_�w�֦����~
		bool IsSeed();						//�O�_��W���ؤl
		void ShowMoney();					//��ܪ���
		bool CostMoney(int);				//��O����
		void GetMoney(int);					//���o����
		void SellItem();					//�c�檫�~
		void ShowHowToPlay();				//��ܫ��䴣��
		void MsgBox(string);				//��J���ܰT��
		void Msg();							//��ܴ��ܰT��
		void ShowTool(int, int, int);		//��ܳ�Ӥu��
		void ShowAllTool();					//����Ҧ��u��
		void ClickSwitch();					//�I���u��������s
		int Gettool_select();				//���o�ثe����u��id
		int ReturnMoney();					//���o����
		void SetMouseXY(int, int);			//�]�w�ƹ���m
		void ShowChaItem();					//��ܦ��N
		bool GetGameOver();					//�]�w�C������
		void SetRunState();					//�]�w�C�����A
	protected:
		CMovingBitmap inventory[9];																		//���~��Ϥ�
		CMovingBitmap inventorySelect;																	//���~����
		CMovingBitmap inventory_line,clockBar;															//�u����
		CMovingBitmap inventory_mainuse, inventory_use1, inventory_use2;								//�����k�u������														
		CMovingBitmap moneyBar, moneyIcon, howToPlayBackground;											//�����C �����ϥ� �C������I��
		CMovingBitmap axe, bell, box, hammer, hoe, milkMachine, rod, scissor, sickle, WaterCan;			//�U�ؤu��Ϥ�
		CMovingBitmap none,crop, chicken, sheep, cow, moneyPIC;											//�U�ئ��N�Ϥ�
		CMovingBitmap cropM, chickenM, sheepM, cowM, moneyPICM;											//�U�طƹ����H���N�Ϥ�
		CMovingBitmap overImg, overImgOver, overImgKeep;												//�O�_�����C��
		CMovingBitmap page1, page2, page3, page4, page5;												//�C�����Э���
		state _state,lastState;					//�C��ui���A
		vector<Item*> InventoryItem;			//���~��}�C
		string msg;								//��T��
		int inventory_select, tool_select;		//���~��u������id
		int mouseX, mouseY;						//�ƹ���m
		bool mouseClick;						//�ƹ��O�_�I��
		int money;								//���a����	
		int msgResetTime;						//�T�����m�ɶ�
		int size;								//���~��j�p
		int msx, msy;							//�ƹ���m
		int overcount;							//�����Ҧ����N ���X�O�_�������˼�
		bool StartOverCount;					//�O�_�}�l�����˼�
		int changePageTime;						//�������ļ���ɶ�
		bool gameOver;							//�C���O�_����
		int page;								//�ثe�C�����Э���
		bool pageBtnClick;						//�������ƫ��s
	};
}
