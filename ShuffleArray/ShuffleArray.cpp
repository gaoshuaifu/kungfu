#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

// random num between 0 and n
int rand0toN(int n){
    if(n == 0) return 0;
    
    n++;
    int upper = RAND_MAX / n * n;
    int r;
    do{
        r = rand(); 
    } while(r >= upper);
    return r % n;
}


class Solution{
public:
    void shuffle(vector<int>& num){
        srand(time(NULL));
        int n = num.size();
        for(int i = n - 1; i >= 0; i--){
            int j = rand0toN(i);
            swap(num[i], num[j]);
        }
    }
};

int main(){
    vector<int> num;
    for(int i = 1; i <= 10; i++)
        num.push_back(i);
    
    Solution solution;
    solution.shuffle(num);
    
    for(int i = 0; i < num.size(); i++)
        cout << num[i] << " ";
    cout << endl;
    
    return 0;   
}
