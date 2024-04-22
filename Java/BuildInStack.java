import java.util.Stack;

class BuildInStack {
    public static void main (String[] args) {
        System.out.println("Build in Stack class in java");
        
        Stack<String> myStack = new Stack();
        
        myStack.push("Bangladesh");
        myStack.push("Dhaka");
        
        System.out.println("Pop deleted: " + myStack.pop());
                
        System.out.println("Peek: " + myStack.peek());
        
        System.out.println("Stack size: " + myStack.size());
        
    }
}