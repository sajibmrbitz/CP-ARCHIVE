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
        if(!head)    return nullptr;

        Node* current=head;

        while(current!=nullptr){
            if(current->child){
                Node* nextNode=current->next;
                Node* childNode =current->child;
                current->next=childNode;
                childNode->prev=current;

                Node* childTail=childNode;
                while(childTail->next!=nullptr){
                    childTail=childTail->next;
                }
                childTail->next=nextNode;
                if(nextNode)    nextNode->prev=childTail;

                current->child=nullptr;
            }

            current=current->next;
        }
        return head;
    }
};
