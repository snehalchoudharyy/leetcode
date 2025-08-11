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
        ListNode* fast=head;
         //first move the fast pointer to the n steps from the head then start both slow(at the head) and fast one step simultaneously such that when the fast reaches at the last node slow will be N steps behind that is it will be at N-l node  
        for(int i=0;i<n;i++){
            fast=fast->next;     
        }
        ListNode* slow=head;
        ListNode* newHead=NULL;
        if(fast==NULL){
            return newHead= head->next;
            delete(head);
        }
        while (fast->next!=NULL){
            slow=slow->next;
            fast=fast->next;
        }
        
        
        ListNode* delNode=slow->next;
        slow->next=slow->next->next;
        delete(delNode);
        return head;
    }
};