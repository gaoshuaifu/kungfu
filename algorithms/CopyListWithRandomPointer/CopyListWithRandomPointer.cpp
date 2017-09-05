class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        map<RandomListNode*, RandomListNode*> m;
        for(RandomListNode* node = head; node; node = node->next) {
            m[node] = new RandomListNode(node->label);
        }
        for(RandomListNode* node = head; node; node = node->next) {
            m[node]->next = m[node->next];
            m[node]->random = m[node->random];
        }
        return m[head];
    }
};
