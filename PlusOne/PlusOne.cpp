/*
 * time: O(n), space: O(1)
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution{
public:
    vector<int> plusOne(vector<int>& digits){
        int n = digits.size();
        int i;
        for(i = n - 1; i >= 0; i--){
            if(digits[i] == 9)
                digits[i] = 0;
            else{
                digits[i]++;
                break;
            }
        }

        if(i < 0)
            digits.insert(digits.begin(), 1);

        return digits;
    }
};

class Solution{
public:
    vector<int> plusOne(vector<int>& digits){
        int n = digits.size();
        int digit;
        int carry = 1;
        for(int i = n - 1; i >= 0; i--){
            int sum = digits[i] + carry;
            digit = sum % 10;
            carry = sum / 10;
            digits[i] = digit;
            if(carry == 0)
                break;
        }
        if(carry > 0)
            digits.insert(digits.begin(), carry);

        return digits;
    }
};


int main(){
    int a[] = {9, 9};
    vector<int> digits = vector<int>(a, a + sizeof(a) / sizeof(a[0]));

    Solution solution;
    vector<int> res = solution.plusOne(digits);
    for(int i = 0; i < res.size(); i++)
        cout << res[i];
    cout << endl;
    return 0;
}

