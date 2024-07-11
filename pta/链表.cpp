/**
 * 哈哈哈哈哈哈，第一次一遍出答案，加油，干就完了
*/






#include<stdio.h>
#include <malloc.h>
typedef struct node{
    struct node *next;
    int v;
}Listnode,*List;

List init(int num,int *a){
    List list;
    list=(List)malloc(sizeof(Listnode));
    List rear=list;
    for(int i=0;i<num;i++)
    {
        List node=(List)malloc(sizeof(Listnode));
        node->v=a[i];
        rear->next=node;
        rear=node;
        rear->next=NULL;
    }
    return list;
}
List findpos(List list,int pos)
{

}
void insert(List list,int pos,int key)
{
    List node=(List)malloc(sizeof(Listnode));
    node->v=key;
    if(pos==0)
    {   
        node->next=list->next;
        list->next=node;
    }
    else 
    {
        int t=0;
        List p=list->next;
        while(p!=NULL)
        {
            t++;
            if(t==pos)
                break;
            p=p->next;
        }
        if(t==pos)
        {
            List temp=p->next;
            p->next=node;
            node->next=temp;
        }
    }
}
void delet(List list,int pos)
{
    
        int t=0;
        List p=list->next;
        List h=list;
        while(p!=NULL)
        {
            t++;
            if(t==pos)
                break;
            h=h->next;
            p=p->next;
        }
        if(t==pos)
        {
            h->next=p->next;
            free(p);
        }
}
void show(List list)
{
    List node =list->next;
    while(node!=NULL)
    {
        printf("%d ",node->v);
        node=node->next;
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    int a[n+1];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    List list=init(n,a);
    int m;
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        int type;
        scanf("%d",&type);
        if(type==0)
        {
            int pos;
            scanf("%d",&pos);
            int key;
            scanf("%d",&key);
            insert(list,pos,key);
        }
        else if(type==1)
        {
            int pos;
            scanf("%d",&pos);
            delet(list,pos);
        }
    }
    show( list);
}