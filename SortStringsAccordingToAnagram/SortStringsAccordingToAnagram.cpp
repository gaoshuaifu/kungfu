#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution{
public:
    struct LessThan{
        bool operator()(const string& a, const string& b){
            string aa = a;
            sort(aa.begin(), aa.end());
            string bb = b;
            sort(bb.begin(), bb.end());
            return aa < bb;
        }
    };
    
    void anagramSort(vector<string>& strs){
        sort(strs.begin(), strs.end(), LessThan());
    }
};

class Solution1{
public:
    void anagramSort(vector<string>& strs){
        map<string, vector<string> > mapping;
        
        for(int i = 0; i < strs.size(); i++){
            string key = strs[i];
            sort(key.begin(), key.end());
            mapping[key].push_back(strs[i]);
        }
        
        strs.clear();
        
        for(map<string, vector<string> >::iterator it = mapping.begin(); it != mapping.end(); it++){
            sort(it->second.begin(), it->second.end());
            strs.insert(strs.end(), it->second.begin(), it->second.end());
        }
    }
};

int main(){
    vector<string> strs;
    strs.push_back("aab");  
    strs.push_back("baa");  
    strs.push_back("abc");  
    strs.push_back("cba");  
    strs.push_back("bbc");  
    strs.push_back("cbc");

    Solution solution;
    solution.anagramSort(strs);
    
    for(int i = 0; i < strs.size(); i++)
        cout << strs[i] << "\n";
    
    return 0;
}