#include "UI.h"
#include "Map.h"
#include "Character.h"
#include "Menu.h"
#include "Challenge.h"
namespace game_framework
{
	enum AUDIO_ID  				// �w�q�U�ح��Ī��s��
	{
		AUDIO_LAKE,				// 1
		AUDIO_COW// 3
	};
	class CGameStateInit : public CGameState
	{
		public:
			CGameStateInit(CGame* g);
			void OnInit();  								// �C������Ȥιϧγ]�w
			void OnKeyUp(UINT, UINT, UINT); 				// �B�z��LUp���ʧ@
			void OnLButtonDown(UINT nFlags, CPoint point);  // �B�z�ƹ����ʧ@
			void OnLButtonUp(UINT nFlags, CPoint point);  // �B�z�ƹ����ʧ@
			void OnMouseMove(UINT nFlags, CPoint point);
		protected:
			void OnShow();									// ��ܳo�Ӫ��A���C���e��
		private:
			CMovingBitmap logo, btitle, menubackground;
			Menu initMenu;
	};
	class CGameStateRun : public CGameState
	{
		public:
			CGameStateRun(CGame* g);
			~CGameStateRun();
			void OnBeginState();							// �]�w�C�������һݪ��ܼ�
			void OnInit();  								// �C������Ȥιϧγ]�w
			void OnKeyDown(UINT, UINT, UINT);
			void OnKeyUp(UINT, UINT, UINT);
			void OnLButtonDown(UINT nFlags, CPoint point);  // �B�z�ƹ����ʧ@
			void OnLButtonUp(UINT nFlags, CPoint point);	// �B�z�ƹ����ʧ@
			void OnMouseMove(UINT nFlags, CPoint point);	// �B�z�ƹ����ʧ@
		protected:
			void OnMove();									// ���ʹC������
			void OnShow();									// ��ܳo�Ӫ��A���C���e��
		private:
			const int		NUMBALLS;	// �y���`��
			int GameTime;
			CMovingBitmap	background;	// �I����
			CMovingBitmap	help;		// ������
			CMovingBitmap	corner;		// ������
			CInteger		hits_left;	// �ѤU��������
			Map				default_map;//�ŧi��l�a��
			Character		player;		//�ŧi���a
			UI				ui;			//�ŧiui
			Challenge		challenge;	//�ŧi���N�t��
			bool doing;					//�ƹ��O�_�I��
	};
	class CGameStateOver : public CGameState
	{
		public:
			CGameStateOver(CGame* g);
			void OnBeginState();							// �]�w�C�������һݪ��ܼ�
			void OnInit();
		protected:
			void OnMove();									// ���ʹC������
			void OnShow();									// ��ܳo�Ӫ��A���C���e��
		private:
			int counter;	// �˼Ƥ��p�ƾ�
			CMovingBitmap end;
	};
}