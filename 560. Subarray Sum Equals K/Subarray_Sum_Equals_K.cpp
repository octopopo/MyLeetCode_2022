class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        int sum = 0;
        
        unordered_map<int, int> sumToAppear;
        sumToAppear[0] = 1;
        
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if(sumToAppear.count(sum-k)){
                count += sumToAppear[sum-k];
            }
            sumToAppear[sum] = sumToAppear.count(sum) ? sumToAppear[sum] + 1 : 1;
        }
        
        return count;
    }
};