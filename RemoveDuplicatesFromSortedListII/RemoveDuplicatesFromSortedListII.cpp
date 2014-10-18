/*
 * time: O(n), space: O(1)
 */
#include <iostream>
#include <climits>
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


class Solution{
public:
    ListNode* deleteDuplicates(ListNode* head){
        ListNode* tmp = new ListNode(INT_MIN);
        tmp->next = head;
        ListNode* prev = tmp;
        ListNode* curr = head;

        while(curr){
            ListNode* post = curr->next;
            bool isDup = false;
            while(post && curr->val == post->val){
                curr->next = post->next;
                delete post;
                post = curr->next;
                isDup = true;
            }
            if(isDup){
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            }
            else{
                prev = prev->next;
                curr = curr->next;
            }
        }

        head = tmp->next;
        delete tmp;
        return head;
    }
};

class Solution1{
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if(!head) return NULL;
        ListNode* tmp = new ListNode(INT_MIN);
        tmp->next = head;
        ListNode* prev = tmp;
        ListNode* curr = head;
        ListNode* post = head->next;
        bool isDup = false;

        while(post){
            if(curr->val == post->val){
                curr->next = post->next;
                delete post;
                post = curr->next;
                isDup = true;
            }
            else{
                if(!isDup){
                    prev = prev->next;
                    curr = curr->next;
                    post = post->next;
                }
                else{
                    prev->next = curr->next;
                    delete curr;
                    curr = prev->next;
                    post = curr->next;
                    isDup = false;
                }

            }
        }

        if(isDup){
            prev->next = NULL;
            delete curr;
        }

        head = tmp->next;
        delete tmp;
        return head;
    }
};


int main(){
    int array[] = {1, 1, 2, 3, 3, 4};
    ListNode* list = initializeList(array, sizeof(array) / sizeof(array[0]));
    print(list);
    Solution solution;
    ListNode* res = solution.deleteDuplicates(list);
    print(res);
    return 0;
}

