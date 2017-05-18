/* The random collection can contain duplicated elements */
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class RandomizedCollection{
private:
    vector<int> a;
    unordered_map<int, vector<int> > m;

public:
    /** Initialize your data structure here. */
    RandomizedCollection() {

    }

    /** Returns true if the collection did not already contain the specified element. */
    bool insert(int val){
        bool res = true;
        if(m.find(val) != m.end())
            res = false;
        a.push_back(val);
        m[val].push_back(a.size() - 1);
        return res;
    }

    /**  Returns true if the collection contained the specified element. */
    bool remove(int val){
        if(m.find(val) == m.end())
            return false;

        int index = m[val].back();
        a[index] = a.back();
        m[a.back()].back() = index;
        a.pop_back();
        m[val].pop_back();
        if(m[val].empty())
            m.erase(val);
        return true;
    }

    int count(int val){
        if(m.find(val) == m.end())
            return 0;
        else
            return m[val].size();
    }

    int size(){
        return a.size();
    }

    /** Get a random element from the collection. */
    int getRandom(){
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
        cout << "] ";

        cout << "{";
        for(unordered_map<int, vector<int> >::iterator it = m.begin(); it != m.end(); it++) {
            cout << it->first << ":";
            for(int i = 0; i < it->second.size(); i++) {
                cout << it->second[i] << ",";
            }
            cout << " ";
        }
        cout << "}";
        cout << endl;
    }
};

int main(){
    RandomizedCollection rs;
    rs.print();

    rs.insert(1);
    rs.print();
    rs.insert(1);
    rs.print();

    rs.insert(2);
    rs.print();
    rs.insert(2);
    rs.print();

    rs.insert(3);
    rs.print();
    rs.insert(3);
    rs.print();

    rs.remove(1);
    rs.print();
    rs.remove(1);
    rs.print();

    rs.remove(3);
    rs.print();
    rs.remove(3);
    rs.print();

    unordered_map<int, int> counter;
    for(int i = 0; i < 10000; i++){
        int val = rs.getRandom();
        counter[val]++;
    }

    for(unordered_map<int, int>::iterator it = counter.begin(); it != counter.end(); it++)
        cout << it->first << ":" << it->second << endl;


    return 0;
}
