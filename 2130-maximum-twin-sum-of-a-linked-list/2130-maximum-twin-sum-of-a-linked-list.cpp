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
    ListNode* rev(ListNode* head){
        if(head==NULL||!head->next){
            return  head;
        }
        ListNode* temp=head->next;
        ListNode* root=rev(head->next);
        head->next=NULL;
        temp->next=head;
        return root;
        
    } 
    int pairSum(ListNode* head) {
        int sum=0;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode* mid=rev(slow);
        while(mid){
            sum=max(sum,mid->val+head->val);
            mid=mid->next;
            head=head->next;
        }
        return sum;
    }
    
    
};