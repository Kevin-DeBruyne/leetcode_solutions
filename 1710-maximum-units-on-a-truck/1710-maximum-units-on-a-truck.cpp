bool cmp(vector<int>&a, vector<int>&b){
    return a[1]>b[1];
}
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), cmp);
        int ans=0;
        int cnt=0;
        int i;
            for(i=0;i<boxTypes.size();i++){
                if(cnt+boxTypes[i][0]<=truckSize){
                    ans+=boxTypes[i][0]*boxTypes[i][1];
                    cnt+=boxTypes[i][0];
                }   
                else{
                    break;
                }
                
            }
            if(i<boxTypes.size() && cnt!=truckSize){
                ans+=(truckSize-cnt)*boxTypes[i][1];

            }
        return ans;
    }
};