/*
 * time: O(n), space: O(1)
 */
#include <iostream>
#include <algorithm>
using namespace std;


class Solution{
public:
    bool canJump(int A[], int n){
        int start = 0;
        int end = 0;

        while(end < n - 1){
            int far = INT_MIN;
            for(int i = start; i <= end; i++)
                far = max(far, i + A[i]);
            if(far <= end)
                return false;
            start = end + 1;
            end = far;
        }
        return true;
    }
};

class Solution1{
public:
    bool canJump(int A[], int n){
        int far = 0;
        for(int i = 0; i <= far && i < n; i++){
            far = max(far, i + A[i]);
        }
        return far >= n - 1;
    }
};

int main(){
    int A[] = {3,2,1,0,4};
    int n = sizeof(A) / sizeof(A[0]);

    int B[] = {2,3,1,1,4};
    int m = sizeof(B) / sizeof(B[0]);

    Solution solution;
    cout << solution.canJump(A, n) << endl;
    cout << solution.canJump(B, m) << endl;
    return 0;
}
