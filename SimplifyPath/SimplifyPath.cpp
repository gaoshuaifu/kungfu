/*
 * time: O(n), space: O(n)
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution{
public:
	string simplifyPath(string path){
		int n = path.size();
		vector<string> dirs;
		
		int start = 0;
		int end;
		while(start < n){
			if(path[start] == '/'){
				start++;
				continue;
			}
			
			end = start;
			while(end < n && path[end] != '/')
				end++;
				
			string dir = path.substr(start, end - start);
			if(dir == ".."){
				if(!dirs.empty())
					dirs.pop_back();
			}
			else if(dir != ".")
				dirs.push_back(dir);
				
			start = end;
		}
		
		if(dirs.empty())
			return "/";

		string res = "";
		for(int start = 0; start < dirs.size(); start++){
			res += "/";
			res += dirs[start];
		}
		
		return res;
	}
};

int main(){
	string path = "/./home///ywang/../ywang/.profile/programming";
	Solution solution;
	string res = solution.simplifyPath(path);
	cout << res << endl;
	return 0;
}

