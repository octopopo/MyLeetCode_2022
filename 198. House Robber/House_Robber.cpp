class Solution {
public:
    int rob(vector<int>& nums) {
        int nL = nums.size();
        vector<int> record(nL, 0);
        if(nL == 1){
            return nums[0];
        }
        
        record[0] = nums[0];
        record[1] = nums[1] > record[0] ? nums[1] : record[0];
        
        for(int i = 2; i < nL; i++){
            int num1 = nums[i] + record[i-2];
            record[i] = num1 > record[i-1] ? num1 : record[i-1];
        }
        
        return record[nL-1];
    }
};