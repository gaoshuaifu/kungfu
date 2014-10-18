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
}

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
    TreeNode* buildTreeHelper(vector<int>::iterator inorder, vector<int>::iterator postorder, int size){
        if(size == 0)
            return NULL;

        int rootVal = *(postorder + size - 1);
        TreeNode* root = new TreeNode(rootVal);

        vector<int>::iterator rootPos = find(inorder, inorder + size, rootVal);
        int sizeLeft = rootPos - inorder;
        int sizeRight = size - 1 - sizeLeft;

        root->left = buildTreeHelper(inorder, postorder, sizeLeft);
        root->right = buildTreeHelper(inorder + sizeLeft + 1, postorder + sizeLeft, sizeRight);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder){
        assert(inorder.size() == postorder.size());
        int size = inorder.size();
        TreeNode* root = buildTreeHelper(inorder.begin(), postorder.begin(), size);
        return root;
    }
};

int main(){
    TreeNode* rootBefore = initialize();

    vector<int> inorderResBefore;
    inorderTraverse(rootBefore, inorderResBefore);
    print(inorderResBefore);

    vector<int> postorderResBefore;
    postorderTraverse(rootBefore, postorderResBefore);
    print(postorderResBefore);

    Solution solution;
    TreeNode* rootAfter = solution.buildTree(inorderResBefore, postorderResBefore);

    vector<int> inorderResAfter;
    inorderTraverse(rootAfter, inorderResAfter);
    print(inorderResAfter);

    vector<int> postorderResAfter;
    postorderTraverse(rootAfter, postorderResAfter);
    print(postorderResAfter);

    return 0;
}

