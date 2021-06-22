/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp=head;
        while(temp){
            Node* n=new Node(temp->val);
            n->next=temp->next;
            temp->next=n;
            temp=temp->next->next;
        }
        temp=head;
        while(temp){
            if(temp->random){
                temp->next->random=temp->random->next;
            }
            temp=temp->next->next;
        }
        temp=head;
        Node* newHead=new Node(0);
        Node* h=newHead;
        while(temp){
            Node* r=temp->next->next;
            Node* c=temp->next;
            temp->next=r;
            h->next=c;
            temp=temp->next;
            h=h->next;
        }
        return newHead->next;
    }
};
