/*
 * time: O(n), space: O(1)
 */
#include <iostream>
using namespace std;

class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        int i = 0;
        while(i < n){
            if (A[i] >= 1 && A[i] <= n && A[i] != A[A[i] - 1])
                swap(A[i], A[A[i] - 1]);
            else 
                i++;
        }
        
        for (i = 0; i < n; i++)
            if (A[i] != i + 1) 
                return i + 1;
                
        return n + 1;
    }
};

int main(){
    int A[] = {3, 4, -1, 1};
    int n = sizeof(A) / sizeof(A[0]);
    
    Solution solution;
    cout << solution.firstMissingPositive(A, n);
    return 0;
}

