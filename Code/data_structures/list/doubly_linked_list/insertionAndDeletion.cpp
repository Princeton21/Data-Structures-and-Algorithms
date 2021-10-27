#include <bits/stdc++.h>
using namespace std;

struct Node //defining the structure
{
    int data;
    Node *next;
    Node *prev;
    Node(int value)
    {
        data = value;
        next=NULL;
        prev=NULL;
    }
};
Node *insertHead(Node *head,int data)//insertion at the head of linked list
{
    Node *temp=new Node(data);
    temp->next=head;
    if(head!=NULL)
    head->prev=temp;
    return temp;//returning head of modified linked list
}
Node *insertEnd(Node *head,int data)//insertion at the end of linked list
{
    Node *temp=new Node(data);
    if(head==NULL)
     return temp;
    Node *curr=head;
    while(curr->next!=NULL)//for going to last node of the linked list
     curr=curr->next;
    curr->next=temp;
    temp->prev=curr;
    return head;//returning head of modified linked list
}
Node *deleteHead(Node *head)//deleteing the head node
{
    if(head==NULL)//linked list is empty
     return NULL;
    if(head->next==NULL)//lnked list has one element
    {
        delete head;
        return NULL;
    }
    else
    {
        Node *temp=head;
        head=head->next;
        head->prev=NULL;
        delete temp;
        return head;//returning head of modified linked list
    }
}
Node *deleteEnd(Node *head)//deleteing the last node
{
    if(head==NULL)//linked list is empty
     return NULL;
    if(head->next==NULL)//lnked list has one element
    {
        delete head;
        return NULL;
    }
    else
    {
        Node *curr=head;
        while(curr->next!=NULL)//for going to last node of the linked list
         curr=curr->next;
        curr->prev->next=NULL;
        delete curr;
        return head;//returning head of modified linked list
    }
}
int main()
{
    Node *head=NULL;
    head=insertHead(head,10);
    head=insertEnd(head,40);
    head=insertHead(head,20);
    head=insertEnd(head,30);
    head=insertHead(head,50);
    head=insertEnd(head,60);
    head=deleteHead(head);
    head=deleteEnd(head);
}