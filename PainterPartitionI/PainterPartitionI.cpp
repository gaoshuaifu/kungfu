/*
 * time: O(kn^2), space: O(kn)
 */
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void print(vector<int>& L, int width){
    int n = L.size();
    
    int s = 0;
    for(int i = 0; i < n - 1; i++){
        s += L[i];
        cout << L[i];
        if(s <= width && s + L[i + 1]> width){
            cout << '|';
            s = 0;
        }
        else 
            cout << ' ';
    }
    cout << L[n - 1] << endl;
}

/* dp[i][j] is solution of L[0..i] with j cuts */
class Solution{
public: 
    int partition(vector<int>& L, int k){
        int n = L.size();
        
        vector<int> cum(n, 0);
        cum[0] = L[0];
        for(int i = 1; i < n; i++)
            cum[i] = cum[i - 1] + L[i];
        
        vector<vector<int> > dp(n, vector<int>(k, INT_MAX));
        for(int j = 0; j < k; j++)
            dp[0][j] = L[0];
        for(int i = 1; i < n; i++)
            dp[i][0] = dp[i - 1][0] + L[i];
        
        for(int i = 1; i < n; i++){
            for(int j = 1; j < k; j++){
                for(int p = 0; p < i; p++){
                    int width = max(dp[p][j - 1], cum[i] - cum[p]);
                    if(width < dp[i][j])
                        dp[i][j] = width;
                }
            }
        }
        
        return dp[n - 1][k - 1];
    }
};

class Solution1{
public:
    int sum(vector<int>& L, int l, int h){
        if(l > h)
            return 0;
        
        int s = 0;
        for(int i = l; i <= h; i++)
            s += L[i];
        return s;
    }

    int partitionHelper(vector<int>& L, int n, int k){
        if(n == 1)
            return L[0];
        if(k == 1)
            return sum(L, 0, n - 1);
        
        int minWidth = INT_MAX;
        for(int p = 1; p < n; p++){
            int width = max(partitionHelper(L, p, k - 1), sum(L, p, n - 1));
            if(width < minWidth)
                minWidth = width;
        }
        
        return minWidth;    
    }   
    
    int partition(vector<int>& L, int k){
        int n = L.size();
        return partitionHelper(L, n, k);
    }
};

int main(){
    int A[] = {100, 200, 300, 400, 500, 600, 700, 800, 900};
    vector<int> L(A, A + sizeof(A) / sizeof(A[0]));
    int k = 3;
    
    Solution solution;
    int width = solution.partition(L, k);
    cout << width << endl;
    print(L, width);

    Solution1 solution1;
    int width1 = solution1.partition(L, k);
    cout << width1 << endl;
    print(L, width1);   
    
    return 0;
}   

