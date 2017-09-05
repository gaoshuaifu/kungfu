/*
 * time: O(m * n), space: O(m * n)
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    void spiralOrderHelper(vector<vector<int> > &matrix, int m, int n, int k, vector<int>& res){
        if(m == 0 || n == 0)
            return;

        if(m == 1){
            for(int j = k; j <= k + n - 1; j++)
                res.push_back(matrix[k][j]);
            return;
        }

        if(n == 1){
            for(int i = k; i <= k + m - 1; i++)
                res.push_back(matrix[i][k]);
            return;
        }

        for(int j = k; j < k + n - 1; j++)
            res.push_back(matrix[k][j]);

        for(int i = k; i < k + m - 1; i++)
            res.push_back(matrix[i][k + n - 1]);

        for(int j = k + n - 1; j > k; j--)
            res.push_back(matrix[k + m - 1][j]);

        for(int i = k + m - 1; i > k; i--)
            res.push_back(matrix[i][k]);

        spiralOrderHelper(matrix, m - 2, n - 2, k + 1, res);
    }

    vector<int> spiralOrder(vector<vector<int> >& matrix){
        vector<int> res;

        int m = matrix.size();
        if(m == 0) return res;

        int n = matrix[0].size();
        if(n == 0) return res;

        spiralOrderHelper(matrix, m, n, 0, res);
        return res;
    }
};

int main(){
    int a[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    vector<vector<int> > matrix;
    for(int i = 0; i < 3; i++){
        vector<int> row = vector<int>(a[i], a[i] + 4);
        matrix.push_back(row);
    }

    Solution solution;
    vector<int> res = solution.spiralOrder(matrix);

    for(int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << endl;

    return 0;
}
