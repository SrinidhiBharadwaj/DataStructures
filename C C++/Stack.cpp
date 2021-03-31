#include <iostream>
using namespace std;
#define STACK_CAPACITY 10

class Stack{

    public:
    int top;
    int stack[STACK_CAPACITY];
    Stack();
    bool isFull();
    bool isEmpty();
    void push(int);
    int pop();

};

Stack::Stack(){
    //Initialize the top to point to the bottom of the stack
   top = 0;
}

/* Check if empty */
bool Stack::isFull(){
    if(top == STACK_CAPACITY)
        return true;
    return false;
}

/* Check if stack is empty */
bool Stack::isEmpty(){
    if(top == 0)
        return true;
    return false;
}

/* Check if full and add */
void Stack::push(int val){
    if(!isFull()){
        stack[top] = val;
        top++;
        cout <<"Added " << val << " to stack"<<endl;
        return;
    }
    cout << "Stack Overflow" <<endl;
}

/* Check if empty and pop */
int Stack::pop(){

    if(!isEmpty()){
        top--;
        cout<<"Returning " <<  stack[top] << " from stack" <<endl;
        return stack[top];
    }
    cout << "Stack Underflow" <<endl;
    return -1;
}


int main(){

    Stack stack;
    for(int i = 0; i < STACK_CAPACITY; i++){
        stack.push(i);
    }

    cout<< stack.isFull() << endl;

    for(int i = 0; i < STACK_CAPACITY; i++){
        int j = stack.pop();
    }
    
    cout<< stack.isEmpty() << endl;

    return 0;
}