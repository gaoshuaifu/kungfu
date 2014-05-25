/*
 * time: O(n), space: O(1)
 */
#include <iostream>
#include <cstring>
#include <climits>
using namespace std;

class Solution{
public:
	int atoi(const char* str){
		int sign = 1;
		long long res = 0;
		
		const char* p = str;
		while(*p == ' ')
			p++;
		
		if(*p == '+' || *p == '-'){
    		if(*p == '-')
    			sign = -1;
    		p++;
    	}
		
		while(*p >= '0' && *p <= '9'){
			res = res * 10 + (*p - '0');
			p++;
		}
		
		res = sign * res;
		
		if(res < INT_MIN)
			return INT_MIN;
		else if(res > INT_MAX)
			return INT_MAX;
		else
			return  res;
	}
};
 
 int main(){
	char str[] = "  -0012a42";
	
	Solution solution;
	int res = solution.atoi(str);
	cout << res << endl;
	return 0;
}


