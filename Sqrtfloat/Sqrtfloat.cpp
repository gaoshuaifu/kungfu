#include <iostream>
#include <cassert>
#include <cmath>
using namespace std;

class Solution{
public:
	float sqrt(float x){
		assert(x >= 0);
		
		float lastGuess;
		float currGuess = x;
		
		do{
			lastGuess = currGuess;
			currGuess = (currGuess + x / currGuess) / 2.0;
		}while(abs(lastGuess - currGuess) > 0.000001);
		
		return currGuess;
	}
};

class Solution1{
public:	
	float sqrt(float x){
		assert(x >= 0);
		
		float low;
		float high;
		float mid;
		
		if(x == 1.0)
			return 1.0;
		if(x > 1.0){
			low = 1.0;
			high = x;
		}
		else if(x < 1.0){
			low = x;
			high = 1.0;
		}
		
		while(abs(high - low) > 0.000001){
			mid = (low + high) / 2.0;	
			if(x < mid * mid)
				high = mid;
			else if(x > mid * mid)
				low = mid;
		}
		
		return mid;
	}
};

int main(){
	Solution solution;
	cout << solution.sqrt(1.21) << endl;	
	cout << solution.sqrt(0.64) << endl;	
	
	Solution1 solution1;
	cout << solution1.sqrt(1.21) << endl;	
	cout << solution1.sqrt(0.64) << endl;	
	return 0;	
}