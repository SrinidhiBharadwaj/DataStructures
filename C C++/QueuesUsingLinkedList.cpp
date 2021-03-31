#include <iostream>
using namespace std;

class LinkedList{
    public:
    int val;
    LinkedList* nextNode;
    LinkedList(int x){
        val = x;
        nextNode = NULL;
    }
};

class Queue{

    public:
    LinkedList *front, *back;
    Queue();
    void Enqueue(int val);
    void Dequeue();
};

Queue::Queue(){
    front = back = NULL;
}

void Queue::Enqueue(int val){

    LinkedList* node = new LinkedList(val);
    if(back == NULL){
        front = back = node;
        return;
    }
    back->nextNode = node; //Link the previous one to the new one
    back = node; //Set the new node as back
}

void Queue::Dequeue(){

    if(front == NULL)
        return;

    LinkedList* tempNode = front;
    front = front->nextNode;

    if(front == NULL) back = NULL;
    
    delete(tempNode);
}

int main()
{
  
    Queue q;
    q.Enqueue(10);
    q.Enqueue(20);
    q.Dequeue();
    q.Dequeue();
    q.Enqueue(30);
    q.Enqueue(40);
    q.Enqueue(50);
    q.Dequeue();
    cout << "Queue Front : " << (q.front)->val << endl;
    cout << "Queue Rear : " << (q.back)->val;
}