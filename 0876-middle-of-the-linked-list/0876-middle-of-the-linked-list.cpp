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
    ListNode* middleNode(ListNode* head) {
        int cnt=0;
        ListNode *curr=head;

        while(curr!=NULL)
        {
            cnt++;
            curr=curr->next;
        }

        // Counted nodes so far

        int x=(cnt/2)+1;

        //reset current ptr at head
        curr=head;
        cnt=1;
        while(curr!=NULL & cnt<x){
            cnt++;
            curr=curr->next;
        }

        return curr;

    }
};