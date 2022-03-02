class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result(2, 0);
        unordered_map<int, int> hash;
        int nLength = nums.size();
        int remain;
        
        for(int i = 0; i < nLength; i++){
            remain = target - nums[i];
            if(hash.count(remain) != 0){
                result[0] = i;
                result[1] = hash[remain];
                break;
            }
            //This is how unordered_map insert new element
            hash[nums[i]] = i;
            
        }
        
        return result;
    }
};