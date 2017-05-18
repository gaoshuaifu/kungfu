/* The random set contains unique elements */
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {

    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(m.find(val) != m.end())
            return false;
        a.push_back(val);
        m[val] = a.size() - 1;
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(m.find(val) == m.end())
            return false;

        int index = m[val];
        a[index] = a.back();
        m[a.back()] = index;
        a.pop_back();
        m.erase(val);
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        return a[rand() % a.size()];
    }

    void print(){
        int n = a.size();
        cout << "[";
        for(int i = 0; i < n; i++){
            cout << a[i];
            if(i != n - 1)
                cout << " ";
        }
        cout << "]";
        cout << endl;
    }

private:
    vector<int> a;
    map<int, int> m;
};

int main(){
    RandomizedSet rs;
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
