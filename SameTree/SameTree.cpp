/*
 * time: O(n), space: O(1)
 */
#include <iostream>
#include <queue>
#include <climits>
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

TreeNode* initialize1(){
    TreeNode* node1 = new TreeNode(4);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(6);
    TreeNode* node4 = new TreeNode(1);
    TreeNode* node5 = new TreeNode(3);
    TreeNode* node6 = new TreeNode(5);
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

TreeNode* initialize2(){
    TreeNode* node1 = new TreeNode(4);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(6);
    TreeNode* node4 = new TreeNode(1);
    TreeNode* node5 = new TreeNode(3);
    TreeNode* node6 = new TreeNode(5);
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

void print(TreeNode* root){
    if(root == NULL)
        return;
    
    print(root->left);
    cout << root->val << endl;
    print(root->right);
}

class Solution{
public:
    bool isSameTree(TreeNode* root1, TreeNode* root2){
        if(!root1 && !root2)
            return true;
            
        if((root1 && !root2) || (!root1 && root2) || (root1->val != root2->val))
            return false;
        
        return isSameTree(root1->left, root2->left) && isSameTree(root1->right, root2->right);
    }
};

class Solution1{
public:
    bool isSameTree(TreeNode* root1, TreeNode* root2){
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        q1.push(root1);
        q2.push(root2);
        
        while(!q1.empty() && !q2.empty()){
            TreeNode* node1 = q1.front();
            TreeNode* node2 = q2.front();
            q1.pop();
            q2.pop();
            if(!node1 && !node2)
                continue;
            if((node1 && !node2) || (!node1 && node2) || (node1->val != node2->val))
                return false;
            q1.push(node1->left);
            q1.push(node1->right);
            q2.push(node2->left);
            q2.push(node2->right);
        }
        
        return q1.empty() && q2.empty();
    }
};

int main(){
    TreeNode* root1 = initialize1();
    TreeNode* root2 = initialize2();
    Solution1 solution;
    bool res = solution.isSameTree(root1, root2);
    cout << res << endl;
    return 0;
}

