#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int findMagicIndex(vector<int>& num){
        int low = 0;
        int high = num.size() - 1;

        while(low <= high){
            int mid = low + (high - low) / 2;
            if(mid == num[mid])
                return mid;
            else if(mid > num[mid])
                low = mid + 1;
            else
                high = mid -1;
        }

        return -1;
    }
};

int main(){
    int array[] = {-2, -1, 1, 2, 4, 6, 8, 10};
    vector<int> num(array, array + sizeof(array) / sizeof(array[0]));

    Solution solution;
    int res = solution.findMagicIndex(num);
    cout << "index is " << res << ", value is " << num[res] << endl;

    return 0;
}
