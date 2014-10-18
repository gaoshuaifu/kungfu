/*
 * time: O(n^2), space: O(n^2)
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    void generateMatrixHelper(int n, int k, int& start, vector<vector<int> >& matrix){
        if(n == 0)
            return;
        
        if(n == 1){
            matrix[k][k] = start;
            return;
        }
            
        for(int j = k; j < k + n - 1; j++)
            matrix[k][j] = start++;
        
        for(int i = k; i < k + n - 1; i++)
            matrix[i][k + n - 1] = start++;
        
        for(int j = k + n - 1; j > k; j--)
            matrix[k + n - 1][j] = start++;
        
        for(int i = k + n - 1; i > k; i--)
            matrix[i][k] = start++;
        
        generateMatrixHelper(n - 2, k + 1, start, matrix);
    }
    
    vector<vector<int> > generateMatrix(int n){
        vector<vector<int> > matrix(n, vector<int>(n, 0));
        int start = 1;
        generateMatrixHelper(n, 0,start, matrix);
        return matrix;
    }
};

int main(){
    int n = 3;
    
    Solution solution;
    vector<vector<int> > res = solution.generateMatrix(n);
    
    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j < res[0].size(); j++)
            cout << res[i][j] << " ";
        cout << "\n";
    }
    cout << endl;
    return 0;
}

