class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        int nL = nums.size();
        vector<int> oneP(nL, 0);
        getOnePermutation(nums, oneP, -1);
        return res;
    }
    
    void getOnePermutation(vector<int> nums, vector<int>currentRes, int lastPos){
        int nL = nums.size();
        if(lastPos == nL-1){
            res.push_back(currentRes);
        }
        int curPos = lastPos+1;
        int curNum;
        for(int i = 0; i < nL; i++){
            curNum = nums[i];
            if(nums[i] != 11){
                currentRes[curPos] = curNum;
                nums[i] = 11;
                getOnePermutation(nums, currentRes, curPos);
                nums[i] = curNum;
            }
        }
    }
};