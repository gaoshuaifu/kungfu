/*
 * time: O(logn), space: O(1)
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int searchLow(int A[], int n, int target){
		int low = 0;
		int high = n - 1;
		while(low <= high){
			int mid = low + (high - low) / 2;
			if(target <= A[mid])
				high = mid - 1;
			if(target > A[mid])
				low = mid + 1;
		}
		return low;
	}
	
	int searchHigh(int A[], int n, int target){
		int low = 0;
		int high = n - 1;
		while(low <= high){
			int mid = low + (high - low) / 2;
			if(target < A[mid])
				high = mid - 1;
			if(target >= A[mid])
				low = mid + 1;				
		}
		return high;
	}
	
    vector<int> searchRange(int A[], int n, int target) {
		vector<int> res(2, -1);
		int low = searchLow(A, n, target);
		int high = searchHigh(A, n, target);
		if(low > high)
			return res;
		else{
			res[0] = low;
			res[1] = high;
			return res;
		}
    }
};

int main(){
	int A[] = {1, 2, 5, 5, 6, 7, 7, 7, 8};
	int target = 5;
	
	Solution solution;
	vector<int> res = solution.searchRange(A, sizeof(A) / sizeof(A[0]), target);
	
	cout << "[" << res[0] << ", " << res[1] << "]" << endl;
	return 0;
}

