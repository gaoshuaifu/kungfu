/*
 * time: O(n), space: O(n)
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

        vector<int> left = vector<int>(n, 0);
        int minPrice = prices[0];
        int maxProfit = 0;
        for(int i = 1; i < n; i++){
            maxProfit = max(maxProfit, prices[i] - minPrice);
            left[i] = maxProfit;
            minPrice = min(minPrice, prices[i]);
        }

        vector<int> right = vector<int>(n, 0);
        int maxPrice = prices[n - 1];
        maxProfit = 0;
        for(int i = n - 2; i >= 0; i--){
            maxProfit = max(maxProfit, maxPrice - prices[i]);
            right[i] = maxProfit;
            maxPrice = max(maxPrice, prices[i]);
        }

        int maxTotal = 0;
        for(int i = 0; i < n; i++)
            maxTotal = max(maxTotal, left[i] + right[i]);
        return maxTotal;
    }
};

int main(){
    int priceArray[] = {1, 4, 2};
    vector<int> prices = vector<int>(priceArray, priceArray + sizeof(priceArray) / sizeof(int));

    Solution solution;
    int res = solution.maxProfitit(prices);
    cout << res << endl;

    return 0;
}
