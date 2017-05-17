/*
 * time: O(m + n), space: O(1)
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

        int i = 0;
        int j = n - 1;

        while(i <= m - 1 && j >= 0){
            if(matrix[i][j] > target)
                j--;
            else if(matrix[i][j] < target)
                i++;
            else
                return true;
        }

        return false;
    }
};

int main(){
    int a[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int> > matrix;
    for(int i = 0; i < 3; i++){
        vector<int> row = vector<int>(a[i], a[i] + 3);
        matrix.push_back(row);
    }

    int target = 5;

    Solution solution;
    bool res = solution.searchMatrix(matrix, target);
    cout << res << endl;
    return 0;
}
