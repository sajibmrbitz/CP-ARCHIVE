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
    ListNode* swapPairs(ListNode* head){
        if(head==nullptr || head->next==nullptr)    return head;

        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode*prev=dummy;

        while(prev->next!=nullptr && prev->next->next!=nullptr){
            ListNode* current=prev->next;
            ListNode* nextNode=prev->next->next;

            current->next=nextNode->next;
            nextNode->next=current;
            prev->next=nextNode;

            prev=current;
        }
        ListNode* newHead=dummy->next;
        delete dummy;
        return newHead;
    }
};
