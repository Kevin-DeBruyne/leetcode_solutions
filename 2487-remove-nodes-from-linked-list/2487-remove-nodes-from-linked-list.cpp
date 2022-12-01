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
    ListNode* removeNodes(ListNode* head) {
        int n=0;
        stack<int>st;
        ListNode* temp=head;
        while(temp!=NULL){
            temp=temp->next;
            n++;
        }
        
        int i=0;
        st.push(head->val);
        head=head->next;
        i++;
        while(i<n && head!=NULL){
            if(head->val>st.top()){
                while(!st.empty() && head->val>st.top()){
                    st.pop();
                }
                st.push(head->val);
            }
            else{
                st.push(head->val);
            }
            i++;
            head=head->next;
        }
        vector<int>vec;
        while(!st.empty()){
            vec.push_back(st.top());
            st.pop();
        }
        reverse(vec.begin(), vec.end());
        for(auto x:vec){
            cout<<x<<" ";
        }
        //     cout<<endl;
        ListNode* ans=new ListNode;
        ListNode* root=ans;
        ans->val=vec[0];
        for(int i=1;i<vec.size();i++){
            ListNode* temp=new ListNode;
            temp->val=vec[i];
            ans->next=temp;
            ans=temp;
        }
        // ans->val
        return root;
    }
};