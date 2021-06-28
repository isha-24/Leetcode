//https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/

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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        unordered_map<int,ListNode*> sumNodes;
        ListNode* curr=dummy;
        int sum=0;
        
        while(curr){
            sum+=curr->val;
            sumNodes[sum]=curr;
            curr=curr->next;
        }
        
        sum=0;
        curr=dummy;
        while(curr){
            sum+=curr->val;
            ListNode* lastNodeSum=sumNodes[sum];
            if(curr!=lastNodeSum){
                curr->next=lastNodeSum->next;
            }
            curr=curr->next;
        }
        return dummy->next;
    }
};
