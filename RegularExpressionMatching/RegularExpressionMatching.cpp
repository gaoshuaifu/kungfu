#include <iostream>
using namespace std;

class Solution{
public:
    bool isMatch(const char* s, const char* p){
        if(*p == '\0')
            return (*s == '\0');
        
        if(*(p + 1) != '*')
            return (*s == *p || (*s != '\0' && *p == '.')) && isMatch(s + 1, p + 1);

        while(*s == *p || (*s != '\0' && *p == '.')){
            if(isMatch(s, p + 2))
                return true;
            s++;
        }
        return isMatch(s, p + 2);
    }
};


int main(){
    Solution solution;
    cout << solution.isMatch("aa", "a") << endl;
    cout << solution.isMatch("aa", "aa") << endl;
    cout << solution.isMatch("aaa", "aa") << endl;
    cout << solution.isMatch("aa", "a*") << endl;
    cout << solution.isMatch("aa", ".*") << endl;
    cout << solution.isMatch("ab", ".*") << endl;
    cout << solution.isMatch("aab", "c*a*b") << endl;
    return 0;
}

