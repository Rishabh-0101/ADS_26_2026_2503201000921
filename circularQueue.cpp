#include <iostream>
#define MAXSIZE 5
using namespace std;

int cq[MAXSIZE];
int front = -1,rear = -1;

void enqueue(int x){
    if(front == (rear+1)%MAXSIZE){
        cout<<"Cq is Full"<<endl;
    }else if(front == -1){
        front = rear = 0;
        cq[rear] = x;
    }else{
        rear = (rear+1) % MAXSIZE;
        cq[rear] = x;
    }
}

void dequeue(){
    if(front == -1){
        cout<<"Cq is Empty"<<endl;
    }else if(front == rear){
        front = rear = -1;
    }else{
        front = (front+1) % MAXSIZE;
    }
}

void peek(){
    if(front == -1){
        cout<<"Cq is Empty"<<endl;
    }else{
        cout<<"Peek value is : "<<cq[front]<<endl;
    }
}

void display(){
    if (front == -1){
        cout<<"Cq is Empty"<<endl;
    }else{
        for(int i = front; i != rear+1; i = (i+1) % MAXSIZE){
            cout<<cq[i]<<"-->";
        }
        cout<<cq[front];
    }
}

int main(){
    enqueue(10);
    dequeue();
    enqueue(20);
    enqueue(30);
    peek();
    dequeue();
    display();

    return 0;
}