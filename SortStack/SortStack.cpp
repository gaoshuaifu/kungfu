#include <iostream>
#include <stack>
using namespace std;

class Solution{
public:
    void sortStack(stack<int>& stk){
        stack<int> buff;
        while(!stk.empty()){
            int tmp = stk.top();
            stk.pop();
            
            while(!buff.empty() && tmp > buff.top()){
                stk.push(buff.top());
                buff.pop(); 
            }
            
            buff.push(tmp);
        }
        
        while(!buff.empty()){
            stk.push(buff.top());
            buff.pop();
        }
    }
};

int main(){
    stack<int> stk;
    stk.push(5);
    stk.push(3);
    stk.push(1);
    stk.push(2);
    stk.push(4);
    
    Solution solution;
    solution.sortStack(stk);
    
    while(!stk.empty()){
        cout << stk.top() << "\n";
        stk.pop();
    }
    
    return 0;   
}