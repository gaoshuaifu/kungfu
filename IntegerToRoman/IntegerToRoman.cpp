/*
 * time: O(1), space: O(1)
 */
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string digitToRoman(int digit, char ten, char five, char one){
		string res;
		
		if(digit == 9){
			res.append(1, one);
			res.append(1, ten);
		}
		else if(digit >= 5){
			res.append(1, five);	
			res.append(digit - 5, one);
		}
		else if(digit == 4){
			res.append(1, one);
			res.append(1, five);
		}
		else
			res.append(digit, one);
		
		return res;
	}
	
    string intToRoman(int num) {
    	string res;
		res += digitToRoman(num / 1000 % 10, '\0', '\0', 'M');
		res += digitToRoman(num / 100 % 10, 'M', 'D', 'C');
		res += digitToRoman(num / 10 % 10, 'C', 'L', 'X');
		res += digitToRoman(num / 1 % 10, 'X', 'V', 'I');
    	return res;
    }
};

int main(){
	int num = 3999;
	
	Solution solution;
	cout << solution.intToRoman(num) << endl;
	
	return 0;
}

