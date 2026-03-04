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
        
        // num of nodes
        ListNode* curr=head;
        int cnt=0;
        while(curr!=NULL){
            cnt++;
            curr=curr->next;
        }

        int midNode= cnt/2; //mid node position

        //Traverse till middle
        curr=head; //reset curr

        while(midNode>0){
            curr=curr->next;
            midNode--;
        }

        return curr;
        
    }
};