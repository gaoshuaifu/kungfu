/*
 * time: O(n), space: O(1)
 */
#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

class Solution{
public:
    enum Color{WHITE, GRAY, BLACK};

    vector<vector<string> > backtrack(string start, string end, map<string, vector<string> >& parents){
        bool isDone = false;
        vector<vector<string> > currV;
        currV.push_back(vector<string>());
        currV[0].push_back(end);
        while(true){
            int pos = currV[0].size() - 1;
            vector<vector<string> > nextV;
            for(int i = 0; i < currV.size(); i++){
                vector<string> prt = parents[currV[i][pos]];
                if(prt[0] == start)
                    isDone = true;
                for(int j = 0; j < prt.size(); j++){
                    currV[i].push_back(prt[j]);
                    nextV.push_back(currV[i]);
                    currV[i].pop_back();
                }
            }
            currV = nextV;
            if(isDone)
                break;
        }
        
        for(int i = 0; i < currV.size(); i++)
            reverse(currV[i].begin(), currV[i].end());
        return currV;       
    }
    
    vector<vector<string> > findLadders(string start, string end, set<string>& dict){
        vector<vector<string> > res;

        queue<string> currQ;
        map<string, Color> colors;
        currQ.push(start);
        colors[start] = BLACK;
        map<string, vector<string> > parents;
        bool foundEnd = false;
        
        while(!currQ.empty()){
            queue<string> nextQ;
            vector<string> strFound;
            while(!currQ.empty()){
                string currStr = currQ.front();
                currQ.pop();

                for(int i = 0; i < currStr.size(); i++){
                    for(int c = 'a'; c <= 'z'; c++){
                        if(currStr[i] == c)
                            continue;
                        string nextStr = currStr;
                        nextStr[i] = c;
                        
                        if(nextStr == end){
                            foundEnd = true;
                            parents[nextStr].push_back(currStr);
                        }

                        if(!foundEnd && (colors.find(nextStr) == colors.end() || colors[nextStr] == GRAY) && dict.find(nextStr) != dict.end()){
                            if(colors.find(nextStr) == colors.end()){
                                nextQ.push(nextStr);
                                colors[nextStr] = GRAY;
                                strFound.push_back(nextStr);    
                            }
                            parents[nextStr].push_back(currStr);
                        }
                    }
                }
            }

            if(foundEnd){
                res = backtrack(start, end, parents);
                return res;
            }

            currQ = nextQ;
            for(int i = 0; i < strFound.size(); i++)
                colors[strFound[i]] = BLACK;
        }
       
        return res;
    }
};


int main(){
    string start = "red";
    string end = "tax";
    set<string> dict;
    dict.insert("ted");
    dict.insert("tex");
    dict.insert("red");
    dict.insert("tax");
    dict.insert("tad");
    dict.insert("den");
    dict.insert("rex");
    dict.insert("pee");
    Solution solution;
    vector<vector<string> > res = solution.findLadders(start, end, dict);
    
    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << " ";
        cout << "\n";
    }
    cout << endl;

    return 0;
}


