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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return head;
        else
        {
            ListNode *curr=head->next,*prev=head;
            while(curr!=NULL)
            {
                if(curr->val==prev->val)
                {
                    prev->next=curr->next;
                    ListNode *temp=curr;
                    curr=curr->next;
                    delete(temp);
                }
                else
                {
                    prev=prev->next;
                    curr=curr->next;    
                }
                
            }
            return head;
        }
    }
};