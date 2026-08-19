#include <iostream>
#include <deque>
using namespace std;

int main(){
    deque<int> dq;
    dq.push_back(10);
    dq.push_back(20);
    dq.push_front(5);
    cout<<"Front Element : "<<dq.front()<<endl;
    cout<<"Back Element : "<<dq.back()<<endl;
    dq.pop_front();
    dq.pop_back();
    cout<<"Remaining Element : ";
    for(int x : dq){
        cout<<x<<" ";
    }
    return 0;
}

