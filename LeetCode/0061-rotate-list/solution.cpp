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
    ListNode* rotateRight(ListNode* head, int k){
        if(!head || k==0){
            return head;
        }
        int len=1;
        ListNode* tail=head;
        while(tail->next!=nullptr){
            len++;
            tail=tail->next;
        }
        k=k%len;
        if(k==0)    return head;
        tail->next=head;
        int ToNewTail=len-k;
        ListNode* newTail=head;
        for(int i=0;i<ToNewTail-1;i++){
            newTail=newTail->next;
        }
        ListNode*newHead=newTail->next;
        newTail->next=nullptr;

        return newHead;
    }
};
