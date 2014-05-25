#include <iostream>
#include <cstring>
#include <set>
using namespace std;

class Solution{
public:
	bool isMatch(char* str, char* pattern){
		char* p = str;
		char* q = pattern;
		while(*p != '\0' && *q != '\0'){
			if(*p != *q)
				return false;
			p++;
			q++;
		}
		return *q == '\0';
	}
	
	void replace(char* str, char* pattern){
		int m = strlen(str);
		int n = strlen(pattern);
		if(m < n) return;
		
		set<int> matchIndex;
		int i = 0; 
		while(i < m){
			if(isMatch(str + i, pattern)){	
				matchIndex.insert(i);
				i +=  n;
			}
			else
				i++;
		}
		
		if(matchIndex.size() == 0) return;
		
		i = 0;
		int j = 0;
		while(i < m){
			if(matchIndex.find(i) == matchIndex.end())
				str[j++] = str[i++];
			else{
				if(matchIndex.find(i - n) == matchIndex.end())
					str[j++] = 'X';
				i += n;
			}
		}
		str[j] = '\0';
	}
};

int main(){
	Solution solution;
	char str[] = "abbaabbauvwabbabbauvwabba";
	char pattern[] = "abba";
	solution.replace(str, pattern);
	cout << str << endl;
	return 0;	
}

