class Stack {
  public:
  queue<int> q_;

  // Push element x onto stack.
  void push(int x) {  // O(n)
    q_.emplace(x);
    for (int i = 0; i < q_.size() - 1; ++i) {
        q_.emplace(q_.front());
        q_.pop();
    }
  }

  // Remove the element on top of the stack.
  void pop() {  // O(1)
    q_.pop();
  }

  // Get the top element.
  int top() {  // O(1)
    return q_.front();
  }

  // Return whether the stack is empty.
  bool empty() {  // O(1)
    return q_.empty();
  }
};
