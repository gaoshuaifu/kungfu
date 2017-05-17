/*
 * time: O(n)
 */
#include <iostream>
#include <stack>
using namespace std;

struct TreeLinkNode{
    int val;
    TreeLinkNode* left;
    TreeLinkNode* right;
    TreeLinkNode* next;
    TreeLinkNode(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
        this->next = NULL;
    }
};

TreeLinkNode* initialize(){
    TreeLinkNode* node1 = new TreeLinkNode(1);
    TreeLinkNode* node2 = new TreeLinkNode(2);
    TreeLinkNode* node3 = new TreeLinkNode(3);
    TreeLinkNode* node4 = new TreeLinkNode(4);
    TreeLinkNode* node5 = new TreeLinkNode(5);
    TreeLinkNode* node6 = new TreeLinkNode(6);
    TreeLinkNode* node7 = new TreeLinkNode(7);
    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->left = node6;
    node3->right = node7;
    TreeLinkNode* root = node1;
    return root;
}

void print(TreeLinkNode* root){
    TreeLinkNode* head = root;
    while(head != NULL){
        for(TreeLinkNode* p = head; p != NULL; p = p->next)
            cout << p->val << " ";
        cout << endl;
        head = head->left;
    }
}

class Solution{
public:
    void connect(TreeLinkNode* root){
        if(!root || !root->left || !root->left)
            return;

        root->left->next = root->right;

        if(root->next)
            root->right->next = root->next->left;
        else
            root->right->next = NULL;

        connect(root->left);
        connect(root->right);
    }
};

int main(){
    TreeLinkNode* root = initialize();
    Solution solution;
    solution.connect(root);
    print(root);

    return 0;
}

