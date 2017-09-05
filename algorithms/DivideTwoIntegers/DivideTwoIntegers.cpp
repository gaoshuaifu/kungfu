#include <iostream>
#include <cassert>
#include <cmath>
#include <climits>
using namespace std;

class Solution{
public:
    int divide(int dividend, int divisor){
        assert(divisor != 0);
        bool neg = (dividend > 0) ^ (divisor > 0);
        long long num = llabs((long long)dividend);
        long long div = llabs((long long)divisor);
        long long res = 0;

        int shift = 31;
        while(shift >= 0){
            if(div << shift <= num) {
                num -= div << shift;
                res += 1LL << shift;
            }
            shift--;
        }
        res = neg? -res : res;
        return min(result, static_cast<long long>(numeric_limits<int>::max()));
    }
};

int main(){
    Solution solution;
    cout << solution.divide(-2147483648, -2147483648) << endl;
    return 0;
}
