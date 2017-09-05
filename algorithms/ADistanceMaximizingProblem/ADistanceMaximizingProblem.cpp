/*
 * time: O(nlogn), space: O(n)
 */
#include <iostream>
#include <vector>
#include <map>
#include <climits>
using namespace std;

class Solution{
public:
    int maxDistance(vector<int>& numbers){
        int n = numbers.size();

        map<int, pair<int, int> > mapping;
        for(int i = 0; i < n; i++){
            int num = numbers[i];
            if(mapping.find(num) == mapping.end())
                mapping[num] = make_pair(i, i);
            else if(i < mapping[num].first)
                mapping[num].first = i;
            else if(i > mapping[num].second)
                mapping[num].second = i;
        }

        map<int, pair<int, int> >::iterator it = mapping.begin();
        int minIndex = (*it).second.first;
        int maxDist = INT_MIN;
        it++;
        while(it != mapping.end()){
            maxDist = max(maxDist, (*it).second.second - minIndex);
            minIndex = min(minIndex, (*it).second.first);
            it++;
        }

        return maxDist;
    }
};

int main(){
    int array[] = {4, 3, 5, 2, 1, 3, 2, 3};
    vector<int> numbers(array, array + sizeof(array) / sizeof(array[0]));

    Solution solution;
    cout << solution.maxDistance(numbers) << endl;

    return 0;
}
