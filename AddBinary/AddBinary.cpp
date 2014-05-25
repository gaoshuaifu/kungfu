/*
 * time: O(m + n), space: O(max(m + n))
 */
#include <iostream>
#include <string>
using namespace std;

class Solution{
public:
	string addBinary(string a, string b){	
		string res = "";
		int digit;
		int carry = 0;
		int i = a.size() - 1;
		int j = b.size() - 1;		
		while(i >= 0 || j >= 0){
			int sum = 0;
			if(i >= 0){
				sum += a[i] - '0'; 
				i--;
			}
			if(j >= 0){
				sum += b[j] - '0';
				j--;
			}
			sum += carry;
			digit = sum % 2;
			carry = sum / 2;
			res.insert(res.begin(), digit + '0');
		}
		if(carry == 1)
			res.insert(res.begin(), '1');	
		return res;
	}
};

int main(){
	string a = "11";
	string b = "11";
	
	Solution solution;
	string res = solution.addBinary(a, b);
	
	cout << res << endl;
	return 0;
}

