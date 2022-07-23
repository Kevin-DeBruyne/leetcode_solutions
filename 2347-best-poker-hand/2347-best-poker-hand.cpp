class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        map<int, int>mp;
        map<int, int>mp_suits;
        for(int i=0;i<ranks.size();i++){
            mp[ranks[i]]++;
        }
        for(int i=0;i<suits.size();i++){
            mp_suits[suits[i]]++;
        }
        int highest_suits=0;
        for(auto x:mp_suits){
            highest_suits=max(highest_suits,x.second);
        }
        if(highest_suits>=5){
            return "Flush";
        }
        int highest=0;
        for(auto x:mp){
            highest=max(highest,x.second);
        }
        if(highest>=3){
            return "Three of a Kind";
        }
        if(highest==2){
            return "Pair";
        }
        return "High Card";
        
    }
};