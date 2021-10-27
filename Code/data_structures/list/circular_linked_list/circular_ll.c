//program to implement circular linked list
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *link;
}NODE;
typedef struct list
{
    NODE *tail;
}CLL;
NODE* getnode()
{
    NODE *temp=(NODE*)malloc(sizeof(NODE));     //dynamic memory allocation
    if(temp==NULL)      //memory full condition
        printf("\nout of memory\n");
    else    //entering of data into node
    {
        printf("\nenter the data ");
        scanf("%d",&(temp->data));
    }
    temp->link=NULL;    //setting link as NULL as a default value
    return temp;    //return of pointer of new node
}
void ins_beg(CLL *cl)
{
    NODE *temp=getnode();
    if(cl->tail==NULL)
    {
        cl->tail=temp;
        temp->link=temp;
    }
    else
    {
        temp->link=cl->tail->link;
        cl->tail->link=temp;
    }
}
void ins_end(CLL *cl)
{
    NODE *temp=getnode();
    if(cl->tail==NULL)
    {
        cl->tail=temp;
        temp->link=temp;
    }
    else
    {
        temp->link=cl->tail->link;
        cl->tail->link=temp;
        cl->tail=temp;
    }
}
void del_beg(CLL *cl)
{
    if(cl->tail==NULL)
        printf("\nthe list is empty\n");
    else
    {
        NODE *temp=cl->tail->link;
        cl->tail->link=temp->link;
        printf("\nthe deleted node is %d",temp->data);
        free(temp);
    }
}
void del_end(CLL *cl)
{
    if(cl->tail==NULL)
        printf("\nthe list is empty\n");
    else
    {
        NODE *temp=cl->tail->link,*prev=NULL;
        while(temp!=cl->tail)
        {
            prev=temp;
            temp=temp->link;
        }
        prev->link=temp->link;
        cl->tail=prev;
        printf("\nthe deleted node is %d",temp->data);
        free(temp);
    }
}
void display(CLL *cl)  
{
    NODE *p=cl->tail->link;  //pointer to traverse through list
    if(p==NULL) //empty list condition
        printf("\nthe list is empty\n");
    else
    {
        while(p!=cl->tail)  //loop for traversal of list
        {
            printf("%d\t",p->data); //printing of node
            p=p->link;
        }
    }
}
int main(void)
{
    CLL *list;
    list->tail=NULL;
    int op;
    retry:  //menu for implementation 
    printf("\n\t\tLINKED LIST\n");
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
