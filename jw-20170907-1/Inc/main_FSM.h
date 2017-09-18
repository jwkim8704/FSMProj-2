/*
    ����  : 3�� �ǹ� ���� �ű�� -FSM
    ����  : ���α׷��� ������ �帧�� ��Ģ������ �����Ѵ�.
    �ۼ���: �ڼ���
    �ۼ���: 2005.04.20
    ������: 2005.12.13


    ����  : ������ ���¸ӽ� ����
            ��������
*/
#ifndef  __PSW_FSM_MAIN_SNAKE
#define  __PSW_FSM_MAIN_SNAKE
#include "FSM.h"

// Event ����
enum EVENT_MOVEMAN
{
    _MOVEMAN_GO_UP  = 0,  // �ö󰡱�     �̺�Ʈ
    _MOVEMAN_GO_DOWN,     // ��������     �̺�Ʈ
   // _MOVEMAN_REST,        // �����     �̺�Ʈ
   // _MOVEMAN_DROP_BOX,    // ���ڳ������� �̺�Ʈ
   // _MOVEMAN_GET_BOX,     // ���ھ��     �̺�Ʈ
    _MOVEMAN_MAX_EVT      /* �ڵ�ī��Ʈ�� */
};

// ���� ����
enum STATE_MOVEMAN
{
    _MOVEMAN_LEVEL_1 = 0,
    _MOVEMAN_LEVEL_2,
  //  _MOVEMAN_LEVEL_3,
    _MOVEMAN_CAN_NOT_MOVE,
    _MOVEMAN_MAX_STATE    /* �ڵ�ī��Ʈ�� */
};

extern Action* InitMainFSM(FSM* e);
extern void    DisplayCurrent();
#endif