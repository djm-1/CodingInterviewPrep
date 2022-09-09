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
    int len(ListNode *head)
    {
        int cnt=0;
        ListNode *temp=head;
        while(temp!=NULL)
        {
            temp=temp->next;
            cnt++;
        }
        
        return cnt;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(len(head)<k)
            return head;
        int cnt=0;
        
        ListNode *next=NULL,*prev=NULL,*curr=head;
        
        while(cnt<k)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            cnt++;
        }
        
        
            head->next=reverseKGroup(next,k);
        
        
        return prev;
    }
};