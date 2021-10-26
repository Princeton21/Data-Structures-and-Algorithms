# nutshell
the idea of the code is to check for opening parantheses in a string and storing(pushed) in a data structure called stack(in our code it is list itself,as list can also be functioned as stack), and by iterating further string finding its closing parantheses in its respective position to its corresponding opening parantheses and poping all opening parantheses which were pushed 
if stack got empty, the string is balanced or else it will be unbalanced

## Steps:
- firstly if any opening parantheses was found,it goes to 'if' block push the opening paranthesis to list named stack by iterating through 
  user given string
- if any closing parantheses was found, it goes to 'else' block and checks its respective position matches with its corresponding opening 
  parantheses 
- by iterating through all over the string by following above two basic operations, we try to empty the stack
- if the stack gotten empty, function prints "The string is Balanced" and returns 0
- if the stack is not empty, function prints "The string is Unbalanced" and returns 0
- the other case where the string have closing parantheses before opening parantheses(addresses in secong basic rule) prints "The string is 
  Unbalanced" and returns 0 
