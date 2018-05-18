#pragma once
#ifndef __STACK_H
#define __STACK_H
#include <stdio.h>
#include "head_usr.h"
#endif 
#include <iostream>
#define STACK_INIT_SIZE 1000
#define STACKINCREMENT 100
typedef int SElemType;
//typedef char SElemType;
/*------------------start!-------------------------
*ջ��˳���ʶ
*date��2018.5.18
*author	��spade
*/

typedef struct{
	SElemType * base; 
	SElemType * top; 
	int stacksize; 
}SqStack;

typedef struct 
{
	int x_seat;
	int y_seat;
}PosType;//迷宫坐标

typedef struct
{
	int ord ; 
	PosType seat;
	int di;
}MG_SElemType;

Status InitStack(SqStack &S);
Status GetTop(SqStack S, SElemType &e);
Status Pop(SqStack & S, SElemType &e);
Status Push(SqStack &S, SElemType e);
Status StackEmpty(SqStack S);
void conversion();
void LineEdit();