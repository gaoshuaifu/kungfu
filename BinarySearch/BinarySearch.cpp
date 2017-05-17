#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int binarySearch(vector<int>& A, int target){
        int n = A.size();
        int low = 0;
        int high = n - 1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(A[mid] == target)
                return mid;
            else if(A[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }
};

int main(){
    int a[] = {1, 3, 5, 7, 9};
    vector<int> A(a, a + sizeof(a) / sizeof(a[0]));

    Solution solution;
    for(int i = 0; i <= 10; i++){
        cout << "index of " << i << " is " << solution.binarySearch(A, i) << "\n\n";

    }

    return 0;
}

