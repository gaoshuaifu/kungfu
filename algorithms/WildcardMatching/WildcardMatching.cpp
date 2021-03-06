#include <iostream>
using namespace std;

class Solution{
public:
    bool matchChar(const char* s, const char* p) {
        return *s == *p || (*s && *p == '?');
    }

    bool isMatch(const char* s, const char* p){
        if(*p == '\0')
            return (*s == '\0');

        if(*p != '*')
            return matchChar(s, p) && isMatch(s + 1, p + 1);
        else
            return isMatch(s, p + 1) || (*s != '\0' && isMatch(s + 1, p));
    }
};

class Solution1{
public:
    bool matchChar(const char* s, const char* p) {
        return *s == *p || (*s && *p == '?');
    }

    bool isMatch(const char* s, const char* p){
        if(*p == '\0')
            return (*s == '\0');

        if(*p != '*')
            return matchChar(s, p) && isMatch(s + 1, p + 1);

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
    cout << solution.isMatch("ab", "*a") << endl;
    return 0;
}
