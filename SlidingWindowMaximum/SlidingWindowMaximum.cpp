#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <cassert>
using namespace std;

class Solution {
public:
  vector<int> maxSlidingWindow(vector<int> num, int w){
    vector<int> res;
    int n = num.size();

    if(n == 0) return res;
    if(w == 1) return num;

    deque<int> q;
    for(int i = 0; i < w; i++){
      while(!q.empty() && num[q.back()] <= num[i])
        q.pop_back();
      q.push_back(i);
    }
    res.push_back(num[q.front()]);

    for(int i = w; i < n; i++){
      if(!q.empty() && q.front() == i - w)
        q.pop_front();
      while(!q.empty() && num[q.back()] <= num[i])
        q.pop_back();
      q.push_back(i);
      res.push_back(num[q.front()]);
    }

    return res;
  }
};

class Solution1 {
public:
  vector<int> maxSlidingWindow(vector<int> num, int w){
    vector<int> res;
    int n = num.size();

    if(n == 0) return res;
    if(w == 1) return num;

    priority_queue<pair<int, int>, vector<pair<int, int> > > maxHeap;
    for(int i = 0; i < w; i++)
      maxHeap.push(make_pair(num[i], i));
    res.push_back(maxHeap.top().first);

    for(int i = w; i < n; i++){
      while(maxHeap.top().second <= i - w)
        maxHeap.pop();
      maxHeap.push(make_pair(num[i], i));
      res.push_back(maxHeap.top().first);
    }
    return res;
  }
};


int main(){
  int array[] = {1, 3, -1, -3, 5, 3, 6, 7};
  vector<int> num(array, array + sizeof(array) / sizeof(array[0]));
  vector<int> res;

  Solution solution;
  res = solution.maxSlidingWindow(num, 3);
  for(int i = 0; i < res.size(); i++)
    cout << res[i] << " ";
  cout << "\n";

  res = solution.minSlidingWindow(num, 3);
  for(int i = 0; i < res.size(); i++)
    cout << res[i] << " ";
  cout << "\n";


  Solution1 solution1;
  res = solution1.maxSlidingWindow(num, 3);
  for(int i = 0; i < res.size(); i++)
    cout << res[i] << " ";
  cout << "\n";

  res = solution1.minSlidingWindow(num, 3);
  for(int i = 0; i < res.size(); i++)
    cout << res[i] << " ";
  cout << "\n";

  return 0;
}
