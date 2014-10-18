#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
    void rotate(vector<int>& numbers, int k){
        int n = numbers.size();
        if(n == 0) return;

        k = k % n;
        reverse(numbers.begin(), numbers.begin() + k);
        reverse(numbers.begin() + k, numbers.end());
        reverse(numbers.begin(), numbers.end());
    }
};

int main(){
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> numbers(array, array + sizeof(array) / sizeof(array[0]));

    Solution solution;
    solution.rotate(numbers, 4);

    for(int i = 0; i < numbers.size(); i++)
        cout << numbers[i] << " ";
    cout << endl;

    return 0;
};
