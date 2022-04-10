class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int nL = nums.size();
        
        int i = nL-2;
        
        while(i >= 0 && nums[i] >= nums[i+1]){
            i--;
        }
        
        if(i >= 0){
            int j = nL-1;
            while(nums[j] <= nums[i]){
                j--;
            }
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
        
        //cout << i << endl;
        
        reverse(nums.begin() + i+1, nums.end());
    }
};