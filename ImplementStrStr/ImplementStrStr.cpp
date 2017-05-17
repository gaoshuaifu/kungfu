/*
 * time: O((m - n) * n), space: O(1)
 */
#include <iostream>
#include <cstring>
using namespace std;

class Solution{
public:
    void precompute(char* pat, int n, int* PI){
        PI[0] = -1;
        int j = -1;
        for(int i = 1; i < n; i++){
            while(j > -1 && pat[j + 1] != pat[i])
                j = PI[j];
            if(pat[j + 1] == pat[i])
                j++;
            PI[i] = j;
        }
    }

    char* strStr(char* str, char* pat){
        int m = strlen(str);
        int n = strlen(pat);

        if(n == 0) return str;

        int PI[n];
        precompute(pat, n, PI);

        int j = -1;
        for(int i = 0; i < m; i++){
            while(j > -1 && pat[j + 1] != str[i])
                j = PI[j];
            if(pat[j + 1] == str[i])
                j++;
            if(j == n - 1)
                return str + (i - n + 1);
        }
        return NULL;
    }
};

class Solution1{
public:
    char* strStr(char* str, char* pat){
        int m = strlen(str);
        int n = strlen(pat);

        for(int i = 0; i < m - n + 1; i++){
            bool isMatch = true;
            for(int j = 0; j < n; j++){
                if(str[i + j] != pat[j]){
                    isMatch = false;
                    break;
                }
            }
            if(isMatch)
                return str + i;
        }
        return NULL;
    }
};

int main(){
    char str[100] = "mississippi";
    char pat[100] = "issip";
    Solution solution;
    char* res = solution.strStr(str, pat);
    cout << res << endl;
    return 0;
}

