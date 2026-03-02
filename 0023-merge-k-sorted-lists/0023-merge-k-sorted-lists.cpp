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
    struct cmp{
        bool operator()(ListNode* a, ListNode*b) const{
            return a->val>b->val; //minheap
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>,cmp>pq;

        for(auto node:lists){
            if(node)
                pq.push(node);
        }


        ListNode dummy(0);

        ListNode *tail=&dummy;

        while(!pq.empty()){
            ListNode* curr= pq.top();
            pq.pop();
            tail->next=curr;
            tail=tail->next;

            if(curr->next)
                pq.push(curr->next);
        }

        tail->next=NULL;

        return dummy.next;


    }
};