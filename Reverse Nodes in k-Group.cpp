//https://leetcode.com/problems/reverse-nodes-in-k-group/

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* t=head, *temp=NULL;
        ListNode* prev=NULL, *n=NULL;
        int c=0;
        int size=0;
        while(t!=NULL) size++, t=t->next;
        int times=size/k;
        ListNode* newHead=new ListNode();
        t=head; head=newHead;
        while(times--){
            c=k;
            temp=t;
            while(c--){
                n=t->next;
                t->next=prev;
                prev=t;
                t=n;
            }
            temp->next=t;
            newHead->next=prev;
            newHead=temp;
            prev=NULL;
        }
        return head->next;
    }
};
