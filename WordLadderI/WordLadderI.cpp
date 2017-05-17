/*
 * time: O(n), space: O(n)
 */
#include <iostream>
#include <queue>
#include <set>
#include <cassert>
using namespace std;

class Solution{
public:
    int ladderLength(string start, string end, set<string>& dict){
        if(start == end)
            return 1;

        int dist = 2;
        queue<string> currQ;
        set<string> visited;
        currQ.push(start);
        visited.insert(start);

        while(!currQ.empty()){
            queue<string> nextQ;

            while(!currQ.empty()){
                string currStr = currQ.front();
                currQ.pop();

                for(int i = 0; i < currStr.size(); i++){
                    string nextStr = currStr;
                    for(char c = 'a'; c <= 'z'; c++){
                        if(currStr[i] == c)
                            continue;
                        nextStr[i] = c;
                        if(nextStr == end)
                            return dist;
                        if(visited.find(nextStr) == visited.end() && dict.find(nextStr) != dict.end()){
                            nextQ.push(nextStr);
                            visited.insert(nextStr);
                        }
                    }
                }
            }
            currQ = nextQ;
            dist++;
        }
        return 0;
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
    cout << solution.ladderLength(start, end, dict) << endl;
    return 0;
}


