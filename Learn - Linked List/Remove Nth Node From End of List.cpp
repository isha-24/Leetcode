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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* a=head;
        ListNode* b=head;
        ListNode* temp=head;
        int i=1;
        while(i!=n){
            a=a->next;
            i++;
        }
        while(a->next!=NULL){
            temp=b;
            b=b->next;
            a=a->next;
        }
        if(b==head){
            head=head->next;
            return head;
        }
        temp->next=b->next;
        return head;
    }
};
