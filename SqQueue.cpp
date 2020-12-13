#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;
typedef int Status;
#define OK 1
#define ERROR 0
int k = 1;		//当k=0时，退出程序
int d = 1;		//当d=0时，表示队列已被销毁

#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#pragma warning(disable:4996);

/*循环队列的顺序存储结构*/
typedef struct {
	ElemType *base;	//存储空间的基址
	int front;		//队头位标
	int rear;		//队尾位标，指示队尾元素的下一个位置
	int maxSize;	//最大长度
}SqQueue;

/*
初始化循环队列
*/
Status InitQueue_Sq(SqQueue &Q,int size) {
	Q.base = (ElemType *)malloc(size * sizeof(ElemType));
	if (Q.base == NULL) {
		return ERROR;
	}
	Q.front = Q.rear = 0;
	Q.maxSize = size;
	d = 1;
	return OK;
}

/*
销毁循环队列
*/
Status DestroyQueue_Sq(SqQueue &Q) {
	free(Q.base);
	Q.base = NULL;
	Q.front = Q.rear = 0;
	d = 0;
	return OK;
}

/*
清空循环队列
*/
Status ClearQueue_Sq(SqQueue &Q) {
	Q.front = Q.rear = 0;
	return OK;
}

/*
循环队列判空
*/
Status EmptyQueue_Sq(SqQueue Q) {
	if (Q.front == Q.rear) {
		return OK;
	}
	return ERROR;
}

/*
循环队列的长度
*/
int LengthQueue_Sq(SqQueue Q) {
	return (Q.rear - Q.front + Q.maxSize) % Q.maxSize;
}

/*
获得队头元素
*/
Status GetHead_Sq(SqQueue Q, ElemType &e) {
	if (Q.front == Q.rear) {
		return ERROR;
	}
	e = Q.base[Q.front];
	return OK;
}

/*
入队
*/
Status EnQueue_Sq(SqQueue &Q, ElemType e) {
	//判断队列是否已满
	if ((Q.rear + 1) % Q.maxSize == Q.front) {
		return ERROR;
	}
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % Q.maxSize;
	return OK;
}

/*
出队
*/
Status DeQueue_Sq(SqQueue &Q, ElemType &e) {
	//若队列不空，则删除队列Q中的对头元素，用e返回其值
	if (Q.front == Q.rear) {
		return ERROR;
	}
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % Q.maxSize;	//Q.front循环加1
	return OK;
}

/*
遍历循环队列
*/
void VisitQueue_Sq(SqQueue Q) {
	if (Q.front == Q.rear) {
		printf("队列为空！\n");
		return;
	}
	while (1) {
		printf("%d  ", Q.base[Q.front]);
		Q.front = (Q.front + 1) % Q.maxSize;
		if (Q.front == Q.rear) {
			break;
		}
	}
	printf("\n");
}

void menu(SqQueue &Q) {
	float choose;
	int n;
	printf("请根据需要输入数字代号：");
	n = scanf("%f", &choose);
	while (n == 0) {
		while (getchar() != '\n');
		printf("亲，您输入的不是数字哦！！");
		printf("请重新选择：");
		n = scanf("%f", &choose);
	}
	int Rchoose;
	Rchoose = (int)choose;
	switch (Rchoose)
	{
	case 1:
		if (d == 1) {
			printf("循环队列已存在，无需初始化！\n");
		}
		else {
			int size;
			printf("请确定循环队列的容量大小：");
			scanf("%d", &size);
			InitQueue_Sq(Q, size);
			printf("循环队列初始化成功！循环队列的容量大小为%d\n", size);
		}
		break;
	case 2:
		if (d == 0) {
			printf("队列已被销毁，请先初始化队列！\n");
		}
		else {
			if (EmptyQueue_Sq(Q)) {
				printf("队列为空！\n");
			}
			else {
				printf("队列不为空！\n");
			}
		}
		break;
	case 3:
		if (d == 0) {
			printf("队列已被销毁，请先初始化队列！\n");
		}
		else {
			int len;
			len = LengthQueue_Sq(Q);
			printf("队列的长度为：%d\n", len);
		}
		break;
	case 4:
		if (d == 0) {
			printf("队列已被销毁，请先初始化队列！\n");
		}
		else {
			ClearQueue_Sq(Q);
			printf("队列已清空！\n");
		}
		break;
	case 5:
		if (d == 0) {
			printf("队列已被销毁，请先初始化队列！\n");
		}
		else {
			ElemType e;
			if (DeQueue_Sq(Q, e)) {
				printf("队头元素已出队，该元素为：%d\n", e);
			}
			else {
				printf("队列为空！\n");
			}
		}
		break;
	case 6:
		if (d == 0) {
			printf("队列已被销毁，请先初始化队列！\n");
		}
		else {
			ElemType e;
			printf("请输入要插入的数据：");
			scanf("%d", &e);
			EnQueue_Sq(Q, e);
			printf("插入元素成功！\n");
		}
		break;
	case 7:
		if (d == 0) {
			printf("队列已被销毁，请先初始化队列！\n");
		}
		else {
			printf("遍历队列中的元素，输出如下：\n");
			VisitQueue_Sq(Q);
		}
		break;
	case 8:
		if (d == 0) {
			printf("队列已被销毁，请先初始化队列！\n");
		}
		else {
			DestroyQueue_Sq(Q);
			printf("队列已被销毁！\n");
		}
		break;
	case 0:
		printf("程序已退出！\n");
		k = 0;
		break;
	default:
		printf("请在0-8之间选择！\n");
	}
}

int main() {
	SqQueue Q;
	InitQueue_Sq(Q,10);
	printf("\n*******************************************************************************\n");
	printf("**************************数 据 结 构 之 循 环 队 列***************************\n");
	printf("***************************作 者：薛 云（3219005084)***************************\n");
	printf("*                            1.初始化队列                                     *\n");
	printf("*                            2.队列判空                                       *\n");
	printf("*                            3.队列长度                                       *\n");
	printf("*                            4.清空清空                                       *\n");
	printf("*                            5.删除队头元素                                   *\n");
	printf("*                            6.队尾插入元素                                   *\n");
	printf("*                            7.遍历队列                                       *\n");
	printf("*                            8.销毁队列                                       *\n");
	printf("*                            0.退出                                           *\n");
	printf("*******************************************************************************\n");
	printf("*******************************************************************************\n");
	printf("\n-------------------默认循环队列已初始化完毕，最大长度为10——------------------\n\n");
	while (k) {
		menu(Q);
	}
	return 0;
}
