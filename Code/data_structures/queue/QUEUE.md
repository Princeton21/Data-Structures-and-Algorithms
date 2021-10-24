# QUEUE 

#### DEFINITION
Queue is a linear structure which follows a particular order in which the operations are performed. The order is **F**irst **I**n **F**irst **O**ut (FIFO). A good example of queue is any queue of consumers for a resource where the consumer that came first is served first.

### Operations on Queue: 
Mainly the following four basic operations are performed on queue:  
**Enqueue:** Adds an item to the queue. If the queue is full, then it is said to be an Overflow condition.  
**Dequeue:** Removes an item from the queue. The items are popped in the same order in which they are pushed. If the queue is empty, then it is said to be an Underflow condition.  
**Front:** Get the front item from queue.  
**Rear:** Get the last item from queue.

#### CODE

  

     #include <iostream>
    
    #include <cstdlib>
    
    using  namespace  std;
    
    // Define the default capacity of a queue
    
    #define SIZE 10
    
    // A class to store a queue
    
    class  queue
    
    {
    
    int  *arr;  // array to store queue elements
    
    int  capacity;  // maximum capacity of the queue
    
    int  front;  // front points to the front element in the queue (if any)
    
    int  rear;  // rear points to the last element in the queue
    
    int  count;  // current size of the queue
    
    public:
    
    queue(int  size  =  SIZE);  // constructor
    
    ~queue();  // destructor
    
    void  dequeue();
    
    void  enqueue(int  x);
    
    int  peek();
    
    int  size();
    
    bool  isEmpty();
    
    bool  isFull();
    
    };
    
    // Constructor to initialize a queue
    
    queue::queue(int  size)
    
    {
    
    arr  =  new  int[size];
    
    capacity  =  size;
    
    front  =  0;
    
    rear  =  -1;
    
    count  =  0;
    
    }
    
    // Destructor to free memory allocated to the queue
    
    queue::~queue()  {
    
    delete[]  arr;
    
    }
    
    // Utility function to dequeue the front element
    
    void  queue::dequeue()
    
    {
    
    // check for queue underflow
    
    if  (isEmpty())
    
    {
    
    cout  <<  "Underflow\nProgram Terminated\n";
    
    exit(EXIT_FAILURE);
    
    }
    
    cout  <<  "Removing "  <<  arr[front]  <<  endl;
    
    front  =  (front  +  1)  %  capacity;
    
    count--;
    
    }
    
    // Utility function to add an item to the queue
    
    void  queue::enqueue(int  item)
    
    {
    
    // check for queue overflow
    
    if  (isFull())
    
    {
    
    cout  <<  "Overflow\nProgram Terminated\n";
    
    exit(EXIT_FAILURE);
    
    }
    
    cout  <<  "Inserting "  <<  item  <<  endl;
    
    rear  =  (rear  +  1)  %  capacity;
    
    arr[rear]  =  item;
    
    count++;
    
    }
    
    // Utility function to return the front element of the queue
    
    int  queue::peek()
    
    {
    
    if  (isEmpty())
    
    {
    
    cout  <<  "Underflow\nProgram Terminated\n";
    
    exit(EXIT_FAILURE);
    
    }
    
    return  arr[front];
    
    }
    
    // Utility function to return the size of the queue
    
    int  queue::size()  {
    
    return  count;
    
    }
    
    // Utility function to check if the queue is empty or not
    
    bool  queue::isEmpty()  {
    
    return  (size()  ==  0);
    
    }
    
    // Utility function to check if the queue is full or not
    
    bool  queue::isFull()  {
    
    return  (size()  ==  capacity);
    
    }
    
    int  main()
    
    {
    
    // create a queue of capacity 5
    
    queue  q(5);
    
    q.enqueue(1);
    
    q.enqueue(2);
    
    q.enqueue(3);
    
    cout  <<  "The front element is "  <<  q.peek()  <<  endl;
    
    q.dequeue();
    
    q.enqueue(4);
    
    cout  <<  "The queue size is "  <<  q.size()  <<  endl;
    
    q.dequeue();
    
    q.dequeue();
    
    q.dequeue();
    
    if  (q.isEmpty())  {
    
    cout  <<  "The queue is empty\n";
    
    }
    
    else  {
    
    cout  <<  "The queue is not empty\n";
    
    }
    
    return  0;
    
    }

**Output:**  
  
Inserting 1  
Inserting 2  
Inserting 3  
The front element is 1  
Removing 1  
Inserting 4  
The queue size is 3  
Removing 2  
Removing 3  
Removing 4  
The queue is empty  


  ##### TIME COMPLEXITY
The time complexity of all the above queue operations is  O(1).



