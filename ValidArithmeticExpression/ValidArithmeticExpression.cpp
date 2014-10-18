/*
    http://www.mitbbs.com/article/JobHunting/32364859_0.html
    
    Write code to do arithmetic expression validation: 
    digits: 0..9
    operators: +, -, (, )
    
    E.g.:
    1+2-3  valid
    1+(2-(3+4)) valid
    -2 not valid
 */
 
#include <iostream>
#include <stack>
#include <vector>
#include <cassert>
using namespace std;


class Solution{
public: 
    int compute(int left, int right, char op){
        if(op == '+') return left + right;
        if(op == '-') return left - right;
        if(op == '*') return left * right;
        if(op == '/') return left / right;
    }
    
    bool validExpression(string s){
        int n = s.size();
        stack<int> numStk;
        stack<char> opStk;
        
        for(int i = 0; i < n; i++){
            char c = s[i];
            
            if(c >= '0' && c <= '9')
                numStk.push(c - '0');
            
            else if(c == '(' || c == '+' || c == '-')
                opStk.push(c);
            
            else if(c == ')'){
                if(opStk.size() < 2)
                    return false;

                if(opStk.top() != '+' && opStk.top() != '-')
                    return false;               
                char op = opStk.top();
                opStk.pop();
                
                if(opStk.top() != '(')
                    return false;
                opStk.pop();
                
                if(numStk.size() < 2)
                    return false;
                
                int right = numStk.top();
                numStk.pop();
                int left = numStk.top();
                numStk.pop();
                
                numStk.push(compute(left, right, op));
            }
            else
                return false;
        }
        return numStk.size() - opStk.size() == 1;
    }
    
    int calculateExpression(string s){
        int n = s.size();
        stack<int> numStk;
        stack<char> opStk;
        
        for(int i = 0; i < n; i++){
            char c = s[i];
            
            if(c >= '0' && c <= '9')
                numStk.push(c - '0');
            
            else if(c == '(' || c == '+' || c == '-')
                opStk.push(c);
            
            else if(c == ')'){
                char op = opStk.top();
                opStk.pop();
                opStk.pop();
                
                int right = numStk.top();
                numStk.pop();
                int left = numStk.top();
                numStk.pop();
                
                numStk.push(compute(left, right, op));
            }
        }
        
        while(!opStk.empty()){
            char op = opStk.top();
            opStk.pop();
            
            int right = numStk.top();
            numStk.pop();
            
            int left = numStk.top();
            numStk.pop();
            
            numStk.push(compute(left, right, op));
        }
        
        return numStk.top();
    }   
};

int main(){
    Solution solution;
    
    vector<string> strs;
    strs.push_back("1+2-3");
    strs.push_back("1+(2-(3+4))");
    strs.push_back("-2");
    
    for(int i = 0; i < strs.size(); i++){
        if(solution.validExpression(strs[i]))
            cout << solution.calculateExpression(strs[i]) << "\n";
        else
            cout << "invalid" << "\n";
    }
    return 0;
}