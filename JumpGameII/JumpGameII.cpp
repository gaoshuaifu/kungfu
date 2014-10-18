/*
 * time: O(n), space: O(1)
 */
#include <iostream>
using namespace std;

class Solution{
public:
    int jump(int A[], int n){
        int start = 0;
        int end = 0;
        int count = 0;
        while(end < n - 1){
            int far = INT_MIN;
            for(int i = start; i <= end; i++)
                far = max(far, i + A[i]);
            if(far <= end)
                return -1;
            start = end + 1;
            end = far;
            count++;
        }
        return count;
    }
};

int main(){
    int A[] = {2,3,1,1,4};
    int n = sizeof(A) / sizeof(A[0]);

    Solution solution;
    cout << solution.jump(A, n) << endl;
    return 0;
}

