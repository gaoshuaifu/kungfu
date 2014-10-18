/*
 * time: O(n), space: O(1)
 */
#include <iostream>
#include <algorithm>
using namespace std;

/*

--------------------------------------
|       |i         |j       k|       |  
--------------------------------------

*/

class Solution{
public:
    void sortColors(int A[], int n){
        int i = 0;
        int j = 0;
        int k = n - 1;
        while(j <= k){
            if(A[j] == 0){
                swap(A[i], A[j]);
                i++;
                j++;
            }
            else if(A[j] == 1)
                j++;
            else if(A[j] == 2){
                swap(A[j], A[k]);
                k--;
            }
        }
    }
};

int main(){
    int A[] = {2, 1, 0, 0, 0, 1, 1, 2, 2, 0, 1, 2, 2, 1, 0};
    int n = sizeof(A) / sizeof(A[0]);
    
    Solution solution;
    solution.sortColors(A, n);
    
    for(int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;
    
    return 0;
}

