/*
 * time: O(n^2), space: O(1)
 */
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

/*
 ____________________
|           |     |  |
|___________|     |  |
|         (i,j)   |  |
|                 |  |
| (n-1-j,i)       |  |
|__               |  |
|  |     (j,n-1-i)|__|
|  |                 |
|  | (n-1-i,n-1-j)   |
|  |     ____________|
|  |     |           |
|__|_____|___________|

*/


class Solution{
public:
    void rotate(vector<vector<int> >& matrix){
        int n = matrix.size();
        assert(n == matrix[0].size());

        for(int i = 0; i < n / 2; i++){
            for(int j = i; j < n - 1 - i; j++){
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[n - 1 - j][i];
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
                matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
                matrix[j][n - 1 - i] = tmp;
            }
        }
    }
};

int main(){
    int a[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int> > matrix;
    for(int i = 0; i < 3; i++){
        vector<int> row = vector<int>(a[i], a[i] + 3);
        matrix.push_back(row);
    }

    Solution solution;
    solution.rotate(matrix);

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++)
            cout << matrix[i][j] << " ";
        cout << "\n";
    }
    cout << endl;

    return 0;
}

