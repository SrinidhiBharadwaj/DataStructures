#include <iostream>
#include <unordered_set>
using namespace std;

class LinkedList{
    public:
    int val;
    LinkedList* nextNode;
};

void AddHead(LinkedList** refToHead, int val){
    LinkedList* temp = new LinkedList;
    temp->val = val;
    temp->nextNode = (*refToHead);

    //Don't forget to move the pointer to head coz I legit forgot
    (*refToHead) = temp; 
}

void AddAtTheEnd(LinkedList** head, int val){

    LinkedList* newNode = new LinkedList;
    LinkedList* tempNode = (*head);
    newNode->val = val;
    newNode->nextNode = NULL;

    if(*head == NULL){
        *head = newNode;
        return;
    }

    /* Loop until the end of the list */
    while(tempNode->nextNode != NULL){
        tempNode = tempNode->nextNode;
    }
    tempNode->nextNode = newNode;
}

void AddAfterANode(LinkedList* node, int val){
    LinkedList* newNode = new LinkedList;
    newNode->val = val;

    if(node == NULL){
        cout << "Invalid position" << endl;
        return;
    }

    /* Decouple and link again */
    newNode->val = val;
    newNode->nextNode = node->nextNode;
    node->nextNode = newNode;
}

void DeleteANode(LinkedList** head, int key){

    LinkedList* tempNode = *head;
    LinkedList* prevNode = *head;
    if(*head == NULL){
        cout << "LinkedList does not exist" << endl;
        return;
    }
    if(tempNode->val == key){
        (*head) = tempNode->nextNode;
        cout << "Node successfully deleted" << endl;
        delete tempNode;
        return;
    }

    while(tempNode != NULL){
       if(tempNode->val == key){
           prevNode->nextNode = tempNode->nextNode;
            delete tempNode;
            cout << "Node successfully deleted" << endl;
            return;
       }
       else{
           prevNode = tempNode;
           tempNode = tempNode->nextNode;
       }
    }

    cout << "Node does not exist in the given list" << endl;
}

void ReverseTheList(LinkedList** head){
    if(*head == NULL){
        cout << "LinkedList does not exist" << endl;
        return;
    }

    LinkedList* prevNode = NULL;
    LinkedList* currNode = (*head);
    LinkedList* nextNode = NULL; //Temporary node for iteration

    while(currNode != NULL){
        nextNode = currNode->nextNode;
        currNode->nextNode = prevNode;
        prevNode = currNode;
        currNode = nextNode;
    }
    (*head) = prevNode; //Assign the head pointer to the last node of the network
}

void PrintLinkedList(LinkedList* node) {

	while (node != NULL) {
		cout << node->val << "-->";
		node = node->nextNode;
	}
	cout << endl;
}
int main(){

    LinkedList* head = NULL;
    /* Test vectors */
	AddAtTheEnd(&head, 6);
	AddHead(&head, 7);
	AddHead(&head, 1);
	AddAtTheEnd(&head, 4);
	AddAfterANode(head->nextNode, 8);
	DeleteANode(&head, 1);
    
    PrintLinkedList(head);

    return 0;
}