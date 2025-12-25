class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head){
        ListNode* dummy=new ListNode(0,head);
        ListNode* prev=dummy; // always holds the last unique node

        while(head!=nullptr){
            if (head->next!=nullptr && head->val==head->next->val){
                while(head->next!=nullptr && head->val==head->next->val){
                    head=head->next;
                }
                
                // head points to the last duplicate
                prev->next = head->next;
            } 
            else {
                prev=prev->next;
            }
            head = head->next;
        }
        return dummy->next;
    }
};
