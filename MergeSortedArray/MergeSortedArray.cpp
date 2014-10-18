/*
 * time: O(m + n), space: O(1)
 */
#include <iostream>
using namespace std;

class Solution{
public:
    void merge(int A[], int m, int B[], int n){
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;
        while (i >= 0 && j >= 0) {
            if (A[i] >= B[j]) 
                A[k--] = A[i--];
            else 
                A[k--] = B[j--];
        }
        while (i >= 0) 
            A[k--] = A[i--];
        while (j >= 0) 
            A[k--] = B[j--];
    }
};

class Solution1{
public:
    void merge(int A[], int m, int B[], int n){
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;
        while (i >= 0 || j >= 0) {
            if(i >= 0 && j >= 0){
                if (A[i] >= B[j]) 
                    A[k--] = A[i--];
                else 
                    A[k--] = B[j--];
            }
            else if(i >= 0)
                A[k--] = A[i--];
            else
                A[k--] = B[j--];
        }
    }
};

int main(){
    int A[1024] = {1, 3, 5, 7};
    int B[1024] = {2, 4, 6, 8};
    int m = 4;
    int n = 4;
    
    Solution solution;
    solution.merge(A, m, B, n);
    
    for(int i = 0; i < m + n; i++)
        cout << A[i] << " ";
    cout << endl;
    
    return 0;
}

