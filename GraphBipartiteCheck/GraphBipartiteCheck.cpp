#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

struct Node {
  int val;
  vector<Node*> neighbors;
  Node(int val){
    this->val = val;
  }
};

vector<Node*> initialize(){
  Node* node1 = new Node(1);
  Node* node2 = new Node(2);
  Node* node3 = new Node(3);
  Node* node4 = new Node(4);
  Node* node5 = new Node(5);

  node1->neighbors.push_back(node5);
  node1->neighbors.push_back(node2);

  node2->neighbors.push_back(node1);
  node2->neighbors.push_back(node3);

  node3->neighbors.push_back(node2);
  node3->neighbors.push_back(node4);

  node4->neighbors.push_back(node3);
  node4->neighbors.push_back(node5);

  node5->neighbors.push_back(node4);
  node5->neighbors.push_back(node1);

  vector<Node*> graph;
  graph.push_back(node1);
  graph.push_back(node2);
  graph.push_back(node3);
  graph.push_back(node4);
  graph.push_back(node5);

  return graph;
}

const int BLACK = 0;
const int WHITE = 1;

class Solution {
public:
  bool bipartiteCheck(vector<Node*>& graph) {
    int n = graph.size();
    if(n == 0) return true;

    queue<Node*> q;
    map<Node*, int> nodeColors;

    q.push(graph[0]);
    nodeColors[graph[0]] = BLACK;

    while(!q.empty()){
      Node* node = q.front();
      q.pop();

      vector<Node*> neighbors = node->neighbors;
      for(int i = 0; i < neighbors.size(); i++) {
        if(nodeColors.count(neighbors[i]) == 0) {
          q.push(neighbors[i]);
          nodeColors[neighbors[i]] = 1 - nodeColors[node];
        }
        else if(nodeColors[neighbors[i]] == nodeColors[node])
          return false;
      }
    }
    return true;
  }
};

int main(){
  vector<Node*> graph = initialize();
  Solution solution;
  cout << solution.bipartiteCheck(graph) << endl;
  return 0;
}
