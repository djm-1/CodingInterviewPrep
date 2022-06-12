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
    ListNode* findMid(ListNode *head){
        
        ListNode *slow=head, *fast=head, *pre=NULL;
        while(fast!=NULL && fast->next!=NULL)
        {
            pre=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        pre->next=NULL;
        return slow;
    }
    
    ListNode *mergeList(ListNode *left, ListNode *right){
        
        ListNode *dummy=new ListNode();
        ListNode *temp=dummy;
        while(left!=NULL && right!=NULL)
        {
            if(right->val<left->val)
            {
                temp->next=right;
                right=right->next;
            }
            else
            {
                temp->next=left;
                left=left->next;
            }
            temp=temp->next;
        }
        
        if(left!=NULL)
        {
            temp->next=left;
            //left=left->next;
        }
        
        if(right!=NULL)
        {
            temp->next=right;
            //right=right->next;
        }
        
        return dummy->next;
    }
    
    ListNode* sortList(ListNode* head) {
        
        if(head==NULL || head->next==NULL)
            return head;
        ListNode *left=head;
        ListNode *right=findMid(head);
        
        
        left=sortList(left);
        right=sortList(right);
        return mergeList(left,right);
    }
};