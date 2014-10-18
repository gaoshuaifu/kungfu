#include <iostream>
#include <cmath>
#include <cassert>
using namespace std;

class Solution{
public: 
    bool isPalindrome(int x){
        if(x < 0)
            return false;
        
        int div = 1;
        while(x / div >= 10)
            div *= 10;
        
        while(x != 0){
            int l = x % 10;
            int h = x / div;
            if(l != h)
                return false;
            x = (x % div) / 10;
            div = div / 100;
        }
        return true;
    }
};

class Solution1{
public: 
    int reverse(int x){
        assert(x >= 0);
        int y = 0;
        while(x != 0){
            y = 10 * y + x % 10;
            x /= 10;
        }
        return y;
    }
    
    bool isPalindrome(int x){
        if(x < 0)
            return false;
        int y = reverse(x);
        return x == y;
    }
};

int main(){ 
    Solution solution;
    cout << solution.isPalindrome(12321) << endl;
    return 0;
}

