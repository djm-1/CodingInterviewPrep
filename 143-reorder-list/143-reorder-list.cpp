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
    
    ListNode *getMid(ListNode *head){
        ListNode *fast=head,*slow=head,*prev=NULL;
        while(fast!=NULL && fast->next!=NULL)
        {
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        prev->next=NULL;
        return slow;
    }
    void reorderList(ListNode* head) {
        if(head==NULL ||head->next==NULL || head->next->next==NULL)
            return;
        
        ListNode *right=getMid(head);
        
        ListNode *prev=NULL,*next=right,*end=NULL,*start=head;
        while(right!=NULL)
        {
            if(right->next==NULL)
            {
                end=right;
            }
            next=right->next;
            right->next=prev;
            prev=right;
            right=next;
        }
        
        ListNode *dummy=new ListNode();
        ListNode*temp=dummy;
        int count=0;
        while(start!=NULL && end!=NULL)
        {
            if(count%2==0)
            {
                temp->next=start;
                start=start->next;
            }
            else
            {
                temp->next=end;
                end=end->next;
            }
            count++;
            temp=temp->next;
        }
        
        if(start)
            temp->next=start;
        if(end)
            temp->next=end;
        
        return;
    }
};