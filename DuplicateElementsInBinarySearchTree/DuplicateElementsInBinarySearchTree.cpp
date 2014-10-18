/*
 * time: O(n), space: O(1)
 */
#include <iostream>
#include <stack>
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

TreeNode* initialize(){
    TreeNode* node1 = new TreeNode(2);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(4);
    TreeNode* node4 = new TreeNode(1);
    TreeNode* node5 = new TreeNode(2);
    TreeNode* node6 = new TreeNode(3);
    TreeNode* node7 = new TreeNode(4);
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
    if(!root)
        return;

    print(root->left);
    cout << root->val << " ";
    print(root->right);
}

class Solution{
public:
    void countDuplicateHelper(TreeNode* curr, TreeNode*& prev, int& count){
        if(!curr) return;

        countDuplicateHelper(curr->left, prev, count);

        if(!prev)
            prev = curr;
        else{
            if(prev->val == curr->val)
                count++;
            prev = curr;
        }

        countDuplicateHelper(curr->right, prev, count);
    }

    int countDuplicate(TreeNode* root){
        int count = 0;
        TreeNode* prev = NULL;
        countDuplicateHelper(root, prev, count);
        return count;
    }
};

class Solution1{
public:
    int countDuplicate(TreeNode* root){
        int count = 0;
        stack<TreeNode*> stk;
        TreeNode* prev = NULL;
        TreeNode* curr = root;
        while(!stk.empty() || curr){
            if(curr){
                stk.push(curr);
                curr = curr->left;
            }
            else{
                curr = stk.top();
                stk.pop();

                if(!prev)
                    prev = curr;
                else{
                    if(prev->val == curr->val)
                        count++;
                    prev = curr;
                }

                curr = curr->right;
            }
        }
        return count;
    }
};

int main(){
    TreeNode* root = initialize();
    Solution solution;
    cout << solution.countDuplicate(root) << endl;
    print(root);
    cout << endl;
    return 0;
}
