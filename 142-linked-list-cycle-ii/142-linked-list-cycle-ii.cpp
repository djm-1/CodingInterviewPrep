/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        bool cycle=false;
        if(head==NULL)
            return NULL;
        ListNode *fast=head,*slow=head;
        while(fast!=NULL && fast->next!=NULL && slow!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow)
            {
                cycle=true;
                break;
            }
        }
        if(!cycle)
            return NULL;
        
            //slow=slow->next;
            ListNode *junc=head;
            while(slow!=junc)
                slow=slow->next,junc=junc->next;
            return junc;
        
    }
};