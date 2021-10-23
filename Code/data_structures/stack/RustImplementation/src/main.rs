// Implementation of Stack using Vec
// Though Vec do behave like a stack in some sense but in the context of Rust, it is consider as a growable array

pub struct Stack<T> {
    stack: Vec<T>,
}

impl<T> Stack<T> {
    pub fn new() -> Self {
        Stack { stack: Vec::new() }
    }

    pub fn pop(&mut self) -> Option<T> {
        self.stack.pop()
    }

    pub fn push(&mut self, item: T) {
        self.stack.push(item)
    }

    pub fn is_empty(&self) -> bool {
        self.stack.is_empty()
    }

    pub fn length(&self) -> usize {
        self.stack.len()
    }

    pub fn peek(&self) -> Option<&T> {
        self.stack.last()
    }
}

fn main() {
    let mut stack: Stack<isize> = Stack::new();
    stack.push(1);
    stack.push(2);
    
    assert_eq!(stack.length(), 2);
    assert_eq!(*stack.peek().unwrap(), 2);

    let item = stack.pop();
    assert_eq!(item.unwrap(), 2);

    let item2 = stack.pop();
    assert_eq!(item2.unwrap(), 1);

    assert_eq!(stack.is_empty(), true);

}

