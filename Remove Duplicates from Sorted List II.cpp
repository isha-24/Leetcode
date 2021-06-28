//https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* h=new ListNode();
        ListNode* newHead=h;
        ListNode* curr=head;
        while(curr){
            int flag=1;
            while(curr->next && curr->val==curr->next->val){
                curr=curr->next;
                flag=0;
            }
            if(flag){
                h->next=curr;
                h=h->next;
                curr=curr->next;
                h->next=NULL;
            }
            if(!flag && curr){
                curr=curr->next;
            }
        }
        return newHead->next;
    }
};
