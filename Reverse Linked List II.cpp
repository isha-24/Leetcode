//https://leetcode.com/problems/reverse-linked-list-ii/

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int c=1;
        ListNode* h=head;
        ListNode* p=new ListNode();
        ListNode* prev=p;
        ListNode* mark=head;
        int flag=1;
        ListNode* m=head;
        // return head;
        
        while(flag && h){
            if(c==left){
                m=h;
                flag=0;
                while(c!=right+1){
                    ListNode* n=h->next;
                    h->next=prev;
                    prev=h;
                    h=n;
                    c++;
                }
                continue;
            }
            mark=h;
            h=h->next;
            c++;
        }
        m->next=h;
        if(left==1)
            return prev;
        mark->next=prev;
        return head;
    }
};
