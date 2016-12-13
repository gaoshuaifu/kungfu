#include <iostream>
#include <vector>
using namespace std;

struct Interval {
  int start;
  int end;
  Interval(int s, int e) {
    start = s;
    end = e;
  }
};

class Solution {
public:
  int minMeetingRooms(vector<Interval>& meetings) {
    int n = meetings.size();
    vector<int> starts;
    vector<int> ends;
    for(int i = 0; i < n; i++) {
      starts.push_back(meetings[i].start);
      ends.push_back(meetings[i].end);
    }
    sort(starts.begin(), starts.end());
    sort(ends.begin(), ends.end());

    int minRooms = 0;
    int rooms = 0;
    int i = 0;
    int j = 0;
    while(i < starts.size()) {
      if(starts[i] < ends[j]) {
        rooms++;
        minRooms = max(rooms, minRooms);
        i++;
      }
      else if(starts[i] > ends[j]) {
        rooms--;
        j++;
      }
      else if(starts[i] == ends[j]) {
        i++;
        j++;
      }
    }

    return minRooms;
  }
};

int main(){
  Solution solution;
  return 0;
}
