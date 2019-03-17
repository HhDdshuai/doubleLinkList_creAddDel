#include <stdio.h>
#include <stdlib.h>

typedef int elemType;
typedef int status;
typedef struct DNode{
	elemType data;
	struct DNode *prior,*next;
}DNode,*DoubLinkList;
//建立双链表
DNode *creatDoubleList(){
	DNode *L,*s,*r;
	elemType x;
	L = (DNode *)malloc(sizeof(DNode));
	if(L == NULL){
		printf("空间分配失败\n");
		exit(0);
	}
	r = L;
	scanf("%d",&x);
	while(x != 65535){
		s = (DNode *)malloc(sizeof(DNode));
		if(s == NULL){
			printf("空间分配失败\n");
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
//打印双链表
void printDLinkList(DNode *L){
	DNode *p,*r;
	p = L->next;
	printf("正向遍历输出:\n");
	while(p){
		printf("%d->",p->data);
		r = p;
		p = p->next;
	}
	printf("\n反向遍历输出:\n");
	while(r->prior){
		printf("%d->",r->data);
		r = r->prior;
	}
	printf("\n");
}
//插入一个结点
status DList_insert(DNode *L,int i,elemType e){
	DNode *p = L;
	int j = 0;
	while(p && j < i - 1){
		p = p->next;
		++j;
	}
	if(p == NULL || (j > i - 1)){    //如果插入位置过大，那么p=NULL,如果插入的位置是0或者负数，那么j>i-1
		printf("插入位置不对\n");
		return 0;
	}
	else{
		DNode *s = (DNode *)malloc(sizeof(DNode));
		if(s == NULL){
			printf("空间分配失败\n");
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
//删除一个结点
status DList_del(DNode *L,int i,elemType *e){
	int j = 0;
	DNode *p = L,*q;
	while(p->next != NULL && j < i - 1){   //要删除p所指元素的后继，p->next不能为空
		p = p->next;
		++j;
	}
	if(p->next == NULL || j > i - 1){
		printf("删除位置不正确.\n");
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
		printf("插入成功.\n");
		printDLinkList(L);
	}
	if(DList_del(L,5,&e)){
		printf("删除成功.删除元素为 %d\n",e);
		printDLinkList(L);
	}
	system("pause");
	return 0;
}
