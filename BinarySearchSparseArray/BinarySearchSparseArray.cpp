#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
	int binarySearch(vector<string> strs, string target){
		int low = 0;
		int high = strs.size() - 1;
		
		while(low <= high){
			int mid = low + (high - low) / 2;
			
			if(strs[mid] == ""){
				int left = mid - 1;
				int right = mid + 1;
				while(left >= low || right <= high){
					if(left >= low){
						if(strs[left] == "")
							left--;						
						else{
							mid = left;
							break;
						}
					}
					
					if(right <= high){
						if(strs[right] == "")
							right++;						
						else{
							mid = right;
							break;
						}
					}
				}	
			}
			if(strs[mid] == "")
				return -1;
			else if(strs[mid] == target)
				return mid;
			else if(strs[mid] > target)
				high = mid - 1;
			else if(strs[mid] < target)
				low = mid + 1;
		}
		
		return -1;
	}
};

int main(){
	vector<string> strs;
	strs.push_back("at");
	strs.push_back("");
	strs.push_back("");
	strs.push_back("");
	strs.push_back("ball");
	strs.push_back("");
	strs.push_back("");
	strs.push_back("car");
	strs.push_back("");
	strs.push_back("");
	strs.push_back("dad");
	strs.push_back("");
	strs.push_back("");
	
	Solution solution;
	int res = solution.binarySearch(strs, "bus");
	
	if(res < 0)
		cout << "NULL" << "\n";
	else
		cout << strs[res] << "\n";
	
	return 0;
}