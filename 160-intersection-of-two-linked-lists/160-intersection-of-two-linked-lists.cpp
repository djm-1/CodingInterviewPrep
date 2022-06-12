/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *pa=headA,*pb=headB;
        while(pa!=NULL && pb!=NULL && pa!=pb)
        {
            pa=pa->next;
            pb=pb->next;
            
            if(pa==pb)
                break;
            
            if(pa==NULL)
                pa=headB;
            if(pb==NULL)
                pb=headA;
            
        }
        if(pa==pb && pa!=NULL && pb!=NULL)
            return pa;
        
            return NULL;
    }
};