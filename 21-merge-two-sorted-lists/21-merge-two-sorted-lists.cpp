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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode *left=list1,*right=list2;
        ListNode *dummy=new ListNode(-1);
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
        
        if(left)
            temp->next=left;
        if(right)
            temp->next=right;
        
        return dummy->next;
    }
};