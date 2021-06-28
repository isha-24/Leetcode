//https://leetcode.com/problems/partition-list/

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
    ListNode* partition(ListNode* head, int x) {
        ListNode* first=new ListNode();
        ListNode* f=first;
        ListNode* second=new ListNode();
        ListNode* s=second;
        ListNode* node;
        
        for(ListNode* h=head; h; h=node){
            node=h->next;
            if(h->val < x){
                first->next=h;
                first=first->next;
            }
            else{
                second->next=h;
                second=second->next;
                second->next=NULL;
            }
        }
        first->next=s->next;
        return f->next;
    }
};
