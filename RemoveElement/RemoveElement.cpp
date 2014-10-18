/*
 * time: O(n), space: O(1)
 */
#include <iostream>
using namespace std;

class Solution{
public:
    int removeElement(int A[], int n, int elem){
        int j = 0;
        for(int i = 0; i < n; i++){
            if(A[i] == elem)
                continue;
            else{
                A[j] = A[i];
                j++;
            }
        }

        return j;
    }
};


int main(){
    int A[] = {1, 2, 3, 1, 1, 4, 5, 1, 6, 1, 7, 1};
    int elem = 1;

    Solution solution;
    int n = solution.removeElement(A, sizeof(A) / sizeof(A[0]), elem);

    for(int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;
}

