/*
 * time: O(nlogn), space O(1)
 */
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct Interval{
	int start;
	int end;
	Interval(){
		this->start = 0;
		this->end = 0;
	}
	Interval(int s, int e){
		this->start = s;
		this->end = e;
	}
};

class Solution{
public:	
	struct LessThan{
		bool operator()(const Interval a, const Interval b){
			return a.start < b.start;	
		}
	};
	
	vector<Interval> merge(vector<Interval>& intervals){
		vector<Interval> res;
		int n = intervals.size();
		if(n == 0) return res;
			
		sort(intervals.begin(), intervals.end(), LessThan());
		
		Interval prev = intervals[0];
		for(int i = 1; i < n; i++){
			Interval curr = intervals[i];
			if(prev.end < curr.start){
				res.push_back(prev);
				prev = curr;
			}
			else
				prev.end = max(prev.end, curr.end);
		}
		res.push_back(prev);
		
		return res;
	}
};

int main(){
	vector<Interval> intervals;
	intervals.push_back(Interval(1, 3));
	intervals.push_back(Interval(8, 10));
	intervals.push_back(Interval(2, 6));
	intervals.push_back(Interval(15, 18));
	
	Solution solution;
	vector<Interval> res = solution.merge(intervals);
	
	for(int i = 0; i < res.size(); i++)
		cout << res[i].start << ", " << res[i].end << endl;
	
	return 0;
}

