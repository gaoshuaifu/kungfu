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

    void quickSortHelper(vector<int>& num, int low, int high){
        if(low >= high)
            return;
        int mid = partition(num, low, high);
        quickSortHelper(num, low, mid - 1);
        quickSortHelper(num, mid + 1, high);
    }

    void quickSort(vector<int>& num){
        int n = num.size();
        quickSortHelper(num, 0, n - 1);
    }
};

int main(){
    int array[] = {5, 8, 7, 1, 3, 2, 6, 4};
    vector<int> num(array, array + sizeof(array) / sizeof(array[0]));

    Solution solution;
    solution.quickSort(num);

    for(int i = 0; i < num.size(); i++)
        cout << num[i] << " ";
    cout << endl;
    return 0;
}
