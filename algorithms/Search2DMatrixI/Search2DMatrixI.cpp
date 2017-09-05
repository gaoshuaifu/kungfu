/*
 * time: O(logm + logn), space: O(1)
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target){
        int m = matrix.size();
        assert(m > 0);

        int n = matrix[0].size();
        assert(n > 0);

        int low = 0;
        int high = m * n - 1;

        while(low <= high){
            int mid = (low + high) / 2;
            int value = matrix[mid / n][mid % n];
            if(value < target) {
                low = mid + 1;
            }
            else if (value > target){
                high = mid - 1;
            }
            else {
                return true;
            }
        }
        return false;
    }
};
