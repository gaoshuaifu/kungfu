/*
 * time: O(n), space: O(n)
 */
#include <iostream>
#include <vector>
#include <map>
using namespace std;


class Solution{
public:
    int longestConsecutive(vector<int>& num){
        int n = num.size();

        map<int, bool> visited;
        for(int i = 0; i < n; i++)
            visited[num[i]] = false;

        int maxLen = 0;
        for(int i = 0; i < n; i++){
            if(visited[num[i]])
                continue;

            visited[num[i]] = true;
            int len = 1;

            int left = num[i] - 1;
            while(visited.count(left) > 0){
                visited[left] = true;
                left--;
                len++;
            }

            int right = num[i] + 1;
            while(visited.count(right) > 0){
                visited[right] = true;
                right++;
                len++;
            }

            maxLen = max(maxLen, len);
        }
        return maxLen;
    }
};

class Solution1{
public:
    int merge(map<int, int>& mapping, int left, int right){
        int lower = left - mapping[left] + 1;
        int upper = right + mapping[right] - 1;
        int len = upper - lower + 1;
        mapping[lower] = len;
        mapping[upper] = len;
        return len;
    }

    int longestConsecutive(vector<int>& num){
        int n = num.size();
        map<int, int> mapping;

        int maxLen = 1;
        for(int i = 0; i < n; i++){
            if(mapping.find(num[i]) != mapping.end())
                continue;

            mapping[num[i]] = 1;

            if(mapping.find(num[i] - 1) != mapping.end())
                maxLen = max(maxLen, merge(mapping, num[i] - 1, num[i]));

            if(mapping.find(num[i] + 1) != mapping.end())
                maxLen = max(maxLen, merge(mapping, num[i], num[i] + 1));
        }
        return maxLen;
    }
};


int main(){
    int a[] = {4, 100, 1, 200, 3, 101, 2, 5};
    vector<int> num = vector<int>(a, a + sizeof(a) / sizeof(a[0]));

    Solution solution;
    int res = solution.longestConsecutive(num);
    cout << res << endl;
    return 0;
}
