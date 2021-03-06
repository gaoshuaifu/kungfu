/*
 * time: O(n), space: O(1)
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int maxProfit(vector<int>& prices){
        int n = prices.size();
        if(n <= 1)
            return 0;
        int maxProfit = 0;
        for(int i = 1; i < n; i++)
            maxProfit += max(0, prices[i] - prices[i - 1]);

        return maxProfit;
    }
};

int main(){
    int priceArray[] = {1, 4, 2};
    vector<int> prices = vector<int>(priceArray, priceArray + sizeof(priceArray) / sizeof(int));

    Solution solution;
    int res = solution.maxProfit(prices);
    cout << res << endl;

    return 0;
}


