/*
 * time: O(logn), space: O(1)
 */
#include <iostream>
#include <cassert>
using namespace std;

void print(unsigned int x){
    int n = 8 * sizeof(x);
    for(int i = n - 1; i >= 0; i--)
        cout << (x >> i & 1);
    cout << endl;
}

class Solution{
public:
    unsigned int reverse(unsigned int x){
        assert(sizeof(x) == 4);
        x = (x & 0x55555555) << 1  | (x & 0xAAAAAAAA) >> 1;
        x = (x & 0x33333333) << 2  | (x & 0xCCCCCCCC) >> 2;
        x = (x & 0x0F0F0F0F) << 4  | (x & 0xF0F0F0F0) >> 4;
        x = (x & 0x00FF00FF) << 8  | (x & 0xFF00FF00) >> 8;
        x = (x & 0x0000FFFF) << 16 | (x & 0xFFFF0000) >> 16;
        return x;
    }
};

class Solution1{
public:
    unsigned int reverse(unsigned int x){
        int n = 8 * sizeof(x);
        int i = n - 1;
        int j = 0;
        while(i > j){
            if((x >> i & 1) ^ (x >> j & 1)){
                x ^= 1 << i;
                x ^= 1 << j;
            }
            i--;
            j++;
        }
        return x;
    }
};

int main(){
    unsigned int x = 9;
    print(x);

    Solution solution;
    unsigned int y = solution.reverse(x);
    print(y);

    return 0;
}

