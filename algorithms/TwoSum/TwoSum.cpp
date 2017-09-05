/*
 * time: O(n), space: O(n)
 */
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        map<int, int> value2Index;
        for(int i = 0; i < numbers.size(); i++){
            if(value2Index.count(target - numbers[i])){
                return {value2Index[target - numbers[i]], i};
            }
            value2Index[numbers[i]] = i;
        }
        return {};
    }
};

int main(){
    int numbersArray[] = {2, 7, 5, 11};
    vector<int> numbers(numbersArray, numbersArray + sizeof(numbersArray) / sizeof(numbersArray[0]));
    int target = 9;

    Solution solution;
    vector<int> res = solution.twoSum(numbers, target);
    cout << res[0] << " " << res[1] << endl;

    return 0;
}
