/*
 * time: O(E + V), space: O(1)
 */
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

Node* initialize(){
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    
    node1->neighbors.push_back(node2);
    node1->neighbors.push_back(node3);
    
    node2->neighbors.push_back(node3);
    node2->neighbors.push_back(node4);
    
    node3->neighbors.push_back(node4);
    return node1;
}

void traverseHelper(Node* node, map<Node*, bool>& visited, vector<Node*>& res){
    res.push_back(node);
    visited[node] = true;
    
    for(int i = 0; i < node->neighbors.size(); i++){
        if(visited.find(node->neighbors[i]) == visited.end())
            traverseHelper(node->neighbors[i], visited, res);
    }
}

void traverse(Node* graph){
    vector<Node*> res;
    map<Node*, bool> visited;
    traverseHelper(graph, visited, res);
    for(int i = 0; i < res.size(); i++)
        cout << res[i]->val << " ";
    cout << "\n";
}

class Solution{
public:
    Node* cloneGraphHelper(Node* node, map<Node*, Node*>& mapping){
        if(mapping[node])
            return mapping[node];
        
        Node* newNode = new Node(node->val);
        mapping[node] = newNode;
        
        for(int i = 0; i < node->neighbors.size(); i++)
            newNode->neighbors.push_back(cloneGraphHelper(node->neighbors[i], mapping));
        
        return newNode;
    }
    
    Node* cloneGraph(Node* graph){
        if(!graph) return NULL;
        map<Node*, Node*> mapping;
        Node* newGraph = cloneGraphHelper(graph, mapping);
        return newGraph;
    }       
};

class Solution1{
public:
    Node* cloneGraphHelper(Node* node, map<Node*, Node*>& mapping){
        Node* newNode = new Node(node->val);
        mapping[node] = newNode;
        
        for(int i = 0; i < node->neighbors.size(); i++){
            Node* neighbor = node->neighbors[i];
            if(mapping[neighbor])
                newNode->neighbors.push_back(mapping[neighbor]);
            else
                newNode->neighbors.push_back(cloneGraphHelper(neighbor, mapping));
        }
        return newNode;
    }
    
    Node* cloneGraph(Node* graph){
        if(!graph) return NULL;
        map<Node*, Node*> mapping;
        Node* newGraph = cloneGraphHelper(graph, mapping);
        return newGraph;
    }       
};

class Solution2{
public:
    Node* cloneGraph(Node* graph){
        if(!graph) return NULL;
        
        Node* newGraph = new Node(graph->val);
        
        map<Node*, Node*> mapping;
        queue<Node*> q;
        
        mapping[graph] = newGraph;
        q.push(graph);
        
        while(!q.empty()){
            Node* node = q.front();
            q.pop();
            
            for(int i = 0; i < node->neighbors.size(); i++){
                Node* neighbor = node->neighbors[i];
                if(mapping[neighbor])
                    mapping[node]->neighbors.push_back(mapping[neighbor]);
                else{
                    Node* newNeighbor = new Node(neighbor->val);
                    mapping[node]->neighbors.push_back(newNeighbor);
                    mapping[neighbor] = newNeighbor;
                    q.push(neighbor);
                }
            }
        }
        return newGraph;
    }       
};

int main(){
    Node* graph = initialize();
    traverse(graph);
    
    Solution solution;
    Node* newGraph = solution.cloneGraph(graph);
    traverse(newGraph);
    
    Solution1 solution1;
    Node* newGraph1 = solution1.cloneGraph(graph);
    traverse(newGraph1);
    
    Solution2 solution2;
    Node* newGraph2 = solution2.cloneGraph(graph);
    traverse(newGraph2);
    
    return 0;   
}