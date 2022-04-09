class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int nL = nums.size();
        int pStart = -1;
        int nStart = -1;
        int currentPro = 1;
        int res = 0;
        int currentNum;
        
        for(int i = 0; i < nL; i++){
            currentNum = nums[i];
            
            //if the currentNum is 0, restart the count 
            if(currentNum == 0){
                nStart = -1;
                pStart = -1;
                currentPro = 1;
                continue;
            }
            
            currentPro *= currentNum > 0 ? 1 : -1;
            
            //Set the first 
            nStart = (nStart == -1 && currentNum < 0) ? i : nStart;
            pStart = (pStart == -1 && currentNum > 0) ? i : pStart;
            
            
            if(currentPro < 0){
                if(nStart < 0){
                    continue;
                }
                res = max(res, i - nStart);
            }
            else{
                if(nStart < 0){
                    res = max(res, i-pStart+1);
                    continue;
                }
                else if(pStart < 0){
                    res = max(res, i-nStart+1);
                    continue;
                }
                
                res = max(res, i - (nStart > pStart ? pStart : nStart)+1);
            }
            
        }
        
        return res;
    }
};