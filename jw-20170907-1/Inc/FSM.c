#include "FSM.h"

// �ܺ� ȣ�����.
int DoEvent(FSM* f, FSM_EVT evt)
{
   Action act;
   unsigned const e = evt.EVT;
   if(f->MaxEvent < e) return 0;

   // EVT�� ȣ���ϴ� FSM ������ ����
   evt.pOwner = f;

   // �ش� �Լ� ����
   act =  *(  (f->HandlerTable) + (f->curState * f->MaxEvent) + e);
  (*act)(evt);
   return 0;
}

// �ƹ��͵� ���ϴ� �Լ���
// ��𼭳� �ʿ��ϴ�.
void doNothing(FSM_EVT e)
{

}

// ���¸� �����Ѵ�.
void SetState(FSM* f, unsigned target)
{
    if(f->MaxState < target) return;
    f->curState = target;
}

// ���¸� ������ �´�.
unsigned GetState(FSM f)
{
    return f.curState;
}

// FSM�� �ʱ�ȭ�Ѵ�.
unsigned InitStateMachine(
    FSM* f, Action* table,
    unsigned MaxEvent,
    unsigned MaxState
    )
{
    unsigned i,  j;
    Action   act;

    f->HandlerTable = table;
    f->MaxEvent     = MaxEvent;
    f->MaxState     = MaxState;

    return 0;
}

// ���� ���¸� ������ �´�.
extern unsigned GetResult(FSM f)
{
    return f.result;
}