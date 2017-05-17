/*
    If they are different, no point.
    else if they are the same and on the bottom level, a point is awarded.
    else if they are both 0 (same), and the LEFT CHILD GAME was guessed correctly, a point is awarded.
    else if they are both 1 (same), and the RIGHT CHILD GAME was guessed correctly, a point is awarded.

    left_child(i): 2 * i
    right_child(i): 2 * i + 1
    parent(i): i / 2
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int score63(int u[], int p[]) {
        int dp[64];
        int score = 0;
        for(int i = 63; i >= 1; i--) {
            if(u[i] != p[u]) {
                dp[i] = 0;
                continue;
            }

            if(i >= 32 || (u[i] == 0 && dp[2 * i]) || u[i] == 1 && dp[2 * i + 1]) {
                dp[i] = 1;
                score++;
            }
            else
                dp[i] = 0;
        }
    }
};
