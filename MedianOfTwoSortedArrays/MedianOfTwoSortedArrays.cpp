/*
 * explanation: http://blog.unieagle.net/2012/10/04/leetcode%E9%A2%98%E7%9B%AE%EF%BC%9Amedian-of-two-sorted-arrays/
 * time: O(logk), space: O(1)
 */
#include <iostream>
#include <cassert>
using namespace std;

class Solution{
public:
    int findKth(int A[], int m, int B[], int n, int k){
        if(m == 0)
            return B[k - 1];
        if(n == 0)
            return A[k - 1];
        if(k == 1)
            return min(A[0], B[0]);
        
        int ka, kb;
        if(m < n){
            ka = min(k / 2, m);
            kb = k - ka;
        }
        else{
            kb = min(k / 2, n);
            ka = k - kb;
        }
        
        if(A[ka - 1] < B[kb - 1])
            return findKth(A + ka, m - ka, B, n, k - ka);
        else
            return findKth(A, m, B + kb, n - kb, k - kb);
    }
    
    double findMedianSortedArrays(int A[], int m, int B[], int n){
        int t = m + n;
        assert(t > 0);
        
        if(t % 2)
            return findKth(A, m, B, n, (t + 1) / 2);
        else
            return (findKth(A, m, B, n, t / 2) + findKth(A, m, B, n, t / 2 + 1)) / 2.0;
    }
};

int main(){
    int A[] = {1, 3, 5, 7};
    int B[] = {2, 4, 6, 8};
    int m = sizeof(A) / sizeof(A[0]);
    int n = sizeof(B) / sizeof(B[0]);
    
    Solution solution;
    cout << solution.findMedianSortedArrays(A, m, B, n) << endl;
    
    return 0;
}

