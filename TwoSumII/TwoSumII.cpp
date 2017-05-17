class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = numbers.size() - 1;
        while(i < j) {
            int sum = numbers[i] + numbers[j];
            if(sum == target) {
                vector<int> res;
                res.push_back(i + 1);
                res.push_back(j + 1);
                return res;
            }
            else if(sum < target) {
                i++;
            }
            else {
                j--;
            }
        }
    }
};
