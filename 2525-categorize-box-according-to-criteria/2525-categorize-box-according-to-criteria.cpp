class Solution {
public:
    string categorizeBox(long long length, long long width, long long height, long long mass) {
        long long volume=(long long)length*(long long)width*(long long)height;
        bool heavy=false;
        bool bulky=false;
        bool neither=false;
        bool both=false;
        if((length>=10000) || (width>=10000) || (height>=10000) || (volume>=1000000000)){
            bulky=true;
        }
        if(mass>=100){
            heavy=true;
        }
        if(bulky && heavy){
            return "Both";
        }
        if(!bulky && heavy){
            return "Heavy";
        }
        if(bulky && !heavy){
            return "Bulky";
        }
        return "Neither";
        
    }
};