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
    
    bool isPalindrome(ListNode* head) {
        if(head->next==NULL){
            return true;
        }
        ListNode* fast=head;
        ListNode* slow=head;
        ListNode* r=NULL;
        while(true){
            slow=slow->next;
            fast=fast->next->next;
            if(fast==NULL){           //even no. of nodes
                r=reverse(slow);
                break;
            }
            if(fast->next==NULL){     //odd no. of nodes
                r=reverse(slow->next);
                break;
            }
        }
        while(r!=NULL){
            if(r->val!=head->val){
                return false;
            }
            r=r->next;
            head=head->next;
        }
        return true;
    }
};
