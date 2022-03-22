class Solution {
public:
    static int compare(const void* a, const void* b){
        return *(int*)a - *(int*)b;
    }
    bool containsDuplicate(vector<int>& nums) {
        int nL = nums.size();
        qsort(&nums[0], nL, sizeof(int), compare);
        for(int i = 1; i < nL; i++){
            if(nums[i] == nums[i-1]){
                return true;
            }
        }
        
        return false;
    }
};