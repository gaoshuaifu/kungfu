#include <iostream>
#include <stack>
using namespace std;

class MinStack{
private:
  stack<int> stk;
  stack<int> minStk;

public:
  void push(int val){
    if(minStk.empty() || val <= minStk.top())
      minStk.push(val);
    stk.push(val);
  }

  void pop(){
    if(stk.empty()) return;
    if(stk.top() == minStk.top())
      minStk.pop();
    stk.pop();
  }

  bool empty(){
    return stk.empty();
  }

  int top(){
    return stk.top();
  }

  int min(){
    return minStk.top();
  }
};

int main(){
  MinStack stk;
  stk.push(10);
  cout << "top: " << stk.top() << ", min: " << stk.min() << "\n";

  stk.push(8);
  cout << "top: " << stk.top() << ", min: " << stk.min() << "\n";

  stk.push(9);
  cout << "top: " << stk.top() << ", min: " << stk.min() << "\n";

  stk.pop();
  cout << "top: " << stk.top() << ", min: " << stk.min() << "\n";

  stk.pop();
  cout << "top: " << stk.top() << ", min: " << stk.min() << "\n";

  return 0;
}

