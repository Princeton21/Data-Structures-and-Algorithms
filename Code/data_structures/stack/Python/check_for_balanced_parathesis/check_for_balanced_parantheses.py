# code to Check for balanced parentheses in an expression

# Function to check parentheses
def par_check(myStr):
    open = ["[","{","("]
    close = ["]","}",")"]
    stack = []
    for i in myStr:
        if i in open:
            stack.append(i)
        elif i in close:
            cls = close.index(i)
            if ((len(stack) > 0) and
                (open[cls] == stack[len(stack)-1])):
                stack.pop()
            else:
                print("The string is Unbalanced")
                return 0
    if len(stack) == 0:
        print("The string is Balanced")
        return 0
    else:
        print("The string is Unbalanced")
        return 0
  
  
string = "({[]}())"
par_check(string)
  
string = "{(})[]"
par_check(string)