#include <bits/stdc++.h>
using namespace std;

struct Node //defining the structure
{
    int data;
    Node *next;
    Node(int value)
    {
        data = value;
        next=NULL;
    }
};
void traverseAndPrint(Node *head)
{
    if(head==NULL)
    return;
    cout<<(head->data)<<" ";
    for(Node *i = head->next; i!=head; i=i->next)
    cout<<(i->data)<<" ";//printing the data
}
int main()
{
    Node *head = new Node(21);//creating head node
    head->next = new Node(7);//creating second node
    head->next->next = new Node(9);//creating third node
    head->next->next->next = new Node (10);//creating fourth node
    head->next->next->next->next=head;
    traverseAndPrint(head);
    return 0;
}