/*
 * time: O(logn), space: O(1)
 */
#include <iostream>
using namespace std;

class Solution{
public:
    int searchInsert(int A[], int n, int target){
        int low = 0;
        int high = n - 1;
        while(low <= high){
            int mid = low + (high - low) / 2;

            if(target == A[mid])
                return mid;

            if(target < A[mid])
                high = mid - 1;
            else if(target > A[mid])
                low = mid + 1;
        }
        return low;
    }
};

int main(){
    int A[] = {1, 3, 5, 6};
    int n = sizeof(A) / sizeof(A[0]);

    Solution solution;
    cout << solution.searchInsert(A, n, 5) << endl;
    cout << solution.searchInsert(A, n, 2) << endl;
    cout << solution.searchInsert(A, n, 7) << endl;
    cout << solution.searchInsert(A, n, 0) << endl;

    return 0;
}

