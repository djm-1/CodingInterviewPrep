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
    ListNode* oddEvenList(ListNode* head) {
        int count=1;
        if(head==NULL||head->next==NULL)
            return head;
        ListNode *dummy=new ListNode(),*even=new ListNode(),*odd=new ListNode();
        ListNode *temp=head,*oddptr=odd,*evenptr=even;
        while(temp!=NULL)
        {
            if(count%2==1)
            {
                oddptr->next=temp;
                oddptr=oddptr->next;
            }
            else
            {
                evenptr->next=temp;
                evenptr=evenptr->next;
            }
            
            count++;
            temp=temp->next;
        }
        
        dummy->next=odd->next;
        oddptr->next=even->next;
        evenptr->next=NULL;
        
        return dummy->next;
    }
};