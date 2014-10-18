#include <iostream>
#include <map>
#include <cstdlib>
#include <ctime>
using namespace std;

int rand7(){
    int upper = RAND_MAX / 7 * 7;
    int r;
    do{
        r = rand(); 
    } while(r >= upper);
    return r % 7 + 1;
}


class Solution{
public:
    int rand10(){   
        int row, col, index;
        do{
            row = rand7();
            col = rand7();
            index = (row - 1) * 7 + col;
        } while(index > 40);
        return (index - 1) % 10 + 1;
    }
};

int main(){
    Solution solution;
    map<int, int> mapping;
    
    srand(time(NULL));
    for(int i = 0; i < 10000000; i++)
        mapping[solution.rand10()]++;
    
    for(map<int, int>::iterator it = mapping.begin(); it != mapping.end(); it++)
        cout << it->first << " " << it->second << "\n";
    
    return 0;   
}

