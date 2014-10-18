/* The random set contains unique elements */
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class RandomSet{
private:
    vector<int> array;
    map<int, int> mapping;

public:
    void insert(int val){
        if(mapping.find(val) != mapping.end())
            return;
        array.push_back(val);
        mapping[val] = array.size() - 1;
    }

    void remove(int val){
        if(mapping.find(val) == mapping.end())
            return;

        int target = mapping[val];
        mapping.erase(val);

        array[target] = array.back();
        array.pop_back();

    }

    int size(){
        return array.size();
    }

    int getRandom(){
        return array[rand() % array.size()];
    }

    void print(){
        int n = array.size();
        cout << "[";
        for(int i = 0; i < n; i++){
            cout << array[i];
            if(i != n - 1)
                cout << " ";
        }
        cout << "]";
        cout << endl;
    }
};

int main(){
    RandomSet rs;
    rs.print();

    rs.insert(1);
    rs.print();

    rs.insert(2);
    rs.print();

    rs.insert(2);
    rs.print();

    rs.insert(3);
    rs.print();

    rs.remove(1);
    rs.print();

    map<int, int> counter;
    for(int i = 0; i < 10000; i++){
        int val = rs.getRandom();
        counter[val]++;
    }

    for(map<int, int>::iterator it = counter.begin(); it != counter.end(); it++)
        cout << it->first << ":" << it->second << endl;

    return 0;
}
