class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int ptr = 0;
        int nL = nums.size();
        
        for(int i = 0; i < nL; i++){
            if(nums[i] != 0){
                nums[ptr] = nums[i];
                ptr++;
            }
        }
        
        for(int i = ptr; i < nL; i++){
            nums[i] = 0;
        }
    }
};