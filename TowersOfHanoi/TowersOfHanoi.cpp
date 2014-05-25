#include <iostream>
#include <stack>
using namespace std;

class Solution{
public:
	void moveHelper(int n, stack<int>& src, stack<int>& buff, stack<int>& dest){
		if(n == 0)
			return;
		
		moveHelper(n - 1, src, dest, buff);
		dest.push(src.top());
		src.pop();
		moveHelper(n - 1, buff, src, dest);
	}
	
	void move(stack<int>& src, stack<int>& buff, stack<int>& dest){
		int n = src.size();
		moveHelper(n, src, buff, dest);
	}
};

int main(){
	stack<int> src;
	stack<int> buff;
	stack<int> dest;
	
	for(int i = 10; i >= 1; i--)
		src.push(i);
	
	Solution solution;
	solution.move(src, buff, dest);
	
	while(!dest.empty()){
		cout << dest.top() << "\n";
		dest.pop();
	}
	
	return 0;
}