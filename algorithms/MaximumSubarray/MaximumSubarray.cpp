/*
 * time: O(n), space O(1)
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int maxSubArray(int A[], int n){
        int sum = 0;
        int maxSum = INT_MIN;
        for(int i = 0; i < n; i++){
            sum += A[i];
            if(sum > maxSum)
                maxSum = sum;
            if(sum < 0)
                sum = 0;
        }
        return maxSum;
    }
};

int main(){
    int A[] = {-1, 1};
    int n = sizeof(A) / sizeof(A[0]);

    Solution solution;
    int res = solution.maxSubArray(A, n);
    cout << res << endl;

    return 0;
}

