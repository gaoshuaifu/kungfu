/*
 * time: O(n), space: O(1)
 */
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    bool isLetter(char c){
        return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9';
    }
    
    char upper(char c){
        assert(isLetter(c));
        if(c >= 'a' && c <= 'z')
            return c - 'a' + 'A';
        return c;
    }
    
    bool isPalindrome(string s) {
        int n = s.size();
        int i = 0;
        int j = n - 1;
        
        while(i < j){
            while(i < j && !isLetter(s[i]))
                i++;
            while(i < j && !isLetter(s[j]))
                j--;
            
            if(i == j)
                return true;
            
            if(upper(s[i]) != upper(s[j]))
                return false;
            
            i++;
            j--;
        }
        
        return true;
    }
};

int main(){
    string s = "abcba";
    Solution solution;
    cout << solution.isPalindrome(s) << endl;
    return 0;
}
