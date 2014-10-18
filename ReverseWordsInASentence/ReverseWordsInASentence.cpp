#include <iostream>
#include <string>
using namespace std;

class Solution{
public:
    void reverseWords(string& s){
        int n = s.size();
        int start = 0;
        int end;

        while(start < n){
            if(s[start] == ' '){
                start++;
                continue;
            }
            end = start;
            while(s[end] != ' ')
                end++;

            reverse(s.begin() + start, s.begin() + end);

            start = end;
        }
        reverse(s.begin(), s.end());
    }
};

int main(){
    Solution solution;

    string s = "    I love hello world  ";
    cout << "\"" << s << "\"" << endl;
    solution.reverseWords(s);
    cout << "\"" << s << "\"" << endl;

    return 0;
}
