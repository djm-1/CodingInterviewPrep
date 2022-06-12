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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *dummy=new ListNode(0);
        ListNode *ptr=dummy;
        priority_queue<int>Q;
        for(int i=0;i<lists.size();i++)
        {
            while(lists[i]!=NULL)
            {
                Q.push(-lists[i]->val);
                lists[i]=lists[i]->next;
            }
        }
        
        while(!Q.empty()){
            int curr=Q.top();
            Q.pop();
            ptr->next=new ListNode(-curr);
            ptr=ptr->next;
        }
        
        ListNode *head=dummy->next;
        delete(dummy);
        return head;
    }
};