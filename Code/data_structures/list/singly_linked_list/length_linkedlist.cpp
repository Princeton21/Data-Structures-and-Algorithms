#include <iostream>
using namespace std;

class node
{
public:
     int data;
     node *next;

     node(int val)
     {
          data = val;
          next = NULL;
     }
};
node *input()
{
     int data;
     cin >> data;
     node *head = NULL; //LL is empty
     node *tail = NULL; //LL is empty
     while (data != -1)
     {
          // creating node
          node *n = new node(data);
          // checking
          if (head == NULL)
          {
               head = n;
               tail = n;
          }
          else
          {
               tail->next = n;
               tail = n;
          }
          cin >> data;
     }
     return head;
}

void lenght(node *head)
{
     int l = 0;
     while (head != NULL)
     {
          l++;
          head = head->next;
     }
     cout << "Lenght of list is: " << l << endl;
}
int main()
{
     node *head;
     head = input();
     lenght(head);
}
