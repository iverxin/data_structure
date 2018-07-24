#include "queue.h"
Status InitQueue(LinkQueue &Q)
{
    // 构造一个空队列 ,有空数据的头结点
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

Status Dequeue(LinkQueue &Q , QElemType &e)
{
    //删除Q的队头元素，用e返回删除的值
    if(Q.front==Q.rear) return ERROR;
    QueuePtr p;
    p=Q.front->next; //删除的节点
    e=Q.front->data; //删除节点的数据
    Q.front->next=p->next; //头结点重新链接
    if(Q.rear == p) Q.rear=Q.front; //如果删除的是最后一个队尾元素\
                                    重新定义队尾指针的指向
    free(p);
    return OK;
}

/* 循环队列函数 */
Status InitSqQueue(SqQueue & Q)
{
    // 构造一个空队列Q
    Q.base = (QElemType *) malloc(MAXQSIZE*sizeof(QElemType));
    if (!Q.base) exit(OVERFLOW);
    Q.front = Q.rear = 0 ;
    return OK ; 
}

int SqQueueLength(SqQueue Q)
{
    // 返回Q的元素个数，即队列的长度
    return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE ; 
}

int SqEnQueue(SqQueue &Q , QElemType e)
{
    // 插入元素e在新的对尾元素
    if ((Q.rear+1)%MAXQSIZE == Q.front) return ERROR ; //队列满。有一个空的应该是
    Q.base[Q.rear] = e;
    Q.rear=(Q.rear+1) % MAXQSIZE;
    return OK;
}

Status DeQueue(SqQueue &Q , QElemType & e)
{
    //若队列不空，则删除Q的队头元素，用e返回其值，并且返回OK
    //否则返回error
    if (Q.front == Q.rear) return ERROR;
    e = Q.base[Q.front];
    Q.front=(Q.front+1) % MAXQSIZE;
    return OK;    
}

