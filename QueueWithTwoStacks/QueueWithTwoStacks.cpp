#include <iostream>
#include <stack>
using namespace std;

template <class T>
class QueueWithTwoStacks{
private:
    stack<T> inStk;
    stack<T> outStk;

    void moveFromInToOut(){
        while(!inStk.empty()){
            T val = inStk.top();
            inStk.pop();
            outStk.push(val);
        }
    }

public:
    void push(T val){
        inStk.push(val);    
    }
    
    void pop(){
        if(outStk.empty())
            moveFromInToOut();
        outStk.pop();
    }
    
    T front(){
        if(outStk.empty())
            moveFromInToOut();
        return outStk.top();
    }
    
    bool empty(){
        return inStk.empty() && outStk.empty();
    }
    
    int size(){
        return inStk.size() + outStk.size();
    }
};

int main(){
    QueueWithTwoStacks<int> q;
    
    for(int i = 1; i <= 10; i++){
        q.push(i);
        cout << q.front() << " " << q.size() << "\n";
    }
    cout << "\n";
    while(!q.empty()){
        cout << q.front() << " " << q.size() << "\n";
        q.pop();
    }
    
    return 0;
}