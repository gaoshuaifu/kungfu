#include <iostream>
using namespace std;

class Solution{
public:
    void replace(char* s){
        int n = strlen(s);
        int count = 0;

        for(int i = 0; i < n; i++)
            if(s[i] == ' ')
             count++;

        int m = n + 2 * count;
        s[m] = '\n';

        int i = n - 1;
        int j = m - 1;

        while(i >= 0){
            if(s[i] != ' ')
                s[j--] = s[i--];
            else{
                s[j--] = '0';
                s[j--] = '2';
                s[j--] = '%';
                i--;
            }
        }
    }
};

int main(){
    Solution solution;

    char s[1000] = "Hello, world! Hello, Yang!";
    solution.replace(s);
    cout << s << endl;
    return 0;
}
