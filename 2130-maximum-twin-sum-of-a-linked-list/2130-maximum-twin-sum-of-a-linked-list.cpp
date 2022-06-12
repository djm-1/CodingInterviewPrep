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
    int pairSum(ListNode* head) {
        int sum=0;
        unordered_map<int,int>mp;
        int count=0;
        ListNode *curr=head;
        while(curr!=NULL)
        {
            mp[count]=curr->val;
            curr=curr->next;
            count++;
        }
        for(int i=0;i<count;i++)
        {
            sum=max(sum,mp[i]+mp[count-1-i]);
        }
        return sum;
    }
};