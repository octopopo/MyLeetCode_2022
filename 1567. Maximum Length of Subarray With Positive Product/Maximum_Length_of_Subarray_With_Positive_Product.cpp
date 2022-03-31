class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int nL = nums.size();
        vector<int> zeroPos;
        vector<int> fromLeft(nL, 0);
        int temp;
        int maxLen = 0;
        
        fromLeft[0] = isPosOrNeg(nums[0]);
        
        if(nums[0] == 0){
            zeroPos.push_back(0);
        }
        
        for(int i = 1; i < nL; i++){
            temp = isPosOrNeg(nums[i]);
            if(temp == 0){
                fromLeft[i] = 0;
                zeroPos.push_back(i);
            }
            else{
                if(fromLeft[i-1] == 0){
                    fromLeft[i] = temp;
                    continue;
                }
                else{
                    fromLeft[i] = fromLeft[i-1] * temp;
                }
            }
        }
        int lastZ = -1;
        int currentZ;
        
        for(int i = 0; i < zeroPos.size(); i++){
            currentZ = zeroPos[i];
            if(currentZ -  lastZ <= 1){
                lastZ = currentZ;
                continue;
            }
            else{
                if(fromLeft[currentZ-1] > 0){
                    maxLen = max((currentZ-lastZ-1), maxLen);
                }
                else{
                    maxLen = max(maxLen,maxLenFromPart(nums, lastZ+1, currentZ-1));
                }
            }
            lastZ = currentZ;
        }
        
        if(fromLeft[nums.size()-1] > 0){
            maxLen = max(((int)nums.size()-lastZ-1), maxLen);
        }
        else{
            maxLen = max(maxLen,maxLenFromPart(nums, lastZ+1, nums.size()-1));
        }
        
        return maxLen;
    }
    
    int maxLenFromPart(vector<int>& nums, int start, int end){
        if(start == end){
            return nums[start] > 0 ? 1 : 0;
        }
        int nFromLeft = start, nFromRight = end;
        while(nFromRight >= 0 && nums[nFromRight] > 0){
            nFromRight--;
        }
        while(nFromLeft < nums.size() && nums[nFromLeft] > 0){
            nFromLeft++;
        }
        
        
        return  max((nFromRight-start), (end-nFromLeft));
    }
    
    int isPosOrNeg(int num){
        if(num > 0){
            return 1;
        }
        else if(num < 0){
            return  -1;
        }
        return 0;
    }
};

//best check https://leetcode.com/problems/maximum-length-of-subarray-with-positive-product/discuss/1881376/C%2B%2B-with-detailed-explanation