#include <iostream>
using namespace std;

class Solution {
    void drawCircle(x0, y0, r) {
        for(int i = 0; i < 45; i++) {
            double rx = r * cos(i);
            double ry = r * sin(i);
            plot(x + rx, y + ry);
            plot(x + rx, y - ry);
            plot(x - rx, y + ry);
            plot(x - rx, y - ry);
            plot(x + ry, y + rx);
            plot(x + ry, y - rx);
            plot(x - ry, y + rx);
            plot(x - ry, y - rx);
        }
    }
}

int main() {
    return 0;
}
