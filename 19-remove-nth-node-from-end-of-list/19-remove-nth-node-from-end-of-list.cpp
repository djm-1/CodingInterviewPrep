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
        ListNode *dummy=new ListNode(-1,head);
        ListNode *slow=dummy, *fast=dummy;
        if(dummy->next==NULL)
            return NULL;
        while(n--)
        {
            fast=fast->next;
        }
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next;
        }
        
        ListNode *curr=slow->next;
        slow->next=slow->next->next;
        delete(curr);
        return dummy->next;
    }
};