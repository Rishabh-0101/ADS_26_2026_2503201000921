#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};

Node* front = NULL;
Node* rear = NULL;

void enqueue(int value){
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next  = NULL;
    if(front == rear){
        front = rear = newNode;
    }
    else{
        rear->next = newNode;
        rear = newNode;
    }
}

void dequeue(){
    if(front == NULL){
        cout<<"Queue is Empty"<<endl;
        return;
    }
    else if(front == rear){
        Node* temp = front;
        front = rear = NULL;
        delete temp;
    }
    else{
        Node* temp = front;
        temp = temp->next;
        delete temp;
    }
}

void peek(){
    if(front == NULL){
        cout<<"Queue is Empty"<<endl;
        return;
    }
    cout<<"Front Element is : "<<front->data<<endl;
}

void display(){
    if(front == NULL){
        cout<<"Queue is Empty"<<endl;
        return;
    }
    Node* temp = front;
    while(temp != NULL){
        cout<<temp->data<<"-->";
        temp = temp->next;
    }
    cout<<"NULL";
}

int main(){
    enqueue(10);
    dequeue();
    dequeue();
    enqueue(30);
    peek();
    enqueue(10);
    enqueue(40);
    display();
    return 0;
}