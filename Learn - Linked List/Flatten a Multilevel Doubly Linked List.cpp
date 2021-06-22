/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node* h=head;
        while(head!=NULL){
            if(head->child!=NULL){
                Node* x=head->next;
                head->next=head->child;
                head->next->prev=head;
                head->child=NULL;
                Node* y=head->next;
                while(y->next!=NULL){
                    y=y->next;
                }
                y->next=x;
                if(x!=NULL){
                    x->prev=y;
                }
            }
            head=head->next;
        }
        return h;
    }
};
