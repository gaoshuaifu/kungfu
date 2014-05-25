#include <iostream>
#include <cassert>
#include <cmath>
#include <climits>
using namespace std;

class Solution{
public:
	int divide(int dividend, int divisor){
		assert(divisor != 0);
		bool neg = (dividend > 0) ^ (divisor > 0);
		long long num = abs((long long)dividend);
		long long div = abs((long long)divisor);
		long long res = 0;
		while(num >= div){
			int i = 0;
			while((div << (i + 1)) <= num)
				i++;
			num -= (div << i);
			res += (1 << i);
		}
		return neg? -res : res;
	}
};

int main(){
	Solution solution;
	cout << solution.divide(-2147483648, -2147483648) << endl;
	return 0;
}
