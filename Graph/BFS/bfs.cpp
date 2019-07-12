#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
    Node(int value){
        this->data = value;
        this->left = nullptr;
        this->right = nullptr;
    }
};

void printLevelOrder(Node* root){
    if(!root)
        return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty())
    {
        Node* node = q.front();
        cout << node->data << " ";
        q.pop();
        if(node->left)
            q.push(node->left);
        if(node->right)
            q.push(node->right);
    }
    
}

int main(){

    Node *root = new Node(1); 
    root->left = new Node(2); 
    root->right = new Node(3); 
    root->left->left = new Node(4); 
    root->left->right = new Node(5); 
  
    cout << "Level Order traversal of binary tree is \n"; 
    printLevelOrder(root); 
    return 0; 
}
