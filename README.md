# 数据结构笔记
## 1、顺序栈（SqStack）
```c
/*顺序栈的存储结构*/
typedef struct SqStack {
	ElemType *elem;	    //存储空间的基址
	int top;		        //栈顶元素的下一个位置，简称栈顶位标
	int size;		        //当前分配的存储容量
	int increment;	    //扩容时，增加的存储容量
}SqStack;
```
* InitStack_Sq(SqStack &S, int size, int inc)//顺序栈初始化
* StackEmpty_Sq(SqStack S)//顺序栈判空
* ClearStack_Sq(SqStack &S)//清空顺序栈
* Length_Sq(SqStack S)//测量栈长度
* Push_Sq(SqStack &S, ElemType e)//入栈
* Pop_Sq(SqStack &S, ElemType &e)//出栈
* GetTop_Sq(SqStack S, ElemType &e)//获取栈顶元素
* Visit_Sq(SqStack S)//遍历栈
* DestroyStack_Sq(SqStack &S)//销毁栈

## 2、循环队列（SqQueue）
```c
/*循环队列的顺序存储结构*/
typedef struct {
	ElemType *base;	//存储空间的基址
	int front;		//队头位标
	int rear;		//队尾位标，指示队尾元素的下一个位置
	int maxSize;	//最大长度
}SqQueue;
```
* InitQueue_Sq(SqQueue &Q,int size)//初始化队列
* EmptyQueue_Sq(SqQueue Q)//队列判空
* LengthQueue_Sq(SqQueue Q)//队列长度
* ClearQueue_Sq(SqQueue &Q)//清空队列
* DeQueue_Sq(SqQueue &Q, ElemType &e)//删除队头元素
* EnQueue_Sq(SqQueue &Q, ElemType e)//队尾插入元素
* VisitQueue_Sq(SqQueue Q)//遍历队列
* GetHead_Sq(SqQueue Q, ElemType &e)//获得队头元素
* DestroyQueue_Sq(SqQueue &Q)//销毁队列
>队列判空的条件：若Q.front=Q.rear=0；则队列为空
<br/>队列判满的条件：若(Q.rear + 1) % Q.maxSize == Q.front；则队列已满
<br/>队头元素出队后：Q.front = (Q.front + 1) % Q.maxSize;//Q.front循环加1
<br/>队尾插入元素后：Q.rear = (Q.rear + 1) % Q.maxSize;//Q.rear向后移一个单位
