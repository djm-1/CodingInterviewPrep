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
    void split_sum(vector<int>&split,int count,int k){
        while(k>0)
        {
            int num=(count+k-1)/k;
            split.push_back(num);
            count-=num;
            k--;
        }
        return;
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        
        vector<ListNode*>ans;
        int count=0;
        ListNode *curr=head;
        while(curr!=NULL)
        {
            count++;
            curr=curr->next;
        }
        
        vector<int>split;
        split_sum(split,count,k);
        
        
        ListNode *start=head,*res=head,*prev=NULL;
        for(int i=0;i<k;i++)
        {
            
            for(int j=0;j<split[i];j++)
            {
                if(start!=NULL)
                {   prev=start;
                    start=start->next;
                }
            }
            
            if(prev!=NULL)
                prev->next=NULL;
            ans.push_back(res);
            
            res=start;
        }
        return ans;
    }
};