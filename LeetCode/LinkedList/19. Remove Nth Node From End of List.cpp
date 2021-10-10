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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head)
            return head;
        ListNode * curr=head;
        int N=0;
        while(curr!=nullptr)
        {
            N++;
            curr=curr->next;
        }
        
        //if node to be deleted not in range
        if(N<n) return head;
        
        //if first node to be deleted
        if(N==n)
        {
            ListNode *temp=head;
            head=head->next;
            return head;
        }
        
        //
        int i;
        N=N-n;
        curr=head;
        for(i=1;i<N;i++)
        {
            curr=curr->next;
        }
        
        //if last node to be deleted
        if(n==1)
        {
            curr->next=nullptr;
            return head;
        }
        
        
        curr->next=curr->next->next;
        return head;
    }
};
