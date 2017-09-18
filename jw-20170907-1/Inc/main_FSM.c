#include "main_FSM.h"
#include <stdlib.h>

//---------------------------------------------------------------------
// ��� �ʱ�ȭ �Լ� & ���� & ����
//---------------------------------------------------------------------
extern void LED1_ON(void);
extern void LED2_ON(void);

#define  MAX_BOX 10
//enum BOX{
//    GET_BOX_ENABLE = 0, // �ڽ��� ���� �� �ִ�.
//    GET_BOX_DISABLE     // �ڽ��� ���� �� ����.
//};

static char szMessage[1024] = "";

//static int m_MyStamina;
//static int m_Bundle;
//static int m_IsGetBox;
static int m_CurLevel;

// ����ö󰡱�
static void LevelUp(int nStep);
static void LevelDown(int nStep);

//---------------------------------------------------------------------
// �ڵ鷯 ���� ����
//---------------------------------------------------------------------
static void OnL1_To_L2  (FSM_EVT e);
//static void OnL2_To_L3(FSM_EVT e);
//static void OnL3_To_L1(FSM_EVT e);

static void OnL1_To_L1  (FSM_EVT e);
static void OnL2_To_L1  (FSM_EVT e);
//static void OnL3_To_L2(FSM_EVT e);

static void OnRest(FSM_EVT e);
static void OnWarnning(FSM_EVT e);
//static void OnDropBox(FSM_EVT e);
//static void OnGetBox (FSM_EVT e);

//---------------------------------------------------------------------
// FSM ���� ����
//---------------------------------------------------------------------

// FSM ����ü�� StateHandler ���̺�
// �ڵ鷯 ���̺��� "����"�� "�̺�Ʈ"�� �������� ����Ǵ� �Լ���
// �迭�����Ѵ�(�� �״�� ����ǥ��). 
Action  table_FSM[_MOVEMAN_MAX_STATE][_MOVEMAN_MAX_EVT] = {
    // [�̺�Ʈ]
    //----------------------------------------------------------|   [����] 
    //  UP          DOWN     REST    DROP BOX    GET BOX
    {OnL1_To_L2, OnL1_To_L1},     // 1�� ����
    {OnL2_To_L1, OnL2_To_L1}   // 2�� ����
  //  {OnL3_To_L1, OnL3_To_L2, OnRest, OnDropBox,  OnWarnning}    // 3�� ����
};

// �ʱ� ������ ����
Action* InitMainFSM(FSM* f)
{
    // State �ʱ�ȭ
    SetState(f, _MOVEMAN_LEVEL_1);

    // �ʱ�ȭ
   // m_MyStamina = 50;
   // m_Bundle    = MAX_BOX;
   // m_IsGetBox  = GET_BOX_ENABLE;
    m_CurLevel  = 1;

    return (Action*)table_FSM;
}

//---------------------------------------------------------------------
// �����Լ� ����
//---------------------------------------------------------------------

// �޽��� �����ϱ� 
static void AddMessage(char* msg)
{
  //  sprintf(szMessage, "\r\n%s", msg);
}

// �� �ö󰡱�
static void LevelUp(int nStep)
{
    m_CurLevel+= nStep;    
}

// �� �������� 
static void LevelDown(int nStep)
{
    m_CurLevel-= nStep; 
}

// ü�º���
/*
static void StaminaUp(int nStep)
{
    m_MyStamina+= nStep;    
}

// ü�°���
static void StaminaDown(int nStep)
{
    m_MyStamina-= nStep; 
}
*/
// ü��üũ 
/*
static int CheckStaminaLow()
{
    // ü���� ���ߴٸ�...
    if(m_MyStamina < 0) {
        AddMessage("[���] ���̻� ������ �� �����ϴ�. \r\n");
        return 1;        
    }
    return 0;
}
*/
// �ڽ� ������ 
/*
static void GetBox()
{
    m_IsGetBox  = GET_BOX_DISABLE; 
}

// �ڽ� �������� 
static void DropBox()
{
    m_IsGetBox  = GET_BOX_ENABLE; 
}
*/
// �ڽ� äũ�ϱ� 
/*
static int IsGetBox()
{
    return m_IsGetBox;
}

*/

// ���ܺη� Extern�Ǵ� �Լ�
/*
void DisplayCurrent()
{
    // 10�� BOX
    char LEV_BOXES[MAX_BOX + 1] = "##########";  
    char MOVE_MAN;
    int notmove_box;
    
	system("cls");

    MOVE_MAN  = '&';
    notmove_box = MAX_BOX - m_Bundle;
    if( IsGetBox() ) notmove_box++;
    
	printf("ü��: %d\r\n���� ����:%d\r\n��������: %d\r\n��ġ: %d��\r\n", 
             m_MyStamina, m_Bundle, m_IsGetBox, m_CurLevel
    );
    
    printf("__________________________________________________\r\n");
    printf("| 3��|   %c  %s     \r\n",  (m_CurLevel == 3) ? MOVE_MAN: ' ',   &LEV_BOXES[m_Bundle]);
    printf("|-------| |---------------------------------------\r\n");
    printf("| 2��|   %c         \r\n",  (m_CurLevel == 2) ? MOVE_MAN: ' '  );
    printf("|-------| |---------------------------------------\r\n");
    printf("| 1��|   %c  %s     \r\n",  (m_CurLevel == 1) ? MOVE_MAN: ' ',   &LEV_BOXES[notmove_box]);
    printf("|_______|_|_______________________________________\r\n"); 
	printf("        | |                                       \r\n"); 
	printf("        Exit            press [?] for help        \r\n"); 
	
	// �޽��� ����ϱ� 
	printf (szMessage);
       
}
*/
//---------------------------------------------------------------------
// �ڵ鷯 ���� ����
//---------------------------------------------------------------------

