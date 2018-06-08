#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
    void heapify(vector<int>& num, int n, int i) {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        // Find largest among root, left child and right child
        if(l < n && num[l] > num[largest]) {
            largest = l;
        }

        if(r < n && num[r] > num[largest]) {
            largest = r;
        }

        // Swap and continue heapifying if root is not largest
        if(largest != i) {
            swap(num[i], num[largest]);
            heapify(num, n, largest);
        }
    }

    void heapSort(vector<int>& num){
        int n = num.size();

        // Build a heap
        for(int i = n / 2 - 1; i >= 0; i--) {
          heapify(num, n, i);
        }

        // Heap sort
        for(int i = n - 1; i >= 0; i--) {
          swap(num[0], num[i]);
          heapify(num, i, 0);
        }
    }
};

int main(){
    int array[] = {5, 8, 7, 1, 3, 2, 6, 4};
    vector<int> num(array, array + sizeof(array) / sizeof(array[0]));

    Solution solution;
    solution.heapSort(num);

    for(int i = 0; i < num.size(); i++)
        cout << num[i] << " ";
    cout << endl;
    return 0;
}
