/*
 * time: O(n), space: O(n)
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Interval{
  int start;
  int end;
  Interval(){
    this->start = 0;
    this->end = 0;
  }
  Interval(int start, int end){
    this->start = start;
    this->end = end;
  }
};

class Solution{
public:
  vector<Interval> insert(vector<Interval>& intervals, Interval newInterval){
    vector<Interval> res;
    int n = intervals.size();
    int i = 0;

    while(i < n && intervals[i].end < newInterval.start) {
        res.push_back(intervals[i]);
        i++;
    }

    while(i < n && intervals[i].start <= newInterval.end) {
        newInterval.start = min(intervals[i].start, newInterval.start);
        newInterval.end = max(intervals[i].end, newInterval.end);
        i++;
    }
    res.push_back(newInterval);

    while(i < n) {
        res.push_back(intervals[i]);
        i++;
    }

    return res;
  }
};

int main(){
  vector<Interval> intervals;
  intervals.push_back(Interval(1, 5));
  intervals.push_back(Interval(6, 8));
  Interval newInterval(0, 9);

  Solution solution;
  vector<Interval> res = solution.insert(intervals, newInterval);

  for(int i = 0; i < res.size(); i++)
    cout << res[i].start << ", " << res[i].end << endl;
  cout << endl;

  return 0;
}
