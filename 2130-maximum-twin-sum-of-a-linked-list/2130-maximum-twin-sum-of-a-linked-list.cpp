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
        if(!head){
            return NULL;
        }
        vector<int>vec;
        ListNode* curr=head;
        while(head){
            vec.push_back(head->val);
            head=head->next;
        }
        reverse(vec.begin(), vec.end());
        for(auto x:vec){
            cout<<x<<" ";
        }
        cout<<endl;
        int sum=0;
        int i=0;
        while(curr && i<vec.size()){
            sum=max(sum, curr->val+vec[i]);
            i++;
            curr=curr->next;
        }
        return sum;
    }
};