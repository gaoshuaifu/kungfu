#include <iostream>
#include <map>
using namespace std;


class Solution{
public:
	string longestSubstr(string s){
		int n = s.size();
		string res;
		map<char, int> mapping;
		
		int start = 0;
		int end = 0;
		while(end < n){
			if(mapping.size() < 2 || mapping.count(s[end])){
				mapping[s[end]]++;
				end++;
				continue;
			}
			
			if(end - start > res.size())
				res = s.substr(start, end - start);
			
			while(mapping.size() == 2){
				mapping[s[start]]--;
				if(mapping[s[start]] == 0)
					mapping.erase(s[start]);
				start++;
			}
		}
		if(end - start > res.size())
			res = s.substr(start, end - start);
		
		return res;
	}
};


int main(){
	Solution solution;
	string s = "abababababcccddd";
	string res = solution.longestSubstr(s);
	cout << res << endl;
	return 0;	
}