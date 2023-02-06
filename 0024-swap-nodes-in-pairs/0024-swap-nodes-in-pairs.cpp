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
    ListNode* swapPairs(ListNode* head) {
        ListNode* d=new ListNode();
        d->val=0;
        d->next=head;
        //save
        ListNode* prev;
        ListNode* curr;
        prev=d;
        curr=head;
        //set
        while(curr && curr->next){
            ListNode* np=curr->next->next;
            ListNode* s=curr->next;
            // update
            curr->next=np;
            prev->next=s;
            s->next=curr;

            prev=curr;
            curr=np;
        }
        return d->next;
    }
};