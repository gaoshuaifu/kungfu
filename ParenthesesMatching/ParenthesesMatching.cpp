#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution{
public:
    bool isMatchingHelper(string& str, int& left, int index){
        if(index == str.size())
            return left == 0;

        if(str[index] == '(')
            left++;
        else{
            if(left > 0)
                left--;
            else
                return false;
        }

        return isMatchingHelper(str, left, index + 1);
    }

    bool isMatching(string str){
        int left = 0;
        return isMatchingHelper(str, left, 0);
    }
};

class Solution1{
public:
    bool isMatching(string str){
        int left = 0;

        for(int i = 0; i < str.size(); i++){
            if(str[i] == '(')
                left++;
            else{
                if(left > 0)
                    left--;
                else
                    return false;
            }
        }

        return left == 0;
    }
};

class Solution2{
public:
    bool isMatching(string str){
        stack<char> stk;

        for(int i = 0; i < str.size(); i++){
            if(str[i] == '(')
                stk.push(str[i]);
            else{
                if(!stk.empty())
                    stk.pop();
                else
                    return false;
            }
        }

        return stk.empty();
    }
};

int main(){
    Solution solution;
    vector<string> strs;
    strs.push_back("(())");
    strs.push_back("(()(");

    for(int i = 0; i < strs.size(); i++)
        cout << strs[i] << "\t" << solution.isMatching(strs[i]) << "\n";

    return 0;
}
