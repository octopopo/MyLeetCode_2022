class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int nL = nums.size();
        int head = 0;
        int tail = nL;
        
        while(head < tail){
            
            int mid = (head+tail)/2;
            //cout << "in while "<< mid << endl;
            
            if(mid > 0 && nums[mid] >= target && nums[mid-1] < target){
                //cout << mid << endl;
                return mid;
            }
            else if(mid == 0 && nums[mid] >= target){
                return 0;
            }
            else if(nums[mid] < target){
                head = mid+1;
            }
            else if(nums[mid] > target){
                tail = mid;
            }
        }
        
        if(target <= nums[0]){
            return 0;
        }
        
        if(target > nums[nL-1]){
            return nL;
        }
        
        return 1;
    }
};