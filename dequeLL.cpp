#include <iostream>
#include <deque>
using namespace std;

struct Node{
    int info;
    Node* prev;
    Node* next;
};
Node* front = NULL;
Node* rear = NULL;
void insertfront(int x){
    Node* newNode = new Node;
    newNode->info = x;
    if(front == NULL){
        newNode->prev = newNode->next = NULL;
        front = rear = newNode;
    }else{
        newNode->prev = NULL;
        newNode->next = front;
        front->prev = newNode;
        front = newNode;
    }
}

void insertrear(int x){
    Node* newNode = new Node;
    newNode->info = x;
    if(front == NULL){
        newNode->prev = newNode->next = NULL;
        front = rear = newNode;
    }else{
        newNode->prev = rear;
        newNode->next = NULL;
        rear->next = newNode;
        rear = newNode;
    }
}

void deletefront(){
    Node* temp = front;
    if(front == NULL){
        cout<<"deque is empty"<<endl;
    }else if(front == rear){
        front = rear = NULL;
        delete temp;
    }else{
        front = front->next;
        front->prev = NULL;
        delete temp;
    }
}

void deleterear(){
    Node* temp = rear;
    if(front == NULL){
        cout<<"deque is empty"<<endl;
    }else if(front == rear){
        front = rear = NULL;
        delete temp;
    }else{
        rear = rear->prev;
        rear->next = NULL;
        delete temp;
    }
}

void peek(){
    if(front == NULL){
        cout<<"deque is empty"<<endl;
    }else{
        cout<<"Peek element is : "<<front->info<<endl;
    }
}

void display(){
    Node* temp = front;
    if(front == NULL){
        cout<<"deque is empty"<<endl;
    }else{
        cout<<"Remaining Element : ";
        while(temp != NULL){
            cout<<temp->info<<"->";
            temp = temp->next;
        }
    }
    cout<<"NULL";
}

int main(){
    insertfront(5);
    insertfront(10);
    peek();
    display();

    return 0;
}
