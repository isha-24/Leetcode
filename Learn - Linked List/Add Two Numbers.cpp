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
    int Lsize(ListNode* l){
        int n=0;
        ListNode* t=l;
        while(t!=NULL){
            n++;
            t=t->next;
        }
        return n;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL){
            return l2;
        }
        if(l2==NULL){
            return l1;
        }
        ListNode* head=new ListNode();
        ListNode* h=head;
        int n1=Lsize(l1);
        int n2=Lsize(l2);
        int carry=0;
        int mx=max(n1,n2);
        int n=mx-abs(n1-n2);
        while(n--){
            ListNode* n=new ListNode((l1->val+l2->val+carry)%10);
            carry=(l1->val+l2->val+carry)/10;
            l1=l1->next;
            l2=l2->next;
            h->next=n;
            h=h->next;
        }
        if(n2>n1){
            l1=l2;
        }
        while(l1!=NULL){
            ListNode* n=new ListNode((l1->val+carry)%10);
            carry=(l1->val+carry)/10;
            l1=l1->next;
            h->next=n;
            h=h->next;
        }
        while(carry>0){
            ListNode* n=new ListNode(carry%10);
            h->next=n;
            h=h->next;
            carry=carry/10;
        }
        return head->next;
    }
};
