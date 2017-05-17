#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
    int longestIncreasingSubstringLen(vector<int> num){
        int n = num.size();
        if(n == 0) return 0;

        int len = 1;
        int maxLen = 1;

        for(int i = 1; i < n; i++){
            if(num[i] > num[i - 1]){
                len++;
                maxLen = max(maxLen, len);
            }
            else
                len = 1;
        }

        return maxLen;
    }
};

int main(){
    int arr[] = {0, 8, 4, 12, 2, 3, 4, 5, 6, 7, 5, 13, 3, 11, 7, 15};
    vector<int> num(arr, arr + sizeof(arr) / sizeof(arr[0]));

    Solution solution;
    int len = solution.longestIncreasingSubstringLen(num);
    cout << len << "\n";

    return 0;
}
