DoubleLinkedList {  

              DoubleNode head;  

              DoubleNode tail;  

             int size;  

      

     DoubleNode CreateDoublyLL(int nodeValue){  

                 head = new DoubleNode();  

                DoubleNode node = new DoubleNode();  

                node.setValue(nodeValue);  

                node.setNext(null);  

               node.setPrev(null);  

               head = node;  

              tail=node;  

              size = 1;  

              return head;  

       

           }  

}  
