class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() && nums[i] <= 0; i++){
            if(i == 0 || nums[i-1] != nums[i]){
                twoSum(nums, i);
            }
        }
        return res;
    }
    
    void twoSum(vector<int>& nums, int i){
        int low = i+1;
        int high = nums.size()-1;
        int sum;
        while(low < high){
            sum = nums[i] + nums[low] + nums[high];
            
            if(sum == 0){
                res.push_back({nums[i], nums[low], nums[high]});
                while(low+1 < high && nums[low] == nums[low+1]){
                    low++;
                }
                low++;
            }
            
            if(sum < 0){
                low++;
            }
            
            if(sum > 0){
                high--;
            }
            
     
        }
    }
};