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

Status InitQueue(LinkQueue &Q);
Status DestoryQueue(LinkQueue &Q);
Status ClearQueue(LinkQueue &Q);
