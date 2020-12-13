## 1、顺序栈（SqStack）
```c
typedef struct SqStack {
	ElemType *elem;	    //存储空间的基址
	int top;		        //栈顶元素的下一个位置，简称栈顶位标
	int size;		        //当前分配的存储容量
	int increment;	    //扩容时，增加的存储容量
}SqStack;
```
* InitStack_Sq//顺序栈初始化
* StackEmpty_Sq//顺序栈判空
* ClearStack_Sq//清空顺序栈
* Length_Sq//测量栈长度
* Push_Sq//入栈
* Pop_Sq//出栈
* GetTop_Sq//获取栈顶元素
* Visit_Sq//遍历栈
* DestroyStack_Sq//销毁栈
