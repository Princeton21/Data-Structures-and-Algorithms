typedef struct node
{
    int data;
    struct node *llink;
    struct node *rlink;
}NODE;
typedef struct DLL
{
    NODE *head;
}DLL;
#include<stdio.h>
#include<stdlib.h>
NODE* getnode()
{
    NODE *temp=(NODE*)malloc(sizeof(NODE));
    if(temp==NULL)
        printf("\nout of memory\n");
    else
    {
        printf("\nenter the data\n");
        scanf("%d",&temp->data);
        temp->llink=NULL;
        temp->rlink=NULL;
    }
    return temp;
}
void ins_beg(DLL *list)
{
    NODE *temp=getnode();
    if(list->head==NULL)
    {
        list->head=temp;
    }
    else
    {
        list->head->llink=temp;
        temp->rlink=list->head;
        list->head=temp;
    }
}
void ins_end(DLL *list)
{
    NODE *temp=getnode();
    if(list->head==NULL)
    {
        list->head=temp;
    }
    else
    {
        NODE *p=list->head;
        while(p->rlink!=NULL)
        {
            p=p->rlink;
        }
        p->rlink=temp;
        temp->llink=p;
    }
}
void del_beg(DLL *list)
{
    if(list->head==NULL)
        printf("\nthe list is empty\n"); 
    else
    {
        NODE *p=list->head;
        printf("\nthe data %d has been deleted\n",p->data);
        if((list->head->rlink==list->head->llink) && list->head->llink==NULL)
            list->head=NULL;   
        else
        { 
            list->head=p->rlink;
            list->head->llink=NULL;
        }
        free(p);
        p=NULL;
    }
}
void del_end(DLL *list)
{
    if(list->head==NULL)
        printf("\nthe list is empty\n"); 
    else
    {
        NODE *p=list->head;
        while(p->rlink!=NULL)
            p=p->rlink;
        printf("\nthe data %d has been deleted\n",p->data);
        if((list->head->rlink==list->head->llink) && list->head->llink==NULL)
            list->head=NULL;   
        else
            (p->llink)->rlink=NULL;
        free(p);
        p=NULL;
    }
}
void display(DLL *list)
{
    NODE *p=list->head;
    if(list->head==NULL)
        printf("\nthe list is empty\n");
    else
    {
        while(p!=NULL)
        {
            printf("\n%p\t%d\t%p\t\n",p->llink,p->data,p->rlink);
            p=p->rlink;
        }
    }
}
int main(void)
{
    DLL *list;
    list->head=NULL;
    int op;
    retry:
    printf("\n\t\tDOUBLY LINKED LIST\n");
    printf("\nchoose your option\n");
    printf("1.insert from beginning\n2.insert from end\n3.delete from beginning\n4.delete from end\n5.display list\n6.exit\n\n");
    scanf("%d",&op);
    switch(op)
    {
        case 1:     ins_beg(list);
                    break;
        case 2:     ins_end(list);
                    break;
        case 3:     del_beg(list);
                    break;
        case 4:     del_end(list);
                    break;
        case 5:     display(list);
                    break;
        case 6:     exit(0);
                    break;
        default:    printf("\ninvalid option,please retry\n");
    }
    goto retry;
}