// 1������ 2�� �ö󰡴� ���, �ڵ鷯 
static void OnL1_To_L2(FSM_EVT e)
{
    
  //  if(CheckStaminaLow()) return;
   // AddMessage("--> 1������ 2������ �ö󰩴ϴ�.\r\n");
    
    // ���̵� 
  //  LevelUp(1);
    
    // ü�°���
  //  StaminaDown(2);
    LED2_ON();
    SetState(e.pOwner, _MOVEMAN_LEVEL_2);       
}

// 2������ 3�� �ö󰡴� ���, �ڵ鷯 
/*
static void OnL2_To_L3(FSM_EVT e)
{
    if(CheckStaminaLow()) return;
    AddMessage("--> 2������ 3������ �ö󰩴ϴ�.\r\n");

    // ���̵� 
    LevelUp(1);
    
    // ü�°���
    StaminaDown( 2 );    
   
    SetState(e.pOwner, _MOVEMAN_LEVEL_3);   
}
*/
// 3������ 1�� �������� ���, �ڵ鷯 
/*
static void OnL3_To_L1(FSM_EVT e)
{
    // ���� ���� ���
    AddMessage(
        "-->1������ �����߽��ϴ�.\r\n"
        "-->5������ ü�¼ս��� �Ծ����ϴ�.\r\n"
    );
    
    // ���̵� 
    LevelDown(2);   
    
    // ü�°���
    StaminaDown( 5 );
    
    SetState(e.pOwner, _MOVEMAN_LEVEL_1);    
}
*/
// 1������ �������� ���(Down��û),  �ڵ鷯  
static void OnL1_To_L1(FSM_EVT e)
{/*
    if(m_Bundle < 1) {
        AddMessage("**** ---------------------------------------.****\r\n"
                   "**** OOO ���� ���ø� �˴ϴ�.������ ���ô�.OO ****\r\n"
                   "**** ---------------------------------------.****\r\n");
        
        // ������� �����ϸ� ����.
        // ������ ������ ���� �����̹Ƿ� ������ ���� �����Ѵ�.
        e.pOwner->result = 100;
        return;
        
    } else {
        AddMessage("**** �ӹ��� �Ϸ���� �ʾ����Ƿ� ���ư� �� �����ϴ� ****\r\n");
    }
    */
}

// 2������ 1�� �������� ���, �ڵ鷯 
static void OnL2_To_L1(FSM_EVT e)
{
  //  if(CheckStaminaLow()) return;
 //   AddMessage("->2������ 1������ ���������ϴ�.\r\n");
     
    // ���̵� 
  //  LevelDown(1);
  LED1_ON();
    
    // ü�°���
 //   StaminaDown(1);
    
    SetState(e.pOwner, _MOVEMAN_LEVEL_1);   
}

// 3������ 2�� �������� ���, �ڵ鷯 
/*
static void OnL3_To_L2(FSM_EVT e)
{
    if(CheckStaminaLow()) return;  
    AddMessage("->3������ 2������ ���������ϴ�.\r\n");
    
    // ���̵� 
    LevelDown(1);  

    // ü�°���
    StaminaDown(1);

    SetState(e.pOwner, _MOVEMAN_LEVEL_2);       
}
*/
// ���� ���, �ڵ鷯 
static void OnRest(FSM_EVT e)
{
  //  StaminaUp( 5 );

   // AddMessage("--> ���鼭 ü���� 5+��ŭ ȸ���߽��ϴ�. \r\n");
    //printf("<ü��: %d ��:%d> \r\n", m_MyStamina, m_Bundle);   
}

// ��� �ڵ鷯 
static void OnWarnning(FSM_EVT e)
{
  /*
   if(e.EVT == _MOVEMAN_DROP_BOX){
       if(IsGetBox()){
           AddMessage("-->3������ �� �Ŀ�, ���ڸ� �����ֽʽÿ� \r\n");
       } else {
           AddMessage("-->������ �ִ� �ڽ��� �����ϴ�.\r\n");
       }
       
   } else if (e.EVT == _MOVEMAN_GET_BOX){       
       AddMessage("-->���ڴ� 1�������� ���� �� �ֽ��ϴ�. \r\n");
   } 
  */
}

// �ڽ��������� ���, �ڵ鷯 
/*
static void OnDropBox(FSM_EVT e)
{
	char msg[1024];
        
    if(CheckStaminaLow()) return;
    
    // ���ڸ� ���´�.
    if(m_Bundle > 0 && IsGetBox() != 0){
        m_Bundle--;

		sprintf(msg, "--> ���ڸ� �����ϴ�. ���� ���� ������ %d �Դϴ�.\r\n", m_Bundle);
        AddMessage(msg);

        DropBox();
        
    }else{
        AddMessage("--> � ���ڸ� ���ڴٴ� ���ΰ���? ���� ���� ���µ� ���Դϴ�.\r\n");
    }
}

// �ڽ� ���� ���, �ڵ鷯 
static void OnGetBox (FSM_EVT e)
{
    if(m_Bundle > 0 && IsGetBox() == GET_BOX_ENABLE){
        AddMessage("--> ���� 1���� �����̽��ϴ�.\r\n");
        GetBox();
    } else if (m_Bundle > 0 && IsGetBox() == GET_BOX_DISABLE){
        AddMessage("--> �̹� ���� 1���� �����̽��ϴ�.\r\n");
    } else {
        AddMessage("--> ���ڸ� ��� �ű������ �����ֽʽÿ�.\r\n");
    }    
}
*/

