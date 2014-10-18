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
        bool hasInserted = false;
        
        for(int i = 0; i < n; i++){
            Interval interval = intervals[i];
            
            if(interval.end < newInterval.start){
                res.push_back(interval);
                continue;
            }
            
            if(newInterval.end < interval.start){
                if(!hasInserted){
                    res.push_back(newInterval);
                    hasInserted = true;
                }
                res.push_back(interval);
                continue;
            }
            
            newInterval.start = min(newInterval.start, interval.start);
            newInterval.end = max(newInterval.end, interval.end);
        }
        
        if(hasInserted == false)
            res.push_back(newInterval);
        
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

