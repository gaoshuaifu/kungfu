#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
    int partition(vector<int>& num, int low, int high){
        int pivot = num[low];
        int i = low + 1;
        int j = high;

        while(i <= j){
            while(i <= j && num[i] <= pivot)
                i++;
            while(i <= j && num[j] > pivot)
                j--;
            if(i <= j)
                swap(num[i], num[j]);
        }
        swap(num[low], num[j]);
        return j;
    }

    int selectHelper(vector<int>& num, int low, int high, int k){
        int mid = partition(num, low, high);
        int rank = mid - low + 1;

        if(k == rank)
            return num[mid];
        else if(k < rank)
            return selectHelper(num, low, mid - 1, k);
        else if(k > rank)
            return selectHelper(num, mid + 1, high, k - rank);
    }

    int select(vector<int>& num, int k){
        int n = num.size();
        return selectHelper(num, 0, n - 1, k);
    }

    int findKthLargest(vector<int>& num, int k){
      int n = num.size();
      return selectHelper(num, 0, n - 1, n + 1 - k);
    }

    int findKthSmallest(vector<int>& num, int k){
      int n = num.size();
      return selectHelper(num, 0, n - 1, k);
    }
};

int main(){
    int array[] = {5, 8, 7, 1, 3, 2, 6, 4};
    vector<int> num(array, array + sizeof(array) / sizeof(array[0]));

    Solution solution;
    for(int i = 1; i <= num.size(); i++){
        cout << i << " : " << solution.select(num, i) << "\n";
    }

    return 0;
}
