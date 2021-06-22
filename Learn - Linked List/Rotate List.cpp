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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL){
            return head;
        }
        ListNode* h=head;
        int size=0;
        ListNode* ln;
        while(h){
            ln=h;
            h=h->next;
            size++;
        }
        k=k%size;
        if(k==0){
            return head;
        }
        h=head;
        ListNode* newLn=h;
        int x=size-k;
        while(x--){
            newLn=h;
            h=h->next;
        }
        ln->next=head;
        newLn->next=NULL;
        return h;
    }
};
