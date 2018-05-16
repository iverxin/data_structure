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
*Õ»µÄË³Ðò±êÊ¶
*date£º2018.5.18
*author	£ºspade
*/

typedef struct{
	SElemType * base; 
	SElemType * top; 
	int stacksize; 
}SqStack;


Status InitStack(SqStack &S);
Status GetTop(SqStack S, SElemType &e);
Status Pop(SqStack & S, SElemType &e);
Status Push(SqStack &S, SElemType e);
Status StackEmpty(SqStack S);
void conversion();

