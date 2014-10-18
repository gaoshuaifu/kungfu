/*
 * time: O(l * n), space: O(m * n)
 */
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution{
public:
    vector<int> findSubstring(string S, vector<string>& L){
        vector<int> res;
        int l = S.size();
        int m = L.size();
        int n = L[0].size();

        map<string, int> needFind;
        for(int i = 0; i < m; i++)
            needFind[L[i]]++;

        for(int i = 0; i <= l - m * n; i++){
            map<string, int> hasFound;
            int j;
            for(j = 0; j < m; j++){
                int start = i + n * j;
                string str = S.substr(start, n);
                if(needFind.find(str) == needFind.end())
                    break;
                hasFound[str]++;
                if(hasFound[str] > needFind[str])
                    break;
            }
            if(j == m)
                res.push_back(i);
        }
        return res;
    }
};

int main(){
    string S = "barfoothefoobarman";
    vector<string> L;
    L.push_back("foo");
    L.push_back("bar");

    Solution solution;
    vector<int> res = solution.findSubstring(S, L);
    for(int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << endl;

    return 0;
}

