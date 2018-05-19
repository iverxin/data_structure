#ifndef __QUEUE_H
#define __QUEUE_H
#include "head_usr.h"
#endif 

typedef int QElemType ;
// -------单链队列--------
typedef struct QNode 
{
    QElemType data;
    struct QNode * next;  //next是下一个struct Qnode的地址，即QueuePtr \
                        因为这类还没有出现QueuePtr的定义，所以只能有struct 的tag来声明
}QNode, *QueuePtr;

typedef struct {
    QueuePtr front;
    QueuePtr rear;
}LinkQueue;


/* 循环队列---队列的顺序存储结构 */
#define MAXQSIZE 100    //最大队列长度

typedef struct 
{
    QElemType * base ; // 初始化的动态分配存储空间
    int front ; //头指针， 若队列不空，只想队列头元素
    int rear ;  //尾指针，队列不空时，指向队列尾元素的下一个位置
}SqQueue;





Status InitQueue(LinkQueue &Q);
Status DestoryQueue(LinkQueue &Q);
Status ClearQueue(LinkQueue &Q);
