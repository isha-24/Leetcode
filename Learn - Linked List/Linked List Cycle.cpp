/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* n=head;
        ListNode* p=NULL;
        if(head==NULL){
            return false;
        }
        while(true){
            p=n;
            n=n->next;
            if(n==NULL){
                return false;
            }
            if(n==n->next){
                return true;
            }
            p->next=p;
        }
    }
};
