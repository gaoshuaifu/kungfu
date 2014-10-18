#include <iostream>
using namespace std;

class Solution{
public:
    int reverse(int x){
        int sign = x > 0? 1 : -1;
        x = abs(x);
        
        int res = 0;
        while(x > 0){
            res = res * 10 + x % 10;
            x /= 10;
        }
    
        return sign * res;
    }
};

int main(){
    int x = -123;
    Solution solution;
    int res = solution.reverse(x);
    cout << res << endl;
    return 0;
}

