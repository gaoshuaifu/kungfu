#include <iostream>
using namespace std;

class Solution{
public:
	bool isMatch(const char* s, const char* p){
		if(*p == '\0')
			return (*s == '\0');

		if(*p != '*')
			return ((*s == *p) || (*s != '\0' && *p == '?')) && isMatch(s + 1, p + 1);
		
		while(*s != '\0'){
			if(isMatch(s, p + 1))
				return true;
			s++;
		}
		return isMatch(s, p + 1);
	}
};

int main(){
	Solution solution;
	cout << solution.isMatch("aa", "*") << endl;
	return 0;
}

