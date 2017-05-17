/*
 * time: O(n), space: O(n)
 */
#include <iostream>
#include <queue>
#include <set>
#include <map>
#include <cassert>
using namespace std;


class Solution{
public:
    vector<string> backtrack(string start, string end, map<string, string>& parent){
        vector<string> res;
        string curr = end;
        while(curr != start){
            res.push_back(curr);
            curr = parent[curr];
        }
        res.push_back(start);
        reverse(res.begin(), res.end());
        return res;
    }

    vector<string> findALadder(string start, string end, set<string>& dict){
        vector<string> res;
        if(start == end){
            res.push_back(start);
            return res;
        }

        queue<string> q;
        set<string> visited;
        q.push(start);
        visited.insert(start);
        map<string, string> parent;

        while(!q.empty()){
            string currStr = q.front();
            q.pop();

            for(int i = 0; i < currStr.size(); i++){
                string nextStr = currStr;
                for(char c = 'a'; c <= 'z'; c++){
                    if(c == currStr[i])
                        continue;

                    nextStr[i] = c;

                    if(nextStr == end){
                        parent[nextStr] = currStr;
                        res = backtrack(start, end, parent);
                        return res;
                    }

                    if(visited.find(nextStr) == visited.end() && dict.find(nextStr) != dict.end()){
                        q.push(nextStr);
                        visited.insert(nextStr);
                        parent[nextStr] = currStr;
                    }
                }
            }
        }
        return res;
    }
};


class Solution1{
public:
    vector<string> backtrack(string start, string end, map<string, string>& parent){
        vector<string> res;
        string curr = end;
        while(curr != start){
            res.push_back(curr);
            curr = parent[curr];
        }
        res.push_back(start);
        reverse(res.begin(), res.end());
        return res;
    }

    vector<string> findALadder(string start, string end, set<string>& dict){
        vector<string> res;
        if(start == end){
            res.push_back(start);
            return res;
        }

        queue<string> currQ;
        set<string> visited;
        currQ.push(start);
        visited.insert(start);
        map<string, string> parent;

        while(!currQ.empty()){
            queue<string> nextQ;
            while(!currQ.empty()){
                string currStr = currQ.front();
                currQ.pop();

                for(int i = 0; i < currStr.size(); i++){
                    string nextStr = currStr;
                    for(char c = 'a'; c <= 'z'; c++){
                        if(c == currStr[i])
                            continue;

                        nextStr[i] = c;

                        if(nextStr == end){
                            parent[nextStr] = currStr;
                            res = backtrack(start, end, parent);
                            return res;
                        }

                        if(visited.find(nextStr) == visited.end() && dict.find(nextStr) != dict.end()){
                            nextQ.push(nextStr);
                            visited.insert(nextStr);
                            parent[nextStr] = currStr;
                        }
                    }
                }
            }
            currQ = nextQ;
        }

        return res;
    }
};

int main(){
    string start = "hit";
    string end = "cog";
    set<string> dict;
    dict.insert("hot");
    dict.insert("dot");
    dict.insert("dog");
    dict.insert("lot");
    dict.insert("log");

    Solution solution;

    vector<string> res = solution.findALadder(start, end, dict);
    for(int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << endl;

    return 0;
}

