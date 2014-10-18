#include <iostream>
#include <vector>
using namespace std;

class Node{
public:
    virtual void traverse() = 0;
};

class Leaf: public Node{
private:
    int val;
public:
    Leaf(int val){
        this->val = val;
    }
    void traverse(){
        cout << val << " ";
    }
};

class Composite: public Node{
private:
    vector<Node*> kids;
public:
    void add(Node* node){
        kids.push_back(node);
    }
    void traverse(){
        for(int i = 0; i < kids.size(); i++)
            kids[i]->traverse();
    }
};

int main(){
    Leaf* node1 = new Leaf(1);

    Composite* node2 = new Composite();
    node2->add(new Leaf(2));
    node2->add(new Leaf(3));

    Composite* root = new Composite();
    root->add(node1);
    root->add(node2);

    root->traverse();
    cout << "\n";

    return 0;
}

