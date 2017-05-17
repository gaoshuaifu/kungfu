#include <iostream>
#include <vector>
#include <stack>
#include <map>
using namespace std;

struct Record {
    string funcName;
    bool isEntering;
    int time;
    Record(string funcName, bool isEntering, int time) {
        this->funcName = funcName;
        this->isEntering = isEntering;
        this->time = time;
    }
};

struct ActiveRecord {
    string funcName;
    int time;
    ActiveRecord(string funcName, int time) {
        this->funcName = funcName;
        this->time = time;
    }
};

class Solution {
public:
    map<string, int> process(vector<Record>& log) {
        map<string, int> res;
        stack<ActiveRecord> stk;

        int lastTime = 0;
        for(int i = 0; i < log.size(); i++) {
            Record record = log[i];
            if(!stk.empty()) {
                stk.top().time += record.time - lastTime;
            }
            lastTime = record.time;

            if(record.isEntering) {
                stk.push(ActiveRecord(record.funcName, 0));
            }
            else {
                if (stk.empty()) {
                    throw "Malformed trace";
                }
                ActiveRecord activeRecord = stk.top();
                if(record.funcName != activeRecord.funcName) {
                    throw "Malformed trace";
                }
                res[activeRecord.funcName] += activeRecord.time;
                stk.pop();
            }
        }
        return res;
    }
};

int main() {
    vector<Record> log;
    log.push_back(Record("foo", true, 0));
    log.push_back(Record("bar", true, 1));
    log.push_back(Record("bar", false, 2));
    log.push_back(Record("bar", true, 3));
    log.push_back(Record("bar", false, 4));
    log.push_back(Record("foo", false, 5));

    Solution solution;
    map<string, int> res = solution.process(log);

    for(map<string, int>::iterator it = res.begin(); it != res.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }

    return 0;
}
