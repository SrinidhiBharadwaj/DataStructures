#include <iostream>

using namespace std;

#define CAPACITY 10

class Queue{
    public:
    int front;
    int back;
    int currentSize;
    int queue[CAPACITY];
    Queue();
    bool isFull();
    bool isEmpty();
    void Enqueue(int);
    int Dequeue();
    void printQueue(); //For better understanding
};
Queue::Queue(){
    currentSize = 0;
    back = 0;
    front = 0;
}

bool Queue::isFull(){
    if(currentSize == CAPACITY )
        return true;
    return false;
}

bool Queue::isEmpty(){
    if(currentSize == 0)
        return true;
    return false;
}

void Queue::Enqueue(int val){
    if(!isFull()){
        queue[back] = val;
        back = (back + 1) % CAPACITY;
        currentSize++;
        cout << "Adding " << val << " to the queue" << endl;
        return;
    }
     cout << "Queue is full" << endl;
}

int Queue::Dequeue(){
    if(!isEmpty()){
        int val = queue[front];
        cout << "Value " << val << " is dequeued" << endl;
        front = (front + 1) % CAPACITY;
        currentSize--;
        return val;
    }

    cout << "Queue is empty" << endl;
    return -1;
}

/* Could be optimized, have to revisit */
void Queue::printQueue(){
    if(!isEmpty()){

        int i = front;
        /* Optimized code */
        do{
            cout << queue[i] << "-->" ; 
            i = (i + 1) % CAPACITY;

        }while (i != back);

        /* Non optimized */
        // if(front < back){
        //     for(int i = front; i< back; i++)
        //        cout << queue[i] << "-->" ; 
        // }
        // else{
        //     for(int i = front; i < CAPACITY; i++)
        //         cout << queue[i] << "-->" ;
        //     for(int i = 0; i < back; i++)
        //         cout << queue[i] << "-->" ;      
        // }
        cout<< endl;
    }
    else{
        cout<<"Queue is empty"<<endl;
    }
    
}

int main(){

    Queue line;
    for(int i = 0; i < 10; i++)
        line.Enqueue(i);
  
    line.Dequeue();
    line.Enqueue(10);
    line.printQueue();
    return 0;
}