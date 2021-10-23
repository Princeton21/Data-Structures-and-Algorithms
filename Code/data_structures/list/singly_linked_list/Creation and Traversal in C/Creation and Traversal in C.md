
# Creation and Traversal of a Singly Linked List in C

In this tutorial we will see creation and traversal of a Singly Linked List using C.
Let us see a brief introduction of a Linked List and some other basic concepts.

## What is a Linked List?
A Linked List is a linear data structure,in which non-contiguous memory allocation takes place.
Each element in a linked list is known as a node. These elements or **nodes** are linked using pointers as shown below:
![image](https://drive.google.com/uc?id=1C5X9QXPL6zchl4t79L-Ox1hHGv40duzb)

A node has atleast 2 data fields present. The first field which is called as **'data'** consists of the value which we wish to store and the second field ; also known as **'next'** consists of address of the next node.

## Benefits of Linked Lists over Arrays
In a Linked List,there are no indices(index) like Arrays.
* Memory is allocated dynamically in a Linked List unlike Arrays. We can allocate memory while programming and this ensure use of memory with precision.
* Insertion and Deletion of elements is easy in linked lists.
* Non-Contigous allocation of memory.

## Creation and Traversal of a linked list in C 
We will now move on to creation of a Linked list in C and how to traverse through the linked list.
Refer the following points before going through the snippet of code.

* An element in a linked list is a **struct Node**. It is made to hold integer data and a pointer of data type struct Node *, as it has to point to another struct Node. 
* We’ll create the below illustrated linked list.
![image](https://drive.google.com/uc?id=1o5YzVb-_fpEfR4Vr0catQFlhLLUVgr21)
* Firstly,we will create individual nodes and link them to the next node using the arrow operator ‘→’.
* Then, we’ll define a structure Node and create two of its members, an int variable data, to store the current node's value and a struct node * pointer variable next. 
* Now, we can move on to our main() and start creating these nodes. We’ll name the first node, head. Define a pointer to head node by struct node* head. And similarly for the other nodes. Request the memory location for each of these nodes from heap via malloc using the below snippet.
  
  ```struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));```
* Link these nodes using the arrow operator and call the traversal function.
* Create a void function LinkedListTraversal and pass into it the pointer to the head node.
* Run a while loop while the pointer doesn’t point to a NULL. And keep changing the pointer next each time you are done printing the data of the current node.

