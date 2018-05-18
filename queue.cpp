#include "queue.h"
Status InitQueue(LinkQueue &Q)
{
    // 构造一个空队列
    Q.front = Q.rear = (QueuePtr) malloc(sizeof (QNode));
    if (!Q.front)  exit(OVERFLOW);
    Q.front->next=NULL;
    return OK;
}

Status DestoryQueue(LinkQueue &Q)
{
    while (Q.front)
    {
        Q.rear = Q.front->next; //尾指针失去作用，所以用来存放front的下一个，避免空间浪费
        free(Q.front);
        Q.front = Q.rear;
    }
    return OK;
}

Status EnQueue(LinkQueue &Q,QElemType e)
{
    // 插入元素e为q的新队尾元素
    QueuePtr p ;
    p=(QueuePtr)malloc(sizeof(QNode));
    if(!p) exit(OVERFLOW);
    p->data = e ; p->next=NULL;
    Q.rear->next=p;
    Q.rear=p;
    return OK;
}

