class Queue {
private:
  stack<int> stk_front;
  stack<int> stk_back;

  void back_to_front() {
    while(!stk_back.empty()) {
      stk_front.push(stk_back.top());
      stk_back.pop();
    }
  }

public:
  // Push element x to the back of queue.
  void push(int x) {
    stk_back.push(x);
  }

  // Removes the element from in front of queue.
  void pop(void) {
    if(stk_front.empty()) {
      back_to_front();
    }
    stk_front.pop();
  }

  // Get the front element.
  int peek(void) {
    if(stk_front.empty()) {
      back_to_front();
    }
    return stk_front.top();
  }

  // Return whether the queue is empty.
  bool empty(void) {
    return stk_front.empty() && stk_back.empty();
  }
};
