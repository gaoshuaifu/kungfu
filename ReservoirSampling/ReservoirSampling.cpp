#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
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
    ListNode* p = NULL;
    
    for(int i = 0; i < n; i++){
        if(head == NULL){
            head = new ListNode(array[i]);
            p = head;
        }   
        else{
            p->next = new ListNode(array[i]);
            p = p->next;
        }
    }
    return head;
}

void print(ListNode* head){
    for(ListNode* p = head; p != NULL; p = p->next)
        cout << p->val << " ";
    cout << endl;
}

// random number between 1 and n
int rand1toN(int n){
    int upper = RAND_MAX / n * n;
    int r;
    do{
        r = rand(); 
    } while(r >= upper);
    return r % n + 1;
}

class Solution{
public:    
    vector<int> sample(ListNode* head, int k){
        vector<int> res;
        
        ListNode* curr = head;
        
        int i;
        for(i = 1; i <= k; i++){
            res.push_back(curr->val);
            curr = curr->next;
        }
        
        srand(time(NULL));
        while(curr){
            int r = rand1toN(i);    
            if(r <= k)
                res[r - 1] = curr->val;
            curr = curr->next;
            i++;
        }
        
        return res;
    }
};

int main(){
    int array[100];
    for(int i = 1; i <= 100; i++)
        array[i] = i;
    
    ListNode* head = initializeList(array, sizeof(array) / sizeof(array[0]));

    Solution solution;
    vector<int> res = solution.sample(head, 10);
    for(int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << endl;
    return 0;
}
