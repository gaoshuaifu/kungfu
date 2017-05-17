/*
 * time: O(n), space: O(1)
 */
#include <iostream>
#include <cstring>
using namespace std;

class Solution{
public:
    int lengthOfLastWord(const char* s){
        int n = strlen(s);
        int i = n - 1;
        while(i >= 0 && s[i] == ' ')
            i--;

        if(i < 0) return 0;

        int j = i;
        while(j >= 0 && s[j] != ' ')
            j--;

        return i - j;
    }
};

int main(){
    Solution solution;
    cout << solution.lengthOfLastWord("a ") << endl;
    return 0;
}

