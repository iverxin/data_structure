#include "stack.h"

using namespace std;

Status InitStack(SqStack &S)
{
	/*构造一个空栈*/
	S.base = (SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
	if (!S.base)
		exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return OK;
}

Status GetTop(SqStack S, SElemType &e)
{
	//若top不为空，则用e返回栈顶元素，并且返回OK，否则返回error
	if (S.top == S.base) return ERROR;
	e = *(S.top - 1);
	return OK; 
}

Status Push(SqStack &S, SElemType e)
{
	//插入元素e为新的栈顶元素
	if ((S.top - S.base) >= S.stacksize)
	{
		//栈满，追加空间
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
	//出栈
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
	//十进制转换成x进制
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


void LineEdit() //利用字符栈S，从终端接受一行并传送至调用过程的数据区
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
		在此处将栈中的数据元素送至数据区
		*/
	ClearStack(S);
	if (ch != EOF) ch = getchar();
	}
	DestoryStack(S);
}