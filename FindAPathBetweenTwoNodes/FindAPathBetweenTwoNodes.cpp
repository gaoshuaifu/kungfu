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

void initialize(Node*& node1, Node*& node4){
    node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    node4 = new Node(4);
    
    node1->neighbors.push_back(node2);
    node1->neighbors.push_back(node3);
    
    node2->neighbors.push_back(node3);
    node2->neighbors.push_back(node4);
    
    node4->neighbors.push_back(node3);
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
    bool existPathHelper(Node* src, Node* dest, map<Node*, bool>& visited){
        if(src == dest)
            return true;
        visited[src] = true;
        
        for(int i = 0; i < src->neighbors.size(); i++){
            Node* neighbor = src->neighbors[i];
            if(visited.find(neighbor) == visited.end() && existPathHelper(neighbor, dest, visited))
                return true;
        }
        return false;
    }
    
    bool existPath(Node* src, Node* dest){
        map<Node*, bool> visited;
        return existPathHelper(src, dest, visited);
    }
};

class Solution1{
public:
    bool existPathHelper(Node* src, Node* dest, map<Node*, bool>& visited){
        for(int i = 0; i < src->neighbors.size(); i++){
            Node* neighbor = src->neighbors[i];
            if(visited.find(neighbor) == visited.end()){
                if(neighbor == dest)
                    return true;
                visited[neighbor] = true;
                if(existPathHelper(neighbor, dest, visited))
                    return true;
            }
        }
        return false;
    }
    
    bool existPath(Node* src, Node* dest){
        map<Node*, bool> visited;
        if(src == dest)
            return true;
        visited[src] = true;
        return existPathHelper(src, dest, visited);
    }
};

class Solution2{
public: 
    bool existPath(Node* src, Node* dest){
        map<Node*, bool> visited;
        queue<Node*> q;
        visited[src] = true;
        q.push(src);

        while(!q.empty()){
            Node* node = q.front();
            q.pop();
            
            if(node == dest)
                return true;
            
            for(int i = 0; i < node->neighbors.size(); i++){
                Node* neighbor = node->neighbors[i];
                if(visited.find(neighbor) == visited.end()){
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        return false;
    }
};

class Solution3{
public: 
    bool existPath(Node* src, Node* dest){
        map<Node*, bool> visited;
        queue<Node*> q;
        
        if(src == dest)
            return true;
        visited[src] = true;
        q.push(src);
        
        while(!q.empty()){
            Node* curr = q.front();
            q.pop();
            
            for(int i = 0; i < curr->neighbors.size(); i++){
                Node* neighbor = curr->neighbors[i];
                if(visited.find(neighbor) == visited.end()){
                    if(neighbor == dest)
                        return true;
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
        return false;
    }
};

int main(){
    Node* node1;
    Node* node4;
    initialize(node1, node4);
    
    Solution1 solution;
    
    cout << "tranverse from node1: ";
    traverse(node1);
    cout << "exist a path from node1 to node4? ";
    cout << solution.existPath(node1, node4);
    cout << "\n";
    
    cout << "tranverse from node4: ";
    traverse(node4);
    cout << "exist a path from node4 to node1? ";
    cout << solution.existPath(node4, node1);   
    cout << "\n";
    
    return 0;   
}