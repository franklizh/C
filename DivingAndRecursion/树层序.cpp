#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef struct Node
{
	int elem;
	struct Node*Lchild;
	struct Node*Rchild; 
	 
 }Node,*Tree;
 int str[100];int op; 
void CreateBiTree(Tree *bt)
{
	int ch;
	ch=str[op];op++;
	 
    CreateBiTree(&((*bt)->Lchild));
	CreateBiTree(&((*bt)->Rchild));
	(*bt)=(Tree)malloc(sizeof(Node));
	(*bt)->elem=ch;
	 
	
}
void cengxu(Tree bt,int *a)
{
    Tree qu[100];
    int head=0,rear=0;
    int i=0;
    if(bt!=NULL)
    {
        qu[rear++]=bt;
        while(head!=rear)
        {
            if(qu[head]->Lchild)
            {
                qu[rear++]=qu[head]->Lchild;
            }
            if(qu[head]->Rchild)
            {
                qu[rear++]=qu[head]->Rchild;
            }
            a[i++]=qu[head]->elem;
            head++;
        }
    }
}
int main()
{
    Tree bt;
    int n;
    scanf("%d",&n);
    int len=n;
    while(n--)
    {
        int a=0;
        scanf("%d",&str[a++]);

    }
    op=0;
    CreateBiTree(&bt);
    printf("nnn");
    int temp[op+1]={0};
    cengxu(bt,temp);
    for(int i=0;i<len;i++)
        printf("%d ",temp[i]);
    return 0;

}