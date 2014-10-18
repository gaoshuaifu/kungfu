#include <iostream>
using namespace std;

class Solution{
public: 
    int numOfOnes(unsigned int x){
        int count = 0;
        while(x != 0){
            count++;
            x = x & (x - 1);
        }
        return count;
    }
};

class Solution1{
public:
    int numOfOnes(unsigned int x){  
        int count = 0;
        for(int i = 0; i < 32; i++){
            if(x & (1 << i))
                count++;
        }
        return count;
    }
};

int main(){
    Solution solution;
    
    unsigned int x = 0xF0F0F0F0;
    int res = solution.numOfOnes(x);
    cout << res << endl;
    
    return 0;
}