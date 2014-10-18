#include <iostream>
using namespace std;

class Solution{
public:
    void swap(int& a, int& b){  
        int n = 8 * sizeof(int);
        for(int i = 0; i < n; i++){
            if((a & (1 << i)) ^ (b & (1 << i))){
                a = a ^ (1 << i);
                b = b ^ (1 << i);
            }
        }
    }
};

class Solution1{
public:
    void swap(int& a, int& b){  
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }
};


class Solution2{
public:
    void swap(int& a, int& b){  
        a = a - b;
        b = a + b;
        a = b - a;
    }
};


int main(){
    int a = 1;
    int b = 2;

    Solution2 solution;
    solution.swap(a, b);
    cout << a << " " << b << endl;

    return 0;   
}