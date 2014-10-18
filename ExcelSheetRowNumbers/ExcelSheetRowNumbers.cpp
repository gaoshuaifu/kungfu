#include <iostream>
#include <algorithm>
using namespace std;

class Solution{
public:
    string excelRowNumber(int n){
        string res = "";
        res.push_back('a' + n % 26);
        n = n / 26;
        while(n){
            res.push_back('a' + (n - 1) % 26);
            n = (n - 1) / 26;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main(){
    Solution solution;
    int n = 25;
    cout << n << ": " << solution.excelRowNumber(n) << "\n";
    return 0;
}

