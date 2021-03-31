#include <iostream>
#include <queue>


/* Refer to https://www.youtube.com/watch?v=zuuAPYiMYDA for theoretical understanding */ 
using namespace std;

struct Node{
    int key;
    Node* left;
    Node* right;
};

Node* createNode(int key){

    Node* node = new Node();

    node->key = key;
    node->left = NULL;
    node->right = NULL;

    return node;
}

/* Level order traversal - Breadth First Traversal */
Node* search(Node* root, int key){

    Node* out = NULL;

    if(root == NULL){
        return NULL;
    }
    queue<Node *> q;
    q.push(root);
    
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp->key == key) out = temp;
        if(temp->left!=NULL) q.push(temp->left);
        if(temp->right!=NULL) q.push(temp->right);
    }
    return out;
}


/* Finding the first empty spot - BFT or Lever order traversal */
void insert(Node** root, int key){
    Node *rootNode = (*root);
    //assuming that the tree is not empty
    Node* nodeToInsert = createNode(key);

    if(root == NULL) {
        rootNode = nodeToInsert;
        return;
    }
    queue<Node*> q;
    q.push(rootNode);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp->left == NULL){
            temp->left = nodeToInsert;
            return;
        }
        else{
            q.push(temp->left);
        }

        if(temp->right == NULL){
            temp->right = nodeToInsert;
            return;
        }
        else{
            q.push(temp->right);
        }
    }

}

int main(){
    
    Node* root = createNode(1);

    cout<< root->key<<endl;
    root->left = createNode(2);
    root->left->left = createNode(4);

    root->right = createNode(3);
    root->right->left = createNode(5);


    return 0;
}