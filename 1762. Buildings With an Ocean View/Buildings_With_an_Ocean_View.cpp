class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        int hL = heights.size();
        vector<int> res(hL, 0);
        int maxHeight = heights[hL-1];
        res.insert(res.begin(), hL-1);
        int temp;
        int rPtr = 1;
        
        for(int i = hL-2; i >=0; i--){
            temp = heights[i];
            if(temp > maxHeight){
                maxHeight = temp;
                res[rPtr] = i;
                rPtr++;
            }
        }
        
        vector<int> resS(res.begin(), res.begin()+rPtr);
        reverse(resS.begin(), resS.end());
        
        return resS;
    }
};