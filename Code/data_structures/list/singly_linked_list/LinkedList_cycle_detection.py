'''
Given head, the head of a linked list, determine if the linked list has a cycle in it. 
There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. 
Return true if there is a cycle in the linked list. Otherwise, return false.
'''
def hasCycle(self, head):
    slow = fast = head
    while fast and fast.next:
        fast = fast.next.next
        slow = slow.next
        if slow == fast:
            return True
    return False
   
'''
Example:
1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 3, the list with loop. Here idea is to use two pointers, one is slow and one is fast.
At the beginning, both of them at number 1.
Next step, slow pointer at 2 and fast at 3.
Next step, slow pointer at 3 and fast at 5.
Next step, slow pointer at 4 and fast at 3.
Next step, slow pointer at 5 and fast is also 5, so we have the same element and we return True.
'''
