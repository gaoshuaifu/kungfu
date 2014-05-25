/*
 * time: O(logn), space: O(1)
 */
#include <iostream>
#include <cassert>
using namespace std;

void print(unsigned int x){
	int n = 8 * sizeof(x);
	for(int i = n - 1; i >= 0; i--)
		cout << (x >> i & 1);
	cout << endl;
}

class Solution{
public: 
	int distance(unsigned int a, unsigned int b){
		unsigned int c = a ^ b;
		int count = 0;
		while(c){
			count++;
			c = c & (c - 1);
		}
		return count;
	}
};

int main(){
	unsigned int a = 9;
	print(a);
	unsigned int b = 19;
	print(b);
	
	Solution solution;
	int dist = solution.distance(a, b);
	cout << dist << endl;
	
	return 0;	
}
