#include <iostream>
#include <sstream>
#include <stack>
#include <vector>
#include <cassert>
using namespace std;

class Solution{
public:
    int str2int(string s){
        int res;
        istringstream iss(s);
        iss >> res;
        return res;
    }
    
    bool isOperator(string s){
        return s == "+" || s == "-" || s == "*" || s == "/";    
    }
    
    int compute(int left, int right, string op){
        if(op == "+") return left + right;
        if(op == "-") return left - right;  
        if(op == "*") return left * right;  
        if(op == "/") return left / right;          
    }
    
    int solve(vector<string> strs){
        int n = strs.size();
        stack<int> stk;
        
        for(int i = 0; i < n; i++){
            string s = strs[i]; 
            if(isOperator(s)){
                int right = stk.top();
                stk.pop();
                
                int left = stk.top();
                stk.pop();
                
                int result = compute(left, right, s);
                stk.push(result);
            }
            else
                stk.push(str2int(s));
        }   
        assert(stk.size() == 1);
        return stk.top();
    }
};

int main(){
    Solution solution;
    
    vector<string> strs;
    strs.push_back("4");
    strs.push_back("1");
    strs.push_back("+");
    strs.push_back("2");
    strs.push_back("*");    
    cout << solution.solve(strs) << endl;
    
    strs.clear();
    strs.push_back("5");
    strs.push_back("8");
    strs.push_back("4");
    strs.push_back("/");
    strs.push_back("+");
    cout << solution.solve(strs) << endl;
        
    return 0;   
}

