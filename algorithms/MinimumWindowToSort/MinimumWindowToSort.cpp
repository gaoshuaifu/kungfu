#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution{
public:
    pair<int, int> minimumWindow(vector<int>& num){
        pair<int, int> res;
        int n = num.size();

        int low;
        for(int i = 1; i < n; i++){
            if(num[i - 1] <= num[i])
                continue;
            else{
                low = i;
                break;
            }
        }

        int high;
        for(int i = n - 2; i >= 0; i--){
            if(num[i] <= num[i + 1])
                continue;
            else{
                high = i;
                break;
            }
        }

        int minVal = num[low];
        for(int i = low; i < n; i++)
            minVal = min(minVal, num[i]);

        int maxVal = num[high];
        for(int i = high; i >= 0; i--)
            maxVal = max(maxVal, num[i]);

        for(int i = 0; i < n; i++){
            if(num[i] > minVal){
                res.first = i;
                break;
            }
        }

        for(int i = n - 1; i >= 0; i--){
            if(num[i] < maxVal){
                res.second = i;
                break;
            }
        }

        return res;
    }
};

int main(){
    int array[] = {1, 2, 4, 7, 10, 11, 7, 12, 6, 7, 16, 18, 19};
    vector<int> num(array, array + sizeof(array) / sizeof(array[0]));

    Solution solution;
    pair<int, int> res = solution.minimumWindow(num);
    int low = res.first;
    int high = res.second;
    cout << low << " " << high << "\n";
    sort(num.begin() + low, num.begin() + high + 1);
    for(int i = 0; i < num.size(); i++)
        cout << num[i] << " ";
    cout << "\n";
    return 0;
}
