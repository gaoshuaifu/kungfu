#include <iostream>
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

class BinarySearchTree{
private:
    TreeNode* root;
    
    void inorder(TreeNode* curr){
        if(!curr)
            return;
        inorder(curr->left);
        cout << curr->val << " ";
        inorder(curr->right);       
    }
    
public:
    BinarySearchTree(){
        root = NULL;    
    }
    
    bool insert(int value){
        if(!root){
            root = new TreeNode(value);
            return true;
        }
        
        TreeNode* curr = root;
        while(true){
            if(root->val == value)
                return false;
            
            if(curr->val > value){
                if(!curr->left){
                    curr->left = new TreeNode(value);
                    return true;
                }
                else
                    curr = curr->left;
            }
            else if(curr->val < value){
                if(!curr->right){
                    curr->right = new TreeNode(value);
                    return true;
                }
                else
                    curr = curr->right;
            }
        }
    }
    
    void print(){
        inorder(root);  
    }
};

int main(){
    BinarySearchTree bst;

    cout << bst.insert(4) << "\n";
    bst.print();
    cout << "\n";
    
    cout << bst.insert(2) << "\n";
    bst.print();
    cout << "\n";
    
    return 0;
}