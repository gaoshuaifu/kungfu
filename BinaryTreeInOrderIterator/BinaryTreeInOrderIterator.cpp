/*
 * time: O(n), space O(hight)
 */
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

TreeNode* initialize(){
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node5 = new TreeNode(5);
    TreeNode* node6 = new TreeNode(6);
    TreeNode* node7 = new TreeNode(7);
    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->left = node6;
    node3->right = node7;
    TreeNode* root = node1;
    return root;
}

class BinaryTreeInOrderIterator{
private:
    stack<TreeNode*> stk;

    void reachLeftMost(TreeNode* node){
        while(node){
            stk.push(node);
            node = node->left;
        }
    }

public:
    BinaryTreeInOrderIterator(TreeNode* root){
        reachLeftMost(root);
    }

    bool hasNext(){
        return !stk.empty();
    }

    TreeNode* next(){
        if(!hasNext())
            return NULL;

        TreeNode* node = stk.top();
        stk.pop();
        reachLeftMost(node->right);
        return node;
    }
};

int main(){
    TreeNode* root = initialize();

    BinaryTreeInOrderIterator it(root);

    while(it.hasNext())
        cout << it.next()->val << " ";
    cout << endl;

    return 0;
}
