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
    ListNode* reverseLinkedList(ListNode* slow){
        ListNode *prev=NULL, *curr=slow->next, *next=slow->next;
        ListNode *endList=NULL;
        while(curr!=NULL)
        {
            if(curr->next==NULL)
            {
                endList=curr;
            }
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return endList;
    }
    bool isPalindrome(ListNode* head) {
        bool pal=true;
        ListNode *slow=head,*fast=head,end=NULL;
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            slow=slow->next;
            
            fast=fast->next->next;
        }
        
        ListNode *endList=reverseLinkedList(slow);
        ListNode *startList=head;
        while(endList!=NULL)
        {
            if(startList->val!=endList->val)
                return false;
            else
            {
                startList=startList->next;
                endList=endList->next;
            }
        }
        return true;
    }
};