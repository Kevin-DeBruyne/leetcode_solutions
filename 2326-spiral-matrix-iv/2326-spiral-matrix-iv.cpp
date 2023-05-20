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
    void dfs(vector<vector<int>>&res,int i, int j, bool goup, ListNode* &head){
            int m=res.size();
            int n=res[0].size();
            if(!head){
                return;
            }
            if(i<0 || j<0 || i>=m || j>=n || res[i][j]!=-1){
                return;
            }
            res[i][j]=head->val;
            head=head->next;
            if(goup) dfs(res, i-1 , j, true, head);
            dfs(res, i, j+1, false, head);
            dfs(res, i+1, j, false, head);
            dfs(res, i, j-1, false, head);
            dfs(res, i-1 , j, true, head);
    }
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> res(m, vector<int> (n, -1));
        int i=0;
        int j=0;
        bool goup=false;
        dfs(res, i, j, goup, head);
        return res;
    }
};