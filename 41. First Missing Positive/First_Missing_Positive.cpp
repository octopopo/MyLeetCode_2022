class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int nL = nums.size();
        bool isOPresent = false;
        
        for(int i = 0; i < nL; i++){
            if(nums[i] <= 0){
                nums[i] = 1;
            }
            else if(nums[i] == 1){
                isOPresent = true;
            }
        }
        
        if(!isOPresent){
            //cout << isOPresent << endl;
            return 1;
        }
        
        for(int i = 0; i < nL; i++){
            int temp = nums[i] < 0 ? -nums[i] : nums[i];
            if(temp == nL){
                nums[0] = nums[0] >= 0 ? -nums[0] : nums[0];
            }
            if(temp < nL){
                nums[temp] = nums[temp] >= 0 ? -nums[temp] : nums[temp];
                //cout << temp << " " << nums[temp] << endl;
            }
            
        }
        
        for(int i = 1; i < nL; i++){
            //cout << nums[i] << endl;
            if(nums[i] > 0){
                return i;
            }
        }
        
        if(nums[0] > 0){
            return nL;
        }
        
        return nL+1;
    }
};