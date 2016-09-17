#include <iostream>
#include <vector>
#include <stack>
using namespace std;

template <class T>
class SetOfStacks{
private:
  int capacity;
  vector<stack<T> > stks;

public:
  SetOfStacks(int cap){
    capacity = cap;
  }

  void push(T val){
    if(stks.empty() || stks.back().size() == capacity)
      stks.push_back(stack<T>());
    stks.back().push(val);
  }

  void pop(){
    stks.back().pop();
    if(stks.back().empty())
      stks.pop_back();
  }

  T top(){
    return stks.back().top();
  }

  bool empty(){
    return stks.empty();
  }

  int size(){
    if(stks.empty())
      return 0;
    else
      return capacity * (stks.size() - 1) + stks.back().size();
  }

  int numStacks(){
    return stks.size();
  }
};

int main(){
  SetOfStacks<int> sos(3);
  for(int i = 1; i <= 10; i++){
    sos.push(i);
    cout << sos.top() << "\t" << sos.size() << "\t" << sos.numStacks() << "\n";
  }

  cout << "\n";

  while(!sos.empty()){
    cout << sos.top() << "\t" << sos.size() << "\t" << sos.numStacks() << "\n";
    sos.pop();
  }

  return 0;
}
