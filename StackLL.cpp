#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* top = NULL;
void push(int x){
    Node* temp = new Node;
    temp->data = x;
    temp->next  = top;
    top = temp;
}

void pop(){
    if(top == NULL){
        cout<<"Stack is Empty"<<endl;
        return;
    }
    Node* temp = top;
    top = top->next;
    delete temp;
}

void peek(){
    if(top == NULL){
        cout<<"Stack is Empty"<<endl;
        return;
    }
    cout<<"Top Element is : "<<top->data<<endl;
}

void traverse(){
    if(top == NULL){
        cout<<"Stack is Empty"<<endl;
        return;
    }
    Node* temp = top;
    while(temp != NULL){
        cout<<temp->data<<"-->";
        temp = temp->next;
    }
    cout<<"NULL";
}

int main(){
    push(10);
    push(20);
    pop();
    push(30);
    peek();
    traverse();

    return 0;
}