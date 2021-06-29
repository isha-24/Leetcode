//https://leetcode.com/problems/next-greater-node-in-linked-list/

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
    ListNode* reverseL(ListNode* head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* n=reverseL(head->next);
        head->next->next=head;
        head->next=NULL;
        return n;
    }
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode* temp=head;
        ListNode* h=reverseL(head);
        vector<int> res; stack<int> st;
        
        while(h){
            while(!st.empty() && st.top()<=h->val)
                st.pop();
            if(st.empty())
                res.push_back(0);
            else
                res.push_back(st.top());
            st.push(h->val);
            h=h->next;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
