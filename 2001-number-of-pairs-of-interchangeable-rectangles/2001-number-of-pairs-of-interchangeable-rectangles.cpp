class Solution {
public:
       
    long long interchangeableRectangles(vector<vector<int>>& rectangles) 
    
    {
         int n = rectangles.size();
        unordered_map<double, double> mp;
        long long result = 0;
        
        //I am going from (n-1) to 0 so that I am aware of the ratios which
		//occurred after current index i
        for(int i = 0; i < n; i++) {
            double ratio = (double)rectangles[i][0]/(double)rectangles[i][1];
            
            //Have I seen this ratio
            if(mp.find(ratio) != end(mp))
                result += mp[ratio];

            //Increase the ratio count
            mp[ratio]++;
        }
        return result;
    }
    
};