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
    bool hasCycle(ListNode *head) {
        ListNode *slow=head, *fast=head; //initial
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next; //1 step move
            fast=fast->next->next; //2 step move
            if(fast==slow)
                return true; //meeting in cycle , dist = wholer circle
        }

        return false;
    }
};