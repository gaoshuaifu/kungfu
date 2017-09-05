class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // Get the top two numbers with highest frequency
        int count1 = 0;
        int count2 = 0;
        int num1;
        int num2;
        for(auto num: nums){
            if (num1 == num){
                count1++;
            }
            else if (num2 == num){
                count2++;
            }
            else if (count1 == 0){
                num1 = num;
                count1 = 1;
            }
            else if (count2 == 0){
                num2 = num;
                count2 = 1;
            }
            else{
                count1--;
                count2--;
            }
        }

        // Count the frequency of those two numbers
        count1 = 0;
        count2 = 0;
        for(auto num: nums){
            if (num == num1) {
                count1++;
            }
            else if (num == num2) {
                count2++;
            }
        }

        // Check if their frequency > n/3
        vector<int> res;
        if (count1 > nums.size() / 3)
          res.push_back(num1);
        if (count2 > nums.size() / 3)
          res.push_back(num2);

        return res;
    }
};
