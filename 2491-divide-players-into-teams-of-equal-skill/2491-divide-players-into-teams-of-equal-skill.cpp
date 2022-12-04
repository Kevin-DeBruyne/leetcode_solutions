class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        if(skill.size()==2){
            return skill[0]*skill[1];
        }
        long long n=skill.size();
        sort(skill.begin(), skill.end());
        long long sum=0;
        for(auto x:skill){
            sum+=x;
        }
        // cout<<sum/(n/2)<<endl;
        long long chem=0;
        long long j=n-1;
        long long i=0;
        long long temp=skill[i]+skill[j];
        while(i<j){
            if(skill[i]+skill[j]!=temp){
                return -1;
            }
            chem+=skill[i]*skill[j];
            i++;
            j--;
            }
            return chem;
    }
};