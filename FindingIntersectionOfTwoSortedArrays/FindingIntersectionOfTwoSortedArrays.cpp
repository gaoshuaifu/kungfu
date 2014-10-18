/*
 * time: O(m + n), space: O(1)
 * time: O(mlogn), space: O(1)
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    vector<int> intersect(vector<int>& v1, vector<int>& v2){
        vector<int> res;
        int n1 = v1.size();
        int n2 = v2.size();
        int i = 0;
        int j = 0;
        while(i < n1 && j < n2){
            if(v1[i] < v2[j])
                i++;
            else if(v1[i] > v2[j])
                j++;
            else if(v1[i] == v2[j]){
                res.push_back(v1[i]);
                i++;
                j++;
            }
        }
        return res;
    }
};

int main(){
    int a1[] = {0, 1, 2, 3, 3, 6, 7, 9};    
    int a2[] = {1, 3, 4, 5, 7, 8};
    vector<int> v1(a1, a1 + sizeof(a1) / sizeof(a1[0]));
    vector<int> v2(a2, a2 + sizeof(a2) / sizeof(a2[0]));

    Solution solution;
    vector<int> res = solution.intersect(v1, v2);
    
    for(int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << "\n";
    
    return 0;
}