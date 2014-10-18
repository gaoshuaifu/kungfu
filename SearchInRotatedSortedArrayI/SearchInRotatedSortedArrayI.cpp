/*
 * time: O(logn), space: O(1)
 */
#include <iostream>
using namespace std;

class Solution{
public:
    int search(int A[], int n, int target){
        int low = 0;
        int high = n - 1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            
            if(target == A[mid])
                return mid;
            
            if(A[low] <= A[mid]){
                if(A[low] <= target && target < A[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            else{
                if(A[mid] < target && target <= A[high])
                    low = mid + 1;
                else    
                    high = mid - 1;
            }
        }
        return -1;
    }
};

int main(){
    int A[] = {4, 5, 6, 7, 0, 1, 2};
    int target = 2;
    
    Solution solution;
    int res = solution.search(A, sizeof(A)/sizeof(A[0]), target);
    cout << res << endl;
    
    return 0;
}



