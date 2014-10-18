/*
 * time: O(n), space: O(1)
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
    void nextPermutation(vector<int>& num){
        int n = num.size();

        int i;
        for(i = n - 2; i >= 0; i--){
            if(num[i] < num[i + 1])
                break;
        }

        if(i < 0){
            reverse(num.begin(), num.end());
            return;
        }

        int j;
        for(j = n - 1; j > i; j--){
            if(num[j] > num[i])
                break;
        }

        swap(num[i], num[j]);
        reverse(num.begin() + i + 1, num.end());
    }
};


void print(vector<int>& num){
    for(int i = 0; i < num.size(); i++)
        cout << num[i] << " ";
    cout << endl;
}

int main(){
    int a[] = {1, 2, 3, 4};
    vector<int> num = vector<int>(a, a + sizeof(a) / sizeof(a[0]));
    print(num);


    Solution solution;

    for(int i = 0; i < 24; i++){
        solution.nextPermutation(num);
        print(num);
    }

    return 0;
}

