    bool comp(pair<int,int>&a,pair<int,int>&b)
    {
        if(a.first!=b.first){
            return a.first>b.first;
        }
        else{
            return a.second<b.second;
        }
    }
class Solution {
public:
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        unordered_map<string,int>mp;
        for(auto &x:positive_feedback){
            mp[x]=1;
        }
        for(auto &x:negative_feedback){
            mp[x]=-1;
        }
        int n=report.size();
        vector<pair<int,int>>vec;
        for(int i=0;i<n;i++){
                int score=0;
                string temp="";
            for(int j=0;j<report[i].size();j++){
                if(report[i][j]==' '){
                    if(mp[temp]==1){
                        score+=3;
                    }
                    else if(mp[temp]==-1){
                        score-=1;
                    }
                    temp="";
                }
                else{
                    temp+=report[i][j];
                }
            }
                if(mp[temp]==1){
                    score+=3;
                }
                else if(mp[temp]==-1){
                    score-=1;
                }
            cout<<score<<endl;
            vec.push_back({score, student_id[i]});
        }
        sort(vec.begin(), vec.end(),comp);
        vector<int>reports;
        student_id.clear();
        for(int i=0;i<k;i++){
            reports.push_back(vec[i].second);
        }
        return reports;
    }
};