/*
 * time: O(n), space: O(1)
 */
#include <iostream>
#include <cstring>
#include <climits>
using namespace std;

class Solution{
public:
    float atof(const char* str){
        int sign = 1;
        int integer = 0;
        float decimal = 0.0;
        
        const char* p = str;

        while(*p == ' ')
            p++;
        
        if(*p == '+' || *p == '-'){
            if(*p == '-')
                sign = -1;
            p++;
        }
        
        while(*p >= '0' && *p <= '9'){
            integer *= 10;
            integer += *p - '0';
            p++;
        }
        
        if(*p == '.'){
            p++;
            float base = 0.1;
            while(*p >= '0' && *p <= '9'){
                decimal += base * (*p - '0');
                base *= 0.1;
                p++;
            }
        }
        
        return sign * (integer + decimal);
    }
};
 
int main(){
    Solution solution;
    cout << " +123." << " => " << solution.atof("+123.") << "\n";
    cout << " -123." << " => " << solution.atof("-123.") << "\n";
    cout << " 123." << " => " << solution.atof("123.") << "\n";
    cout << "+123.456" << " => " << solution.atof("+123.456") << "\n";
    cout << "-123.456" << " => " << solution.atof("-123.456") << "\n";
    cout << "123.456" << " => " << solution.atof("123.456") << "\n";
    cout << "1.0" << " => " << solution.atof("1.0") << "\n";
    cout << "1.1" << " => " << solution.atof("1.1") << "\n";
    cout << "1" << " => " << solution.atof("1") << "\n";
    cout << "-1" << " => " << solution.atof("-1") << "\n";
    return 0;
}

