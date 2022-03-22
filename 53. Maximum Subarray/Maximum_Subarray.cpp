class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxNum = INT_MIN;
        int tempRes = 0;
        int nL = nums.size();
        for(int i = 0; i < nL; i++){
            tempRes += nums[i];
            maxNum = max(maxNum, tempRes);
            if(tempRes <= 0){
                tempRes = 0;
            }
        }
        
        return maxNum;
    }
};