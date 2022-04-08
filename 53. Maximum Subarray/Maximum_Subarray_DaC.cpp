class Solution {
public:
    int res = INT_MIN;
    //Will return a boolean indicate if the result can be connected;
    int getSubArrayPart(vector<int>& nums, int L, int R){
        if(L == R){
            return nums[L];
        }
        
        int mid = (L+R)/2;
        int curr = 0;
        int bestL = 0;
        int bestR = 0;
        int bestO = 0;
        
        for(int i = mid-1; i >= 0; i--){
            curr += nums[i];
            if(curr > bestL){
                bestL = curr;
            }
        }
        
        curr = 0;
        
        for(int j = mid+1; j <= R; j++){
            curr += nums[j];
            if(curr > bestR){
                bestR = curr;
            }
        }
        
        bestO = nums[mid] + bestL + bestR;
        
        int lR = getSubArrayPart(nums, L, mid);
        int rR = getSubArrayPart(nums, mid+1, R);
        
        return max(bestO, max(lR, rR));
        
        
    }
    int maxSubArray(vector<int>& nums) {
        return getSubArrayPart(nums, 0, nums.size()-1);
    }
};