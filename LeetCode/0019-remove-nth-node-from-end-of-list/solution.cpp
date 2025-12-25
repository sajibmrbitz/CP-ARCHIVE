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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        int len=0;
        ListNode* current=head;
        while(current!=nullptr){
            len++;
            current=current->next;
        }

        int idx=len-n;

        if(idx==0){
            ListNode* temp=head;
            head=head->next;
            delete temp;
            return head;
        }

        current=head;
        for(int i=0;i<idx-1;i++){
            current=current->next;
        }

        ListNode* nodeToDelete=current->next;
        current->next=nodeToDelete->next;
        delete nodeToDelete;

        return head;
    }
};
