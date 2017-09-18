/*
    ����  : ���°�����-FSM
    ����  : ���α׷��� ������ �帧�� ��Ģ������ �����Ѵ�.
    �ۼ���: �ڼ���
    �ۼ���: 2005.04.20
    ������: 2005.12.13


    ����  : 1) ���¿� �̺�Ʈ�� �б����� ������.
            2) Handler ���̺�� ������ �� �ִ�.
            3) �������̿� ���� �޼ҵ带 �����Ѵ�.
            4) ���´� ���ο��� �����Ѵ�. �̺�Ʈ�� �ܺ� �Է��׸��̴�.

    ����� ȯ�濡 �°� C �������� ������.
*/
#ifndef  __PSW_FSM_SNAKE
#define  __PSW_FSM_SNAKE


// State Handler�� Ÿ��

typedef struct tagFSM_EVT FSM_EVT ;
typedef struct tagFSM FSM;

typedef void (*Action)(FSM_EVT);

// FSM(���¸ӽ�) Structure
typedef struct tagFSM{

    int      result;
    unsigned curState;

    unsigned MaxEvent;
    unsigned MaxState;
    Action*  HandlerTable;

} tagFSM;

// �̺�Ʈ�� �Ű�����
typedef struct tagFSM_EVT{
    unsigned EVT;
    int    lParam;    // Parameter 1
    int    wParam;    // Parameter 2
    FSM*   pOwner;     // State��ü
} tagFSM_EVT;

// FSM�� �ʱ�ȭ �Ѵ�.
extern int  DoEvent(FSM* f, FSM_EVT evt);

// ���¸� �����Ѵ�.
extern void SetState(FSM* f,unsigned target);

// ���¸� ������ �´�.
extern unsigned GetState(FSM f);

// ���� ���¸� ������ �´�.
extern unsigned GetResult(FSM f);

// �ƹ��͵� ���� �ʴ´�.
extern void doNothing(FSM_EVT e);

// FSM�� �ʱ�ȭ�Ѵ�.
extern unsigned InitStateMachine(
    FSM* f, Action* table,
    unsigned MaxEvent,
    unsigned MaxState
);

#endif