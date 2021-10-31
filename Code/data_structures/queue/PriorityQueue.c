#include<stdio.h>

#include<conio.h>

#include<malloc.h>

typedef struct que

{

    int info,prio;

    struct que *next;

}nodetype;

void insert(nodetype**,nodetype**,int,int);

void serve(nodetype**,nodetype**);

void display(nodetype*);

void main()

{

    nodetype *front=NULL,*rear=NULL;

    int ch,pr,num,c=0;

    printf("Menu\n1.Insert\n2.serve\n3.Display\n4.Exit\nChoice : ");

    do

    {

        scanf("%d",&ch);

        switch(ch)

        {

             case 1: printf("\nEnter the number to be inserted and its priority : ");

             scanf("%d  %d",&num,&pr);

             insert(&front,&rear,num,pr);

             break;

             case 2: if(front==NULL)

             printf("\nNo elements are present in the Priority Queue");

             else

             serve(&front,&rear);

             break;

             case 3: if(front==NULL)

             printf("\nNo elements in the Priority Queue");

             else

             display(front);

             break;

             default:

             printf("\nEnter the correct choice");

        }

        printf("press 1 to continue\n");

        scanf("%d",&c);

    }while(c==1);

}

void insert(nodetype **front,nodetype **rear,int num,int pr)

{

    nodetype *p=NULL,*tmp=*front;

    p=(nodetype*)malloc(sizeof(nodetype));

    if(p!=NULL)

    {

         p->info=num;

         p->prio=pr;

         p->next=NULL;

    }

    if((*rear)==NULL)

    {

         (*front)=(*rear)=p;

    }

    else

    {

         if((p->prio)>((*rear)->prio))

         {

              (*rear)->next=p;

              (*rear)=p;

         }

         else if(p->prio<((*front)->prio))

         {

              p->next=(*front);

              (*front)=p;

         }

         else

         {

              while(((tmp->next)->prio)<(p->prio))

              tmp=tmp->next;

              p->next=tmp->next;

              tmp->next=p;

         }

    }

}

void serve(nodetype **front,nodetype **rear)

{

    nodetype *tmp=*front;

    if((*front)==(*rear))

    {

        printf("The served element is %d",(*front)->info);

        (*rear)=(*front)=NULL;

    }

    else

    {

        printf("The served element is %d",(*front)->info);

        (*front)=(*front)->next;

    }

    free(tmp);

}

void display(nodetype *front)

{

    nodetype *tmp;

    tmp=front;

    while(tmp!=NULL)

    {

         printf("%d ",tmp->info);

         tmp=tmp->next;

    }

}
