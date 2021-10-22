#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *next;
}*start=NULL;

struct node *createNode()
{
    struct node *n;
    n=(struct node*)malloc(sizeof(struct node));
    return n;
}

void insertNode()
{
    struct node *temp,*t;
    temp=createNode();
    printf("Enter The Number: ");
    scanf("%d",&temp->data);
    t=start;
    if(start==NULL)
      {
         start=temp;
         temp->next=NULL;
      }
    else{
        while(t->next!=NULL)
            t=t->next;
        t->next=temp;
        temp->next=NULL;
    }

}

void deleteNode()
{
    struct node *r,*t;
    r=start;
    t=start;
    while(r->next!=NULL)
        r=r->next;
    while(t->next!=r)
        t=t->next;
    t->next=NULL;
    free(r);
}

int main()
{
    while(1)
    {
    int choice;
    printf("\n1. Create\n");
    printf("2. Delete\n");
    printf("9. Exit\n");
    scanf("%d",&choice);
        switch(choice)
        {
            case 1:insertNode();break;
            case 2:deleteNode();break;
            case 9:exit(0);break;
            default:printf("INVALID INPUT");
                    exit(0);
        }
    }
    return 0;
}
