#include "stack.h"

using namespace std;

Status InitStack(SqStack &S)
{
	/*����һ����ջ*/
	S.base = (SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
	if (!S.base)
		exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return OK;
}

Status GetTop(SqStack S, SElemType &e)
{
	//��top��Ϊ�գ�����e����ջ��Ԫ�أ����ҷ���OK�����򷵻�error
	if (S.top == S.base) return ERROR;
	e = *(S.top - 1);
	return OK; 
}

Status Push(SqStack &S, SElemType e)
{
	//����Ԫ��eΪ�µ�ջ��Ԫ��
	if ((S.top - S.base) >= S.stacksize)
	{
		//ջ����׷�ӿռ�
		S.base = (ElemType *)realloc(S.base, sizeof(ElemType)*(S.stacksize + STACKINCREMENT));
		if (!S.base) exit( OVERFLOW);
		S.stacksize += STACKINCREMENT;
	}
	*S.top = e;
	S.top++;
	//*S.top++=e;
	return OK;
}

Status Pop(SqStack & S, SElemType &e)
{
	//��ջ
	if (S.top == S.base) return (ERROR);
	e = *--S.top; //echos to e *(--S.top)
	return OK;
}//Pop

Status StackEmpty(SqStack S)
{
	if (S.base == S.top)
		return 1;
	else return 0;
}
void conversion()
{
	//ʮ����ת����x����
	SqStack S;
	int N ;
	ElemType e; 
	InitStack(S);
	cin >> N;
	while (N)
	{
		Push(S,N%8) ;
		N = N / 8;
	}
	while (!StackEmpty(S))
	{
		Pop(S, e);
		cout <<  e;
	}
}
Status ClearStack(SqStack &S)
{
	S.top = S.base;
	return OK; 
}

Status DestoryStack(SqStack &S)
{
	free(S.base);
	S.base = NULL;
	S.top = NULL;
	S.stacksize = 0; 
	return OK;
}


void LineEdit() //�����ַ�ջS�����ն˽���һ�в����������ù��̵�������
{
	SqStack S;
	InitStack(S);
	SElemType ch , c ;
	ch = getchar();
	
	while (ch!=EOF)
	{
		while (ch != '\n')
		{
			switch (ch)
			{
			case '#': Pop(S, c);
				break;
			case '@': ClearStack(S);
				break;
			default: Push(S,ch);
			}
		ch = getchar();
		}
		/*
		�ڴ˴���ջ�е�����Ԫ������������
		*/
	ClearStack(S);
	if (ch != EOF) ch = getchar();
	}
	DestoryStack(S);
}


