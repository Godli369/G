#define MAX  20
#include <stdlib.h>
#include <stdio.h>
typedef struct SqQueue{
	int *base;
	int front;
	int rear;
}SqQueue;//���Զ���

void InitQueue(SqQueue *Q)
{//����һ������
	Q->base=(int*)malloc(MAX * sizeof(SqQueue));
	Q->front=Q->rear=0;
}

int EnQueue(SqQueue *Q,int e)//���
{	if((Q->rear+1)%MAX==Q->front)
		exit(0);
	Q->base[Q->rear]=e;
	Q->rear=(Q->rear+1)%MAX;
	return e;
}

int DeQueue(SqQueue *Q,int e)
{//���ǿն���Q�еĶ�ͷԪ�س�����

	if(Q->front==Q->rear)
		exit(0);
	e=Q->base[Q->front];
	Q->front=(Q->front+1)%MAX;
	return e;
}

int GetHead(SqQueue Q,int e)
{//��e���ض���Q�Ķ�ͷԪ��
	if(Q.front==Q.rear)
		exit(0);
	e=Q.base[Q.front];
	return e;
	
}
void Party(SqQueue *Q1,SqQueue *Q2)
{//������Q1��Q2�еĳ�Ա���
	int i,m,w,xm,ls,k,j,x,y;
	printf("\n\n");
	printf("\t**************************************\n\n");
	printf("\t>>>>>>>>>>>>>>>������<<<<<<<<<<<<<<<\n\n");
	printf("\t**************************************\n\n");
	printf("\t>>>>>>>>>>>>>>�����Ѵ���<<<<<<<<<<<<<<<\n");
	printf("\t>>>>>>>>>>>>>�밴��ʾ����<<<<<<<<<<<<<<\n\n");
	InitQueue(Q1);  
	printf("\t\t^^^���������������^^^\n");
	scanf("\t\t%d",&m);
	printf("\t\t^^^�������������^^^\n");
	for(i=0;i<m;i++)
	{
		scanf("\t\t%d",&xm);
		EnQueue(Q1,xm);
	}
	InitQueue(Q2);
	printf("\t\t^^^������Ů�������^^^\n");
	scanf("\t\t%d",&w);
	printf("\t\t^^^������Ů�����^^^\n");
	for(i=0;i<w;i++)
	{
		scanf("\t\t%d",&xm);
		EnQueue(Q2,xm);
	}
	printf("\t\t^^^��������������^^^\n");
	scanf("\t\t%d",&ls);
	printf("\n");
	printf("\t************�����Խ��************\n\n");
    if(m>w)k=w;
	else k=m;
	for(i=0;i<ls;i++)
	{
		printf("\t\t^^^��%d�ֳ������:^^^\n",i+1);
		for(j=0;j<k;j++)
		{
		
			x=DeQueue(Q1,m);
			y=DeQueue(Q2,w);
			printf("\t\t%d<------->%d\n",x,y);
			EnQueue(Q1,x);
			EnQueue(Q2,y);
		}
		x=GetHead(*Q1,m);
		y=GetHead(*Q2,w);
	    printf("\t\t��һ��Ҫ��Ե�����ǣ�\n");
		printf("\t\t%d��%d\n\n",x,y);

	}
}

void main()
{   
	
	SqQueue Q1;
	SqQueue	Q2;
    Party(&Q1,&Q2);
	
}
