#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;

struct Node {
  int val;
  vector<Node*> neighbors;
  Node(int val){
    this->val = val;
  }
};

class Solution {
public:
  vector<Node*> traverse(Node* graph) {
    vector<Node*> res;
    if(!graph)
      return res;

    queue<Node*> q;
    set<Node*> visited;

    q.push(graph);
    visited.insert(graph);

    while(!q.empty()) {
      Node* node = q.front();
      q.pop();
      res.push_back(node);

      vector<Node*> neighbors = node->neighbors;
      for(int i = 0; i < neighbors.size(); i++) {
        if(visited.count(neighbors[i]) == 0) {
          q.push(neighbors[i]);
          visited.insert(neighbors[i]);
        }
      }
    }
    return res;
  }

  vector<Node*> shortestPath(Node* start, Node* end) {
    vector<Node*> path;
    if(!start || !end)
      return path;

    queue<Node*> q;
    set<Node*> visited;
    map<Node*, Node*> prevNode;

    q.push(start);
    visited.insert(start);
    prevNode[start] = NULL;

    while(!q.empty()) {
      Node* node = q.front();
      q.pop();

      if(node == end)
        break;

      vector<Node*> neighbors = node->neighbors;
      for(int i = 0; i < neighbors.size(); i++) {
        if(visited.count(neighbors[i]) == 0) {
          q.push(neighbors[i]);
          visited.insert(neighbors[i]);
          prevNode[neighbors[i]] = node;
        }
      }
    }

    if(prevNode.count(end) == 0)
      return path;

    path.push_back(end);
    while(true) {
      Node* prev = prevNode[path.back()];
      if(prev)
        path.push_back(prev);
      else
        break;
    }
    reverse(path.begin(), path.end());
    return path;
  }
};

int main() {
  Node* node1 = new Node(1);
  Node* node2 = new Node(2);
  Node* node3 = new Node(3);
  Node* node4 = new Node(4);
  node1->neighbors.push_back(node2);
  node1->neighbors.push_back(node3);
  node2->neighbors.push_back(node3);
  node2->neighbors.push_back(node4);
  node3->neighbors.push_back(node4);

  Solution solution;
  vector<Node*> traveral = solution.traverse(node1);
  for(int i = 0; i < traveral.size(); i++)
    cout << traveral[i]->val << " ";
  cout << endl;

  vector<Node*> path = solution.shortestPath(node1, node4);
  for(int i = 0; i < path.size(); i++)
    cout << path[i]->val << " ";
  cout << endl;

  return 0;
};
