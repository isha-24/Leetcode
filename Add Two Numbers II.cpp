//https://leetcode.com/problems/add-two-numbers-ii/submissions/

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
    pair<ListNode*,int> Lreverse(ListNode* head){
        ListNode* prv=NULL, *nxt=NULL; int l=0;
        while(head){
            nxt=head->next;
            head->next=prv;
            prv=head;
            head=nxt;
            l++;
        }
        return make_pair(prv,l);
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL){
            return l2;
        }
        if(l2==NULL){
            return l1;
        }
        auto p1=Lreverse(l1);
        l1=p1.first; int n1=p1.second;
        auto p2=Lreverse(l2);
        l2=p2.first; int n2=p2.second;
        int carry=0;
        int mx=max(n1,n2);
        int n=mx-abs(n1-n2);
        ListNode* head=NULL;
        while(n--){
            ListNode* n=new ListNode((l1->val+l2->val+carry)%10);
            carry=(l1->val+l2->val+carry)/10;
            l1=l1->next;
            l2=l2->next;
            n->next=head;
            head=n;
        }
        if(n2>n1){
            l1=l2;
        }
        while(l1!=NULL){
            ListNode* n=new ListNode((l1->val+carry)%10);
            carry=(l1->val+carry)/10;
            l1=l1->next;
            n->next=head;
            head=n;
        }
        while(carry>0){
            ListNode* n=new ListNode(carry%10);
            n->next=head;
            head=n;
            carry=carry/10;
        }
        return head;
    }
};
