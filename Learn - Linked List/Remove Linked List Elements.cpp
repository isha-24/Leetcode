/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        while(head!=NULL && head->val==val){
            head=head->next;
        }
        ListNode* a=head;
        ListNode* b=head;
        while(a!=NULL){
            if(a->val==val){
                b->next=a->next;
                a=b->next;
            }
            else
            {b=a;
            a=a->next;}
        }
        return head;
    }
};
