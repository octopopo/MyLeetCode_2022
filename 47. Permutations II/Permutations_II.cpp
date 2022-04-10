class Solution {
public:
    vector<vector<int>> res;
    
    void swap(vector<int>& nums, int i, int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    void permute(vector<int>& nums, int curPos){
        int nL = nums.size();
        int lastCheck = 11;
        set<int> checkSet;
        if(curPos == nL-1){
            res.push_back(nums);
        }
        
        for(int i = curPos; i < nL; i++){
            if(checkSet.count(nums[i])){
                continue;
            }
            swap(nums, curPos, i);
            permute(nums, curPos+1);
            swap(nums, curPos, i);
            checkSet.insert(nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        permute(nums, 0);
        return res;
    }
};