#include <iostream>
#include <vector>
using namespace std;

// The number of offices
const int N = 4;

// The number of weeks
const int M = 5;

// Cannot fly more than 6 hours when switching offices
const int MAX_FLIGHT_TIME = 6;

struct SourceAndDays {
  int days;
  int source;
  SourceAndDays(int days, int source) {
    this->days = days;
    this->source = source;
  }
};

class Solution {
public:
  // weekOfficeVacations: a M x N matrix, weekOfficeVacations[i][j] is the number of vacation days in the week i at the office j;
  // distances: a N x N matrix, distances[i][j] is the hours spent travelling from the office i to the office j;
  vector<int> maximizeVacationDays(vector<vector<int> > weekOfficeVacations, vector<vector<int> > distances) {
    // A M x N matrix, dp[i][j] is the max total vacation days within the first i weeks ending up with office j
    vector<vector<SourceAndDays> > dp;

    // The first week
    vector<SourceAndDays> row;
    for(int j = 0; j < N; j++)
      row.push_back(SourceAndDays(weekOfficeVacations[0][j], -1));
    dp.push_back(row);

    // Following weeks
    for(int i = 1; i < M; i++) {
      vector<SourceAndDays> row;
      for(int j = 0; j < N; j++) {
        int maxDays = INT_MIN;
        int source;
        for(int k = 0; k < N; k++) {
          if(distances[k][j] <= MAX_FLIGHT_TIME) {
            // The total vacation days from office k to office j
            int days = dp[i - 1][k].days + weekOfficeVacations[i][j];
            if(days > maxDays) {
              maxDays = days;
              source = k;
            }
          }
        }
        row.push_back(SourceAndDays(maxDays, source));
      }
      dp.push_back(row);
    }

    int office;
    int maxDays = INT_MIN;
    for(int j = 0; j < N; j++) {
      int days = dp[M - 1][j].days;
      if(days > maxDays) {
        maxDays = days;
        office = j;
      }
    }

    vector<int> res;
    res.push_back(office);
    for(int i = M - 1; i > 0; i--) {
      office = dp[i][office].source;
      res.push_back(office);
    }
    reverse(res.begin(), res.end());
    return res;
  }
};

int main() {
  Solution solution;
  return 0;
}
