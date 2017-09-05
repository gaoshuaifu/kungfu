/*
 * time: O(logn)
 */

#include <iostream>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) {
            return 1;
        }

        // -2147483648 == 2147483648 is true
        if (n < 0 && n != -n) {
            return 1.0 / myPow(x, -n);
        }
        double v = myPow(x, n / 2);
        return n % 2? v * v * x : v * v;
    }
};

int main(){
    double x = 1.0;
    int n = -2147483648;

    Solution solution;
    double res = solution.myPow(x, n);
    cout << res << endl;
    return 0;
}
