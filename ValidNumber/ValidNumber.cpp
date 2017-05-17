/*
 * time: O(n), space: O(1)
 */
#include <iostream>
using namespace std;

class Solution{
public:
    bool isNumber(const char* s){
        bool hasInteger = false;
        bool hasDecimal = false;

        const char* p = s;

        while(*p == ' ')
            p++;

        if(*p == '+' || *p == '-')
            p++;

        if(*p >= '0' && *p <= '9')
            hasInteger = true;

        while(*p >= '0' && *p <= '9')
            p++;

        if(*p == '.'){
            p++;

            if(*p >= '0' && *p <= '9')
                hasDecimal = true;

            while(*p >= '0' && *p <= '9')
                p++;
        }

        if(*p == 'e'){
            p++;

            if(*p == '+' || *p == '-')
                p++;

            if(*p < '0' || *p > '9')
                return false;

            while(*p >= '0' && *p <= '9')
                p++;
        }

        while(*p == ' ')
            p++;

        return *p == '\0' && (hasInteger || hasDecimal);
    }
};


int main(){
    const char* array[] = {"0", "    0.1    ", "abc", "1 a", "2e10"};
    Solution solution;
    for(int i = 0; i < 5; i++)
        cout << array[i] << " => " << solution.isNumber(array[i]) << "\n";

    return 0;
}
