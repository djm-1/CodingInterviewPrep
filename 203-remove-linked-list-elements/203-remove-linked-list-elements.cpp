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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy=new ListNode(-1,head);
        if(head==NULL)
            return NULL;
            ListNode *prev=dummy;
            ListNode *curr=head;
            
            while(curr!=NULL)
            {
                if(curr->val==val)
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
            return dummy->next;
        
    }
};