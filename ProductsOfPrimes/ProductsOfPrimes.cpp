#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    void productsHelper(vector<int>& nums, int index, int product, vector<int>& res) {
        if(product != 1)
            res.push_back(product);

        for(int i = index; i < nums.size(); i++) {
            productsHelper(nums, i + 1, product * nums[i], res);
        }
    }

    vector<int> products(vector<int>& nums) {
        vector<int> res;
        int product = 1;
        productsHelper(nums, 0, product, res);
        return res;
    }

    void productsWithDupHelper(vector<int>& nums, int index, int product, vector<int>& res) {
        if(product != 1)
            res.push_back(product);

        set<int> visited;
        for(int i = index; i < nums.size(); i++) {
            if(visited.count(nums[i]) == 0) {
                visited.insert(nums[i]);
                productsWithDupHelper(nums, i + 1, product * nums[i], res);
            }
        }
    }

    vector<int> productsWithDup(vector<int>& nums) {
        vector<int> res;
        int product = 1;
        productsWithDupHelper(nums, 0, product, res);
        return res;
    }
};

int main() {
    Solution solution;

    int A[] = {2, 3, 5};
    vector<int> nums1(A, A + sizeof(A) / sizeof(A[0]));
    vector<int> res1 = solution.products(nums1);
    for(int i = 0; i < res1.size(); i++)
        cout << res1[i] << " ";
    cout << endl;

    int B[] = {2, 2, 3, 5};
    vector<int> nums2(B, B + sizeof(B) / sizeof(B[0]));
    vector<int> res2 = solution.productsWithDup(nums2);
    for(int i = 0; i < res2.size(); i++)
        cout << res2[i] << " ";
    cout << endl;
    return 0;
}
