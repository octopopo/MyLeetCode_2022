class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        int nL = nums.size();
        getOnePermutation(nums, -1);
        return res;
    }
    
    void swap(vector<int>& nums, int i, int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    
    void getOnePermutation(vector<int>& nums, int lastPos){
        int nL = nums.size();
        if(lastPos == nL-1){
            res.push_back(nums);
        }
        int curPos = lastPos+1;
        int curNum;
        for(int i = curPos; i < nL; i++){
            swap(nums, curPos, i);
            getOnePermutation(nums, curPos);
            swap(nums, curPos, i);
        }
    }
    
    
};