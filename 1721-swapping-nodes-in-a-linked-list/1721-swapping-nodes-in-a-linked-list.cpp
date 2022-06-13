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
    ListNode* swapNodes(ListNode* head, int k) {
        
        ListNode *slow=head,*fast=head;
        
        k--;
        
        while(k--)
        {
            fast=fast->next;
        }
        
        ListNode* startK=fast;
        
        while(fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next;
        }
        
        ListNode *endK=slow;
        
        swap(startK->val,endK->val);
        
        return head;
    }
};