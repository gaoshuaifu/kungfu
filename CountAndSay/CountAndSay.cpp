#include <iostream>
#include <string>
using namespace std;

class Solution{
public:
	string nextStr(string str){
		int n = str.size();
		string res = "";
		char curr = str[0];
		int count = 1;
		for(int i = 1; i < n; i++){
			if(str[i] == curr)
				count++;
			else{
				res.push_back(count + '0');
				res.push_back(curr);
				curr = str[i];
				count = 1;
			}
		}					
		res.push_back(count + '0');
		res.push_back(curr);
		return res;
	}

	string countAndSay(int n){
		string str = "1";
		for(int i = 0 ; i < n - 1; i++)
			str = nextStr(str);
		return str;
	}
};

int main(){
	Solution solution;
	cout << solution.countAndSay(5) << endl;
	return 0;
}
