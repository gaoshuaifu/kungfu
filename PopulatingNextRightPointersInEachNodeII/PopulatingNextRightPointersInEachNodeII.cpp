/*
 * time: O(n), space: O(1)
 */
#include <iostream>
#include <queue>
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
    //TreeLinkNode* node6 = new TreeLinkNode(6);
    TreeLinkNode* node7 = new TreeLinkNode(7);
    node1->left = node2;
    node1->right = node3;
    //node2->left = node4;
    node2->right = node5;
    //node3->left = node6;
    node3->right = node7;
    TreeLinkNode* root = node1;
    return root;
}

void print(TreeLinkNode* root){
    TreeLinkNode* currentHead = root;
    while(currentHead != NULL){
        TreeLinkNode* nextHead = NULL;
        for(TreeLinkNode* p = currentHead; p != NULL; p = p->next){
            cout << p->val << " ";
            if(nextHead == NULL){
                if(p->left != NULL)
                    nextHead = p->left;
                else if(p->right != NULL)
                    nextHead = p->right;
            }
        }
        cout << endl;
        currentHead = nextHead;
    }
}

class Solution{
public:
    void connect(TreeLinkNode* root){
        if(root == NULL)
            return;

        queue<TreeLinkNode*> currQ;
        currQ.push(root);

        while(!currQ.empty()){
            queue<TreeLinkNode*> nextQ;
            while(!currQ.empty()){
                TreeLinkNode* node = currQ.front();
                currQ.pop();
                if(!currQ.empty())
                    node->next = currQ.front();
                if(node->left)
                    nextQ.push(node->left);
                if(node->right)
                    nextQ.push(node->right);
            }
            currQ = nextQ;
        }
    }
};

int main(){
    TreeLinkNode* root = initialize();
    Solution solution;
    solution.connect(root);
    print(root);
    return 0;
}
