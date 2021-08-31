//https://leetcode.com/problems/merge-in-between-linked-lists/

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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2)  {
        ListNode* first=list1;
        ListNode* last=list1;
        ListNode *temp=NULL;
        ListNode* q=list2;
        while(q->next!=NULL)
        {
            q=q->next;
        }
        int x=a-1;
        int y=b+1;
        while(x || y)
        {
            if(x!=0)
            {
                first=first->next;
                x--;
            }
            if(y!=0)
            {
                temp=last;
                last=last->next;
                y--;
            }
        }
        first->next=list2;
        q->next=last;
        temp->next=NULL;
        return list1;
        
    }
};
