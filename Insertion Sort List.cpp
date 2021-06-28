//https://leetcode.com/problems/insertion-sort-list/

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
    ListNode* insertionSortList(ListNode* head) {
        ListNode*  prev=head;
        ListNode* p=NULL;
        for(ListNode* h=head->next;h;h=h->next){
            if(h->val>=prev->val){
                prev=h;
                continue;
            }
            ListNode* curr=h;
            prev->next=curr->next;
            ListNode* temp=head;
            while(temp && temp!=curr && temp->val<curr->val){
                p=temp;
                temp=temp->next;
            }
            if(temp==head){
                curr->next=head;
                head=curr;
            }
            else{
                p->next=curr;
                curr->next=temp;
            }
            h=prev;
            if(!h)
                break;
        }
        return head;
    }
};
