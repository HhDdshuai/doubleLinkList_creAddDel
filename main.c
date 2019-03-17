#include <stdio.h>
#include <stdlib.h>

typedef int elemType;
typedef int status;
typedef struct DNode{
	elemType data;
	struct DNode *prior,*next;
}DNode,*DoubLinkList;
//����˫����
DNode *creatDoubleList(){
	DNode *L,*s,*r;
	elemType x;
	L = (DNode *)malloc(sizeof(DNode));
	if(L == NULL){
		printf("�ռ����ʧ��\n");
		exit(0);
	}
	r = L;
	scanf("%d",&x);
	while(x != 65535){
		s = (DNode *)malloc(sizeof(DNode));
		if(s == NULL){
			printf("�ռ����ʧ��\n");
			exit(0);
		}
		s->data = x;
		s->prior = r;
		r->next = s;
		r=s;
		scanf("%d",&x);
	}
	r->next = NULL;
	L->prior = NULL;
	return L;
}
//��ӡ˫����
void printDLinkList(DNode *L){
	DNode *p,*r;
	p = L->next;
	printf("����������:\n");
	while(p){
		printf("%d->",p->data);
		r = p;
		p = p->next;
	}
	printf("\n����������:\n");
	while(r->prior){
		printf("%d->",r->data);
		r = r->prior;
	}
	printf("\n");
}
//����һ�����
status DList_insert(DNode *L,int i,elemType e){
	DNode *p = L;
	int j = 0;
	while(p && j < i - 1){
		p = p->next;
		++j;
	}
	if(p == NULL || (j > i - 1)){    //�������λ�ù�����ôp=NULL,��������λ����0���߸�������ôj>i-1
		printf("����λ�ò���\n");
		return 0;
	}
	else{
		DNode *s = (DNode *)malloc(sizeof(DNode));
		if(s == NULL){
			printf("�ռ����ʧ��\n");
			exit(0);
		}
		s->data = e;
		s->next = p->next;
		s->prior = p;
		p->next->prior = s;
		p->next = s;
		return 1;
	}
}
//ɾ��һ�����
status DList_del(DNode *L,int i,elemType *e){
	int j = 0;
	DNode *p = L,*q;
	while(p->next != NULL && j < i - 1){   //Ҫɾ��p��ָԪ�صĺ�̣�p->next����Ϊ��
		p = p->next;
		++j;
	}
	if(p->next == NULL || j > i - 1){
		printf("ɾ��λ�ò���ȷ.\n");
		return 0;
	}else{
		q = p->next;
		p->next = q->next;
		q->next->prior = p;
		*e = q->data;
		free(q);
		return 1;
	}
}
int main(){
	DNode *L;
	elemType e;
	L = creatDoubleList();
	printDLinkList(L);
	if(DList_insert(L,5,520)){
		printf("����ɹ�.\n");
		printDLinkList(L);
	}
	if(DList_del(L,5,&e)){
		printf("ɾ���ɹ�.ɾ��Ԫ��Ϊ %d\n",e);
		printDLinkList(L);
	}
	system("pause");
	return 0;
}
