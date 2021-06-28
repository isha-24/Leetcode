//https://leetcode.com/problems/reorder-list/

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
    ListNode* reverse(ListNode* head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* n=reverse(head->next);
        head->next->next=head;
        head->next=NULL;
        return n;
    }
    void reorderList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return;
        }
        ListNode* fast=head;
        ListNode* slow=head;
        ListNode* prev=NULL;
        while(fast && fast->next){
            fast=fast->next->next;
            prev=slow;
            slow=slow->next;
        }
        prev->next=NULL;
        slow=reverse(slow);
        fast=head;
        ListNode* ans=new ListNode();
        ListNode* a=ans;
        while(fast && slow){
            ans->next=fast; ans=ans->next;
            fast=fast->next; 
            ans->next=slow; ans=ans->next;
            slow=slow->next;
        }
        if(slow && ans)
            ans->next=slow;
        head=a->next;
        return;
    }
};
