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
	unsigned int overwrite(unsigned int x, int high, int low, unsigned int y){
		unsigned int mask = 0;
		mask |= (~0 << high);
		mask |= (1 << (low - 1)) - 1;
		
		x &= mask;
		
		x |= (y << (low - 1));
		
		return x;
	}
};

int main(){
	unsigned int x = (1 << 2) + (1 << 4) + (1 << 6) + (1 << 8) + (1 << 10);
	unsigned int y = 19;
	print(x);
	print(y);
	
	Solution solution;
	x = solution.overwrite(x, 5, 1, y);
	print(x);
	
	return 0;	
}
