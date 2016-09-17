/*
 * time: O(nlogn), space: O(n)
 */
#include <iostream>
#include <vector>
using namespace std;

struct ListNode{
  int val;
  ListNode* next;
  ListNode(int val){
    this->val = val;
    this->next = NULL;
  }
};

ListNode* initializeList(int array[], int n){
  ListNode* head = NULL;
  ListNode* tail = NULL;

  for(int i = 0; i < n; i++){
    if(head == NULL){
      head = new ListNode(array[i]);
      tail = head;
    }
    else{
      tail->next = new ListNode(array[i]);
      tail = tail->next;
    }
  }
  return head;
}

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

void inorderTraverse(TreeNode* root, vector<int>& inorderRes){
  if(root == NULL)
    return;
  inorderTraverse(root->left, inorderRes);
  inorderRes.push_back(root->val);
  inorderTraverse(root->right, inorderRes);
}

void print(vector<int>& res){
  for(int i = 0; i < res.size(); i++)
    cout << res[i] << " ";
  cout << endl;
}

class Solution{
public:
  int getLength(ListNode* head){
    int len = 0;
    for(ListNode* p = head; p != NULL; p = p->next)
      len++;
    return len;
  }

  TreeNode* sortedListToBSTHelper(ListNode*& head, int low, int high){
    if(low > high)
      return NULL;

    int mid = (low + high) / 2;

    TreeNode* leftTree = sortedListToBSTHelper(head, low, mid - 1);

    TreeNode* root = new TreeNode(head->val);
    root->left = leftTree;
    head = head->next;

    TreeNode* rightTree = sortedListToBSTHelper(head, mid + 1, high);
    root->right = rightTree;

    return root;
  }

  TreeNode* sortedListToBST(ListNode* head){
    int n = getLength(head);
    return sortedListToBSTHelper(head, 0, n - 1);
  }
};

int main(){
  int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  ListNode* head = initializeList(array, sizeof(array) / sizeof(array[0]));

  Solution solution;
  TreeNode* root = solution.sortedListToBST(head);

  vector<int> inorderRes;
  inorderTraverse(root, inorderRes);
  print(inorderRes);

  return 0;
}

