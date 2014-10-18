/*
 * time: O(n), space: O(1)
 */
#include <iostream>
#include <stack>
using namespace std;

class Solution{
public:
    int trap(int A[], int n){
        if(n == 0)
            return 0;

        int maxIndex = 0;
        for(int i = 0; i < n; i++){
            if(A[i] > A[maxIndex])
                maxIndex = i;
        }

        int sum = 0;
        
        int maxLeft = 0;
        for(int i = 0; i < maxIndex; i++){
            maxLeft = max(maxLeft, A[i]);
            sum += maxLeft - A[i];
        }

        int maxRight = 0;
        for(int i = n - 1; i > maxIndex; i--){
            maxRight = max(maxRight, A[i]);
            sum += maxRight - A[i];
        }

        return sum;
    }
};

int main(){
    int A[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

    Solution solution;
    int res = solution.trap(A, sizeof(A) / sizeof(A[0]));
    cout << res << endl;

    return 0;
}

