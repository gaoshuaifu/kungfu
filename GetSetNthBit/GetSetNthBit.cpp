#include <iostream>
#include <cassert>
using namespace std;

class Solution{
public:
	unsigned int getPureBit(unsigned int x, int n){
		return (x >> n) & 1;
	}
	
	unsigned int getBit(unsigned int x, int n){
		return x & (1 << n);
	}
	
	unsigned int setBit(unsigned int x, int n){
		return x | (1 << n);
	}
	
	unsigned int clearBit(unsigned int x, int n){
		return x & ~(1 << n);
	}
	
	unsigned int toggleBit(unsigned int x, int n){
		return x ^ (1 << n);
	}

	unsigned int getGrayCode(unsigned int x){
		return x ^ (x >> 1);	
	}
	
	unsigned int clearLastOne(unsigned int x){
		return x & (x - 1);	
	}	
};

int main(){
	Solution solution;
	
	int n = 1;
	
	cout << solution.getPureBit(0, n) << "\n";
	cout << solution.getPureBit(2, n) << "\n";
	cout << "\n";
	
	cout << solution.getBit(0, n) << "\n";
	cout << solution.getBit(2, n) << "\n";
	cout << "\n";
	
	cout << solution.setBit(0, n) << "\n";
	cout << solution.setBit(2, n) << "\n";
	cout << "\n";
	
	cout << solution.clearBit(0, n) << "\n";
	cout << solution.clearBit(2, n) << "\n";
	cout << "\n";
	
	cout << solution.toggleBit(0, n) << "\n";
	cout << solution.toggleBit(2, n) << "\n";
	cout << "\n";
	
	cout << solution.getGrayCode(0) << "\n";
	cout << solution.getGrayCode(2) << "\n";
	cout << "\n";
	
	cout << solution.clearLastOne(0) << "\n";
	cout << solution.clearLastOne(2) << "\n";
	cout << "\n";
	
	return 0;	
}


