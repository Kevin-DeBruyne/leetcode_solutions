class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int hours=0;
        for(int i=0;i<energy.size();i++){
            if(initialEnergy<=energy[i]){
                hours+=energy[i]-initialEnergy+1;
                initialEnergy+=energy[i]-initialEnergy+1;
            }
            if(initialExperience<=experience[i]){
                hours+=experience[i]-initialExperience+1;
                initialExperience+=experience[i]-initialExperience+1;
            }     
            
            initialEnergy-=energy[i];
            initialExperience+=experience[i];
        }
        return hours;
    }
};