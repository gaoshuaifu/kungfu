/*
 * time: O(n)
 */
#include <iostream>
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

void printHead2Tail(TreeNode* head){
    TreeNode* p;
    for(p = head; p->right != head; p = p->right)
        cout << p->val << " ";
    cout << p->val << "\n";
}

void printTail2Head(TreeNode* head){
    TreeNode* p;
    for(p = head->left; p != head; p = p->left)
        cout << p->val << " ";
    cout << p->val << "\n";
}

class Solution{
public:
    TreeNode* connect(TreeNode* root){
        TreeNode* tmp = new TreeNode(INT_MIN);
        TreeNode* tail = tmp;

        stack<TreeNode*> stk;
        TreeNode* curr = root;
        while(!stk.empty() || curr){
            if(curr){
                stk.push(curr);
                curr = curr->left;
            }
            else{
                curr = stk.top();
                stk.pop();

                tail->right = curr;
                curr->left = tail;
                tail = curr;

                curr = curr->right;
            }
        }

        TreeNode* head = tmp->right;
        head->left = tail;
        tail->right = head;
        delete tmp;
        return head;
    }
};

class Solution1{
public:
    void connectHelper(TreeNode* root, TreeNode*& tail){
        if(!root) return;
        connectHelper(root->left, tail);

        tail->right = root;
        root->left = tail;
        tail = root;

        connectHelper(root->right, tail);
    }

    TreeNode* connect(TreeNode* root){
        TreeNode* tmp = new TreeNode(INT_MIN);
        TreeNode* tail = tmp;
        connectHelper(root, tail);

        TreeNode* head = tmp->right;
        head->left = tail;
        tail->right = head;
        delete tmp;
        return head;
    }
};

int main(){
    TreeNode* root = initialize();
    Solution solution;
    TreeNode* head = solution.connect(root);
    printHead2Tail(head);
    printTail2Head(head);
    return 0;
}
