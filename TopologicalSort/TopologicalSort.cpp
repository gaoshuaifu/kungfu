#include <iostream>
#include <vector>
#include <set>
#include <stack>
using namespace std;

struct Node {
    int val;
    vector<Node*> neighbors;
    Node(int val){
        this->val = val;
    }
};

vector<Node*> initialize() {
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    node1->neighbors.push_back(node2);
    node1->neighbors.push_back(node3);
    node2->neighbors.push_back(node3);
    node2->neighbors.push_back(node4);
    node4->neighbors.push_back(node3);

    vector<Node*> nodes;
    nodes.push_back(node1);
    nodes.push_back(node2);
    nodes.push_back(node3);
    nodes.push_back(node4);
    return nodes;
}

class Solution {
public:
    void topologicalSortHelper(Node* node, set<Node*>& visited, stack<Node*>& stk) {
        if(visited.count(node) > 0)
            return;
        visited.insert(node);

        for(int i = 0; i < node->neighbors.size(); i++) {
            topologicalSortHelper(node->neighbors[i], visited, stk);
        }

        stk.push(node);
    }

    vector<Node*> topologicalSort(vector<Node*> nodes) {
        vector<Node*> res;
        stack<Node*> stk;
        set<Node*> visited;

        for(int i = 0; i < nodes.size(); i++) {
            topologicalSortHelper(nodes[i], visited, stk);
        }

        while(!stk.empty()) {
            res.push_back(stk.top());
            stk.pop();
        }
        return res;
    }
};

int main() {
    vector<Node*> nodes = initialize();
    Solution solution;
    vector<Node*> res = solution.topologicalSort(nodes);
    for(int i = 0; i < res.size(); i++) {
        cout << res[i]->val << " ";
    }
    cout << endl;
    return 0;
}
