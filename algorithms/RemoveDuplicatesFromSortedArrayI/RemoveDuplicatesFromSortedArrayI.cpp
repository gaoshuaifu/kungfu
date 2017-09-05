/*
 * time: O(n), space: O(1)
 */
#include <iostream>
using namespace std;

class Solution{
public:
    int removeDuplicates(int A[], int n){
        if(n == 0)
            return 0;

        int j = 1;
        for(int i = 1; i < n; i++){
            if(A[i] != A[i - 1]){
                A[j] = A[i];
                j++;
            }
        }
        return j;
    }
};

class Solution1{
public:
    int removeDuplicates(int A[], int n){
        if(n == 0)
            return 0;

        int j = 0;
        for(int i = 1; i < n; i++){
            if(A[i] != A[j]){
                j++;
                A[j] = A[i];
            }
        }
        return j + 1;
    }
};

int main(){
    int A[] = {1, 1, 2, 3, 3, 4};
    int n = sizeof(A) / sizeof(A[0]);

    Solution solution;
    int res = solution.removeDuplicates(A, n);

    cout << res << endl;
    for(int i = 0; i < res; i++)
        cout << A[i] << " ";
    cout << endl;
    return 0;
}

