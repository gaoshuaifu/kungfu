/*
 * time: O(m * n), space: O(1)
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    void setZeroes(vector<vector<int> >& matrix){
        int m = matrix.size();
        if(m == 0) return;

        int n = matrix[0].size();
        if(n == 0) return;

        bool firstColZero = false;
        for(int i = 0; i < m; i++){
            if(matrix[i][0] == 0){
                firstColZero = true;
                break;
            }
        }

        bool firstRowZero = false;
        for(int j = 0; j < n; j++){
            if(matrix[0][j] == 0){
                firstRowZero = true;
                break;
            }
        }

        for(int i = 1; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    break;
                }
            }
        }

        for(int j = 1; j < n; j++){
            for(int i = 0; i < m; i++){
                if(matrix[i][j] == 0){
                    matrix[0][j] = 0;
                    break;
                }
            }
        }

        for(int i = 1; i < m; i++){
            if(matrix[i][0] != 0)
                continue;
            for(int j = 1; j < n; j++)
                matrix[i][j] = 0;
        }

        for(int j = 1; j < n; j++){
            if(matrix[0][j] != 0)
                continue;
            for(int i = 1; i < m; i++)
                matrix[i][j] = 0;
        }

        if(firstColZero){
            for(int i = 0; i < m; i++)
                matrix[i][0] = 0;
        }

        if(firstRowZero){
            for(int j = 0; j < n; j++)
                matrix[0][j] = 0;
        }
    }
};


int main(){
    int a[5][4] = {{1,0,0,5},{4,3,1,4},{0,1,1,4},{1,2,1,3},{0,0,1,1}};
    vector<vector<int> > matrix;
    for(int i = 0; i < 5; i++){
        vector<int> row = vector<int>(a[i], a[i] + 4);
        matrix.push_back(row);
    }
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++)
            cout << matrix[i][j] << " ";
        cout << "\n";
    }
    cout << endl;


    Solution solution;
    solution.setZeroes(matrix);

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++)
            cout << matrix[i][j] << " ";
        cout << "\n";
    }
    cout << endl;
    return 0;
}

