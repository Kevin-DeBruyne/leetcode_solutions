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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy=new ListNode();
        dummy->next=head;
        ListNode* prev=dummy;
        ListNode* curr=head;

        while(curr){
            ListNode* temp=curr->next;
            if(curr->val==val){
                prev->next=temp;
                
            }
            else{
                prev=curr;
            }
            curr=temp;
        }
        return dummy->next;
    }
};