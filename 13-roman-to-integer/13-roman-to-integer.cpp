class Solution {
public:
    int romanToInt(string s) {
        int cnt=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='I'){
                cnt++;    
            }
            else if(s[i]=='V'){
                if(i!=0 && s[i-1]=='I'){
                    cnt+=3;
                }
                else{
                    cnt+=5;
                }
            }
            else if(s[i]=='X'){
                if(i!=0 && s[i-1]=='I'){
                    cnt+=8;
                }
                else{
                    cnt+=10;
                    }
                }
            else if(s[i]=='L'){
                if(i!=0 &&  s[i-1]=='X'){
                    cnt+=30;
                }
                else{
                    cnt+=50;
                }
            }
            else if(s[i]=='C'){
                if(i!=0 && s[i-1]=='X'){
                    cnt+=80;
                }
                else{
                    cnt+=100;
                }
            }
            else if(s[i]=='D'){
                if(i!=0 && s[i-1]=='C'){
                    cnt+=300;
                }
                else
                {
                    cnt+=500;
                    
                }
            }
            else if(s[i]=='M'){
                if(i!=0 && s[i-1]=='C'){
                    cnt+=800;
                }
                else
                {
                    cnt+=1000;
                    
                }
            }
           
            
        }

        
     return cnt;   
    }
};