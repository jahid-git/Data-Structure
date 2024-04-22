class Stack {
    int capacity = 3;
    int top = -1;
    int[] stack = new int[capacity];
    
    void push(int x){
        if(top < capacity - 1){
            stack[++top] = x;
            System.out.println("Successfully added: " + x);
        } else {
            System.out.println("Exception! Stack Overflow.");
        }
    }
    
    int peek(){
        if(top < 0){
            System.out.println("Exception! Stack Underflow.");
            return -1;
        }
        return stack[top];
    }
    
    int pop(){
        if(top < 0){
            System.out.println("Exception! Stack Underflow.");
            return -1;
        }
        int val = stack[top];
        top--;
        return val;
    }
    
    public static void main (String[] args) {
        
        System.out.println("Implementing Stack by java");
        
        Stack stackObj = new Stack();
        System.out.println("Peek Returned: " + stackObj.peek());
        stackObj.push(10);
        stackObj.push(20);
        stackObj.push(30);
        System.out.println("Pop deleted: " + stackObj.pop());
        stackObj.push(40);
        System.out.println("Peek Returned: " + stackObj.peek());
        
    }
}