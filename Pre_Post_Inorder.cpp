#include <iostream>
using namespace std;
// 1. Structure for a Tree Node

struct Node 
{
    char data;
    Node *left;
    Node *right;
};

// 2. Function to create the Binary Tree
Node* create() 
{
    char x;
    cout << "Enter data (Enter '#' for no node): ";
    cin >> x;
    
    // If user enters '#', it means no node (NULL)
    if (x == '#') {
        return NULL;
    }
        
    Node *newNode = new Node();
    newNode->data = x;
        
    cout << "--> For Left Child of " << x << ": ";
    newNode->left = create();
    
    cout << "--> For Right Child of " << x << ": ";
    newNode->right = create();
    
    return newNode;
}

// 3. Preorder Traversal (Root -> Left -> Right)
void preorder(Node* root) 
{
    if (root != NULL) 
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

// 4. Inorder Traversal (Left -> Root -> Right)
void inorder(Node* root) 
{
    if (root != NULL) 
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

// 5. Postorder Traversal (Left -> Right -> Root)
void postorder(Node* root) 
{
    if (root != NULL) 
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

// 6. Count Leaf Node (Left -> Right)
int leafcount(Node* p){
    if(p == NULL){
        return 0;
    }
    if(p->left == NULL && p->right == NULL){
        return 1;
    }else{
        return leafcount(p->left) + leafcount(p->right);
    }
}

// 7. Count Internal Node (Left -> Right)
int InternalNode(Node* p){
    if(p == NULL){
        return 0;
    }
    if(p->left == NULL && p->right == NULL){
        return 0;
    }else{
        return 1 + InternalNode(p->left) + InternalNode(p->right);
    }
}

// 8. Count Total Node (Left -> Right)
int TotalNode(Node* p){
    if(p == NULL){
        return 0;
    }
    return 1 + TotalNode(p->left) + TotalNode(p->right);
}


int main() 
{
    cout << "=== Binary Tree Creation ===" << endl;
    Node *root = create();
    
    cout << "\n=== Preorder Traversal ===" << endl;
    preorder(root);
    cout << endl;
    
    cout << "\n=== Inorder Traversal ===" << endl;
    inorder(root);
    cout << endl;
    
    cout << "\n=== Postorder Traversal ===" << endl;
    postorder(root);
    cout << endl;

    cout << "\n=== Leaf Node Count ===" << endl;
    cout << "Total Leaf Nodes: " << leafcount(root) << endl;

    
    cout << "\n=== Internal Node Count ===" << endl;
    cout << "Total Internal Nodes: " << InternalNode(root) << endl;

    cout << "\n=== Total Node Count ===" << endl;
    cout << "Total Nodes: " << TotalNode(root) << endl;


    return 0;
}