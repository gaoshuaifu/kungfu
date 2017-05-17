/*
 * time: O(n), space: O(height)
 */
#include <iostream>
#include <sstream>
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

bool isSameTree(TreeNode* root1, TreeNode* root2){
    if(!root1 && !root2)
        return true;

    if((root1 && !root2) || (!root1 && root2))
        return false;

    return (root1->val == root2->val) && isSameTree(root1->left, root2->left) && isSameTree(root1->right, root2->right);
}


class Solution{
public:
    vector<int> serialize(TreeNode* root){
        vector<int> tokens;
        stack<TreeNode*> stk;
        TreeNode* curr = root;
        while(!stk.empty() || curr){
            if(curr){
                tokens.push_back(curr->val);
                stk.push(curr);
                curr = curr->left;
            }
            else{
                curr = stk.top();
                stk.pop();
                curr = curr->right;
            }
        }
        return tokens;
    }

    TreeNode* deserialize(vector<int> tokens){
        if(tokens.size() == 0)
            return NULL;

        TreeNode* root = new TreeNode(tokens[0]);

        for(int i = 1; i < tokens.size(); i++){
            int val = tokens[i];
            TreeNode* curr = root;
            while(true){
                if(val < curr->val){
                    if(curr->left)
                        curr = curr->left;
                    else{
                        curr->left = new TreeNode(val);
                        break;
                    }
                }
                else if(val > curr->val){
                    if(curr->right)
                        curr = curr->right;
                    else{
                        curr->right = new TreeNode(val);
                        break;
                    }
                }
            }
        }
        return root;
    }
};

class Solution1{
public:
    void serializeHelper(TreeNode* root, vector<int>& tokens){
        if(!root)
            return;

        tokens.push_back(root->val);
        serializeHelper(root->left, tokens);
        serializeHelper(root->right, tokens);
    }

    vector<int> serialize(TreeNode* root){
        vector<int> tokens;
        serializeHelper(root, tokens);
        return tokens;
    }

    void deserializeHelper(int min, int max, vector<int>& tokens, int& index, TreeNode*& root){
        if(index == tokens.size())
            return;

        int val = tokens[index];
        if(val > min && val < max){
            root = new TreeNode(val);
            index++;
            deserializeHelper(min, val, tokens, index, root->left);
            deserializeHelper(val, max, tokens, index, root->right);
        }
    }

    TreeNode* deserialize(vector<int> tokens){
        int index = 0;
        TreeNode* root;
        deserializeHelper(INT_MIN, INT_MAX, tokens, index, root);
        return root;
    }
};

int main(){
    TreeNode* root = initialize();

    Solution solution;
    vector<int> tokens = solution.serialize(root);
    for(int i = 0; i < tokens.size(); i++)
        cout << tokens[i] << " ";
    cout << endl;

    TreeNode* newRoot = solution.deserialize(tokens);
    cout << "isSameTree: " << isSameTree(root, newRoot) << endl;

    return 0;
}


