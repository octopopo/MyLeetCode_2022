class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int nL = nums.size();
        
        int mid = nL/2;
        
        int target = nums[mid];
        int res = 0;
        
        
        for(int i = 0; i < nL; i++){
            res += abs(target-nums[i]);
        }
        
        return res;
    }
};