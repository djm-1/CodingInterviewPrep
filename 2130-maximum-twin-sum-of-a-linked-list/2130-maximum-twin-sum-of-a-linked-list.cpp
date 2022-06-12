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
    int pairSum(ListNode* head) {
        
        ListNode *slow=head, *fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        
        ListNode *prev=slow,*curr=slow->next,*next=curr,*end=NULL;
        while(curr!=NULL)
        {
            if(curr->next==NULL)
            {
                end=curr;
            }
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        slow->next=NULL;
        ListNode *start=head;
        int sum=0;
        while(start!=NULL)
        {
            sum=max(sum,start->val+end->val);
            start=start->next;
            end=end->next;
        }
        return sum;
    }
};