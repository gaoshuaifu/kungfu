#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;


class Solution{
public:
    void letterCombinationsHelper(string& digits, map<char, string>& mapping, int index, string& sol, vector<string>& res){
        if(index == digits.size()){
            res.push_back(sol);
            return;
        }
        
        string letters = mapping[digits[index]];
        for(int i = 0; i < letters.size(); i++){
            sol.push_back(letters[i]);  
            letterCombinationsHelper(digits, mapping, index + 1, sol, res);
            sol.erase(sol.size() - 1);  // can be replaced by sol.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits){   
        map<char, string> mapping;
        mapping['2'] = "abc";
        mapping['3'] = "def";
        mapping['4'] = "ghi";
        mapping['5'] = "jkl";
        mapping['6'] = "mno";
        mapping['7'] = "pqrs";
        mapping['8'] = "tuv";
        mapping['9'] = "wxyz";
        mapping['0'] = " ";
        
        vector<string> res;
        string sol = "";
        letterCombinationsHelper(digits, mapping, 0, sol, res);
        return res;
    }
};

int main(){

    string digits = "234";
    Solution solution;
    vector<string> res = solution.letterCombinations(digits);
    for(int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << endl;
    return 0;
}

