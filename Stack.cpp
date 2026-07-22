// Online C++ compiler to run C++ program online
#include <iostream>
#define MAXSIZE 5
using namespace std;
int st[MAXSIZE];
int top = -1;
bool isOverflow(){//O(1)
    return top == MAXSIZE-1;
}
bool isUnderflow(){//O(1)
    return top == -1;
}
void push(int x){//O(1)
    if(isOverflow()){
        cout<<"Stack is Full"<<endl;
        return;
    }
    top++;
    st[top] = x;
}
void pop(){//O(1)
    if(isUnderflow()){
        cout<<"Stack is Empty"<<endl;
        return;
    }
    cout<<st[top]<<"is Popped"<<endl;
    top--;
}
void peek(){//O(1)
    if(isUnderflow()){
        cout<<"Stack is Empty"<<endl;
        return;
    }
    cout<<"Top Element is : "<<st[top]<<endl;
}
void traverse(){
    if(isUnderflow()){
        cout<<"Stack is Empty"<<endl;
        return;
    }
    for(int i = top; i>=0 ; i--){
        cout<<st[i]<<endl;
    }
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