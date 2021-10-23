#include<stdio.h>
#include<stdlib.h>

struct Node{  //defining  a structure
    int data;
    struct Node * next;
}; //semicolon is important

void LinkedListTraversal(struct Node * ptr){
    while (ptr !=NULL)
    {
    printf("Element: %d\n", ptr->data);
    ptr = ptr->next;
    }
}
int main(){
   struct Node * head;  //Creating a Head node
   struct Node * second; //Creating second node
   struct Node * third; //creating a third node
   struct Node * fourth; //creating a fourth node
   head = (struct Node *) malloc(sizeof(struct Node)); //allocating memory dynamically in heap
   second = (struct Node *) malloc(sizeof(struct Node));
   third = (struct Node *) malloc(sizeof(struct Node));
   fourth = (struct Node *) malloc(sizeof(struct Node));

   //Linking the first and second nodes
   head ->data = 7;
   head ->next = second;

   //Linking the second and third node
   second ->data = 11;
   second ->next = third;

   //Linking the third and fourth node
   third ->data =  64;
   third ->next = fourth;
   
   //Terminate the linked list at third node
   fourth ->data = 57;
   fourth ->next = NULL;
   
   LinkedListTraversal(head);
   return 0;
}
