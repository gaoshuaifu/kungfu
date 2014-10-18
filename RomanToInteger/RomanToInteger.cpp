/*
 * time: O(n), space: O(1)
 */
#include <iostream>
#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    int mapping(char c){
        switch(c){  
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
        }
    }
    
    int romanToInt(string s) {
        int n = s.size();
        int res = 0;
        for(int i = 0; i < n; i++){
            if(mapping(s[i]) < mapping(s[i + 1]))
                res -= mapping(s[i]);
            else
                res += mapping(s[i]);
        }
        return res;
    }
};

int main(){
    string s = "MMMCMXCIX";
    
    Solution solution;
    cout << solution.romanToInt(s) << endl;
    
    return 0;
}
