class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<vector<int>> temp;
        for(int i=0;i<triplets.size();i++){
            if(triplets[i][0]<=target[0] && triplets[i][1]<=target[1] && triplets[i][2]<=target[2]){
                temp.push_back(triplets[i]);
            }
        }
        bool a=false;bool b=false;bool c=false;
        for(int i=0;i<temp.size();i++){
            if(temp[i][0]==target[0]){
                a=true;
                break;
            }
        }
        for(int i=0;i<temp.size();i++){
            if(temp[i][1]==target[1]){
                b=true;
                break;
            }
        }
        for(int i=0;i<temp.size();i++){
            if(temp[i][2]==target[2]){
                c=true;
                break;
            }
        }
        if(a && b && c){
            return true;
        }
        return false;
    }
};