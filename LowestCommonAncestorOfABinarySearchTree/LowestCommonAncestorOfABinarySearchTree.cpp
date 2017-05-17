/*
 * time: O(h), space: O(1)
 */
#include <iostream>
#include <cassert>
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

/*
        _______4______
         /                \
    ___2__            ___6__
     /        \        /        \
     1         3         5         7

*/
TreeNode* initialize(TreeNode*& root, TreeNode*& p, TreeNode*& q){
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

    root = node1;
    p = node4;
    q = node5;
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
    TreeNode* LCA(TreeNode* root, TreeNode* node1, TreeNode* node2){
        if(!root)
            return NULL;

        int low = min(node1->val, node2->val);
        int high = max(node1->val, node2->val);

        if(root->val >= low && root->val <= high)
            return root;
        else if(root->val > high)
            return LCA(root->left, node1, node2);
        else if(root->val < low)
            return LCA(root->right, node1, node2);
    }
};


int main(){
    TreeNode* root;
    TreeNode* p;
    TreeNode* q;
    initialize(root, p, q);
    Solution solution;
    TreeNode* lca = solution.LCA(root, p, q);
    cout << lca->val << endl;
    return 0;
}


