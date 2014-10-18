/*
 * time: O(n), space: O(height)
 */
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
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
    TreeNode* node6 = new TreeNode(6);
    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node3->left = node6;
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
    string int2str(int val){
        ostringstream oss;
        oss << val;
        return oss.str();
    }

    int str2int(string str){
        istringstream iss(str);
        int val;
        iss >> val;
        return val;
    }

    vector<string> serialize(TreeNode* root){
        vector<string> tokens;

        if(!root){
            tokens.push_back("#");
            return tokens;
        }

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            if(node){
                tokens.push_back(int2str(node->val));
                q.push(node->left);
                q.push(node->right);
            }
            else
                tokens.push_back("#");
        }

        int i = tokens.size() - 1;
        while(tokens[i] == "#"){
            tokens.pop_back();
            i--;
        }

        return tokens;
    }


    TreeNode* deserialize(vector<string> tokens){
        if(tokens.size() == 1 && tokens[0] == "#")
            return NULL;

        int n = tokens.size();

        queue<TreeNode*> q;
        TreeNode* root = new TreeNode(str2int(tokens[0]));
        q.push(root);
        int left = 1;
        int right = 2;
        while(true){
            TreeNode* node = q.front();
            q.pop();

            if(left >= n)
                break;
            if(tokens[left] != "#"){
                node->left = new TreeNode(str2int(tokens[left]));
                q.push(node->left);
            }

            if(right >= n)
                break;
            if(tokens[right] != "#"){
                node->right = new TreeNode(str2int(tokens[right]));
                q.push(node->right);
            }

            left += 2;
            right += 2;
        }
        return root;
    }
};


class Solution1{
public:
    string int2str(int val){
        ostringstream oss;
        oss << val;
        return oss.str();
    }

    int str2int(string str){
        istringstream iss(str);
        int val;
        iss >> val;
        return val;
    }

    void serializeHelper(TreeNode* root, vector<string>& tokens){
        if(!root){
            tokens.push_back("#");
            return;
        }

        tokens.push_back(int2str(root->val));
        serializeHelper(root->left, tokens);
        serializeHelper(root->right, tokens);
    }

    vector<string> serialize(TreeNode* root){
        vector<string> tokens;
        serializeHelper(root, tokens);
        return tokens;
    }

    TreeNode* deserializeHelper(vector<string>& tokens, int& index){
        if(tokens[index] == "#")
            return NULL;

        TreeNode* root = new TreeNode(str2int(tokens[index]));
        index++;
        root->left = deserializeHelper(tokens, index);
        index++;
        root->right = deserializeHelper(tokens, index);

        return root;
    }

    TreeNode* deserialize(vector<string> tokens){
        int index = 0;
        TreeNode* root = deserializeHelper(tokens, index);
        return root;
    }
};

int main(){
    TreeNode* root = initialize();

    cout << "## Solution ##" << endl;
    Solution solution;
    vector<string> tokens = solution.serialize(root);
    for(int i = 0; i < tokens.size(); i++)
        cout << tokens[i] << " ";
    cout << endl;

    TreeNode* newRoot = solution.deserialize(tokens);
    cout << "isSameTree: " << isSameTree(root, newRoot) << endl;


    cout << "\n## Solution1 ##" << endl;
    Solution1 solution1;

    vector<string> tokens1 = solution1.serialize(root);
    for(int i = 0; i < tokens1.size(); i++)
        cout << tokens1[i] << " ";
    cout << endl;

    TreeNode* newRoot1 = solution1.deserialize(tokens1);
    cout << "isSameTree: " << isSameTree(root, newRoot1) << endl;

    return 0;
}



