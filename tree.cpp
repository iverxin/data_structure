#include "tree.h"
#include "iostream"
using namespace std ;
// Status CreateBiTree(BiTree &T)
// {
//     BiTree pTemp,pNow;
//     TElemType dataInput ;
//     int numOrd=0;
//     bool LRflag=0;
//     pNow=T;


//     printf("Please Input the data (%d)",numOrd++);
//     scanf("%c",&dataInput);
//     if (dataInput=='#') //# is the end keyllll 
//         return 1;
//     else
//     {
//         if (LRflag=0)
//         {
//             pTemp=(BiTNode *)malloc(sizeof(BiTNode));
//             pNow->lchild=pTemp;
//             pTemp->data=dataInput;
//             LRflag=1-LRflag;
//         }
//         else 
//         {
//             pTemp=(BiTree)malloc(sizeof(BiTNode));
//             pNow->rchild=pTemp;
//             pTemp->data=dataInput;
//             LRflag=not(LRflag);
//             pNow=pNow->lchild;
//         }
//     }
// }
Status PrintElement(TElemType e)
{
    cout << e<<endl;
    return OK;
}

Status PreOrderTraverse(BiTree T , Status (* Visit)(TElemType e)) //传递函数为函数，函数名为指针
{
    //调用方法 eg:PreOrderTraverse(T,PirntElement)
    //采用二叉树链表存储结构
    //先序遍历
    //递归调用

    if(T) 
    {
        if(Visit(T->data))
            if (PreOrderTraverse(T->lchild,Visit))
                if(PreOrderTraverse(T->rchild,Visit))
                    return OK;

        return ERROR;
    }
    else 
        return OK;
}

//写的不好
// Status CreateBiTree(BiTree &T)
// {
//     //先序插入二叉树节点的值
//     //构造二叉链表表示的二叉树
//     char ch ;
//     scanf("%c",&ch);
//     if(ch=='') 
//         T=NULL;
//     else
//     {
//         if(!(T=(BiTNode *)malloc(sizeof(BiTNode)))) exit(OVERFLOW);  //申请内存空间地址
//         T->data=ch;
//         CreateBiTree(T->lchild);//构造左子树
//         CreateBitree(T->rchild);//构造右子树
//     }
//     return OK;
// }

/* 6.5 */
Status InOrderTraverse_Thr(BiThrTree T, Status (* Visit)(TElemType e))
{
    BiThrTree p;
    p=T->lchild ;
    while(p!=T)
    {
        while(p->LTag==Link) p=p->lchild;  //找到左孩子的左的左孩子。。。
        if(!Visit(p->data)) //访问左孩子
            return ERROR;
        while(p->RTag==Thread && p->rchild!= T)  //如果右孩子是后继，则访问
        {
            p=p->rchild ; Visit(p->data) ; 
        }
        p=p->rchild; //左和中都完成，把右孩子当做中，开始找最左。 
    }
    return OK;
}


/* 6.7 */
void InThreading(BiThrTree p)
{
    BiThrTree pre;
    if (p)
    {
        InThreading(p->lchild) ; //左子树线索化
        if(!p->lchild)
        {
            p->LTag=Thread ; p->lchild=pre ; //前驱线索
        }
    if (!pre->rchild) 
    {
        pre->RTag = Thread ; pre->rchild = p ; 
    }
    pre = p ; 
    InThreading(p->rchild);
    }
}
/* 6.6 */
Status InOrderThreading(BiThrTree & Thrt , BiThrTree T)
{
    //中序遍历二叉树T,并将其中序线索花，Thrt指向头结点
    BiThrTree pre;
    if (!(Thrt = (BiThrTree)malloc(sizeof(BiThrNode))))
        exit(OVERFLOW);
    Thrt->LTag = Link; Thrt->RTag=Thread; //创建头结点
    Thrt->rchild=Thrt; //右指针回指
    if(!T) Thrt->lchild = Thrt ; 
    else{
        Thrt->lchild=T; pre=Thrt;
        InThreading(T); //进行中序遍历并进行线索化
        pre->rchild=Thrt; pre->RTag=Thread; //最后一个节点线索化
        Thrt->rchild = pre;
    }

}