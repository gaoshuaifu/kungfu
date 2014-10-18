/*
 * time: O(n), space: O(n)
 */
#include <iostream>
#include <vector>
#include <algorithm>
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
    TreeNode* root = node1;;
    return root;
};

void preorderTraverse(TreeNode* root, vector<int>& preorderRes){
    if(root == NULL)
        return;
    preorderRes.push_back(root->val);
    preorderTraverse(root->left, preorderRes);
    preorderTraverse(root->right, preorderRes);
}

void inorderTraverse(TreeNode* root, vector<int>& inorderRes){
    if(root == NULL)
        return;
    inorderTraverse(root->left, inorderRes);
    inorderRes.push_back(root->val);
    inorderTraverse(root->right, inorderRes);
}

void postorderTraverse(TreeNode* root, vector<int>& postorderRes){
    if(root == NULL)
        return;
    postorderTraverse(root->left, postorderRes);
    postorderTraverse(root->right, postorderRes);
    postorderRes.push_back(root->val);
}


void print(vector<int>& res){
    for(int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << endl;
}


class Solution{
public:
    TreeNode* buildTreeHelper(vector<int>::iterator preorder, vector<int>::iterator inorder, int size){
        if(size == 0)
            return NULL;

        int rootVal = *preorder;
        TreeNode* root = new TreeNode(rootVal);

        vector<int>::iterator rootPos = find(inorder, inorder + size, rootVal);
        int sizeLeft = rootPos - inorder;
        int sizeRight = size - 1 - sizeLeft;

        root->left = buildTreeHelper(preorder + 1, inorder, sizeLeft);
        root->right = buildTreeHelper(preorder + 1 + sizeLeft, inorder + sizeLeft + 1, sizeRight);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder){
        assert(preorder.size() == inorder.size());
        int size = preorder.size();
        TreeNode* root = buildTreeHelper(preorder.begin(), inorder.begin(), size);
        return root;
    }
};

int main(){
    TreeNode* rootBefore = initialize();

    vector<int> preorderResBefore;
    preorderTraverse(rootBefore, preorderResBefore);
    print(preorderResBefore);

    vector<int> inorderResBefore;
    inorderTraverse(rootBefore, inorderResBefore);
    print(inorderResBefore);

    Solution solution;
    TreeNode* rootAfter = solution.buildTree(preorderResBefore, inorderResBefore);

    vector<int> preorderResAfter;
    preorderTraverse(rootAfter, preorderResAfter);
    print(preorderResAfter);

    vector<int> inorderResAfter;
    inorderTraverse(rootAfter, inorderResAfter);
    print(inorderResAfter);

    return 0;
}

