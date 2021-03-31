#include <iostream>
#include <queue>

using namespace std;

class Stack{
    queue<int> q1, q2;
    int size;
    public:
    Stack();
    void push(int);
    int pop();
    int top();
    int getCurrSize();

};

Stack::Stack(){
    size = 0;
}

/* Push using 2 queues */
void Stack::push(int val){
/*           Q1                                 
     _______________________
    |   |   |   |   |   |   |    
    | 1 | 2 | 3 | 4 | 5 | 6 |                     
    |___|___|___|___|___|___|

             Q2
     _______________________
    |   |   |   |   |   |   |    
    |val|   |   |   |   |   |                      
    |___|___|___|___|___|___|
*/

    size++;
    q2.push(val);

    while(!q1.empty()){
        q2.push(q1.front());
        q1.pop();
    }

    /* Swap q1 and q2, just the names */
    queue<int> temp = q1;
    q1 = q2;
    q2 = temp;
}

int Stack::pop(){
    int val;
    if(q1.empty())
        return -1;

    val = q1.front();
    q1.pop();
    size--;

    return val;
}

int Stack::top(){
    int val;
    if(q1.empty())
        return -1;

    val = q1.front();
    return val;
}

int Stack::getCurrSize(){
    return size;
}

/* Pop using 2 queues */

void Stack::push(int val){

    size++;
    q1.push(val);
}

int Stack::pop(){
    size--;
    int poppedNum = 0;
    int ret;
    while(size != poppedNum){
        poppedNum++;
        q2.push(q1.front());
        q1.pop();
    }
    ret = q1.front();
    q1.pop(); //Queue should ideally be empty at this point, needs to be verified

    queue<int> temp = q1;
    q1 = q2;
    q2 = temp;

    return ret;
}

int Stack::top(){
    size--;
    int poppedNum = 0;
    int ret;
    while(size != poppedNum){
        poppedNum++;
        q2.push(q1.front());
        q1.pop();
    }
    ret = q1.front();
    q2.push(ret);   //Important step, the final value should be pushed to queue number 2

    queue<int> temp = q1;
    q1 = q2;
    q2 = temp;

    return ret;
}

int main(){

    Stack stack;
    for(int i = 0; i < 10; i++){
        stack.push(i);
    }


    for(int i = 0; i < 10; i++){
        int j = stack.pop();
        cout << "Value popped is " << j << endl;
    }
    
   

    return 0;
}