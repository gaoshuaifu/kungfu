/*
 * time: O(h), space: O(1)
 */
#include <iostream>
#include <cassert>
#include <map>
using namespace std;

struct TreeNode{
    int val;
    TreeNode * parent;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val){
        this->val = val;
        this->parent = NULL;
        this->left = NULL;
        this->right = NULL;
    }
};

/*
        _______3______
       /              \
    ___5__          ___1__
   /      \        /      \
   6      _2       0       8
         /  \
         7   4

*/
void initialize(TreeNode*& root, TreeNode*& p, TreeNode*& q){
    TreeNode* node0 = new TreeNode(0);
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node5 = new TreeNode(5);
    TreeNode* node6 = new TreeNode(6);
    TreeNode* node7 = new TreeNode(7);
    TreeNode* node8 = new TreeNode(8);
    node3->left = node5;
    node3->right = node1;

    node5->parent = node3;
    node5->left = node6;
    node5->right = node2;

    node1->parent = node3;
    node1->left = node0;
    node1->right = node8;

    node6->parent = node5;

    node2->parent = node5;
    node2->left = node7;
    node2->right = node4;

    node0->parent = node1;
    node8->parent = node1;

    node7->parent = node2;
    node4->parent = node2;

    root = node3;
    p = node6;
    q = node4;
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
    int getDepth(TreeNode* node){
        int d = 0;
        while(node){
            node = node->parent;
            d++;
        }
        return d;
    }

    TreeNode* LCA(TreeNode* root, TreeNode* node1, TreeNode* node2){
        if(!root || !node1 || !node2)
            return NULL;

        int d1 = getDepth(node1);
        int d2 = getDepth(node2);

        TreeNode* low;
        TreeNode* high;
        int diff;
        if(d1 > d2){
            low = node1;
            high = node2;
            diff = d1 - d2;
        }
        else{
            low = node2;
            high = node1;
            diff = d2 - d1;
        }

        while(diff > 0){
            low = low->parent;
            diff--;
        }

        while(low != high){
            low = low->parent;
            high = high->parent;
        }
        return low;
    }
};

class Solution1{
public:
    TreeNode* LCA(TreeNode* root, TreeNode* node1, TreeNode* node2){
        if(!root)
            return NULL;

        if(!node1 || !node2)
            return node1? node1 : node2;

        map<TreeNode*, bool> visited;
        while(node1 || node2){
            if(node1){
                if(visited.find(node1) != visited.end())
                    return node1;
                visited[node1] = true;
                node1 = node1->parent;
            }
            if(node2){
                if(visited.find(node2) != visited.end())
                    return node2;
                visited[node2] = true;
                node2 = node2->parent;
            }
        }
        return NULL;
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

