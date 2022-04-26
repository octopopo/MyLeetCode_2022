class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res;
        int nL = nums.size();
        int firstP = nL;
        int firstN = 0;
        
        int i = 0;
        
        for(; i < nL; i++){
            if(nums[i] == 0){
                res.push_back(0);
                if(i >= 0){
                    firstN = i-1;
                }
                if(i < nL-1){
                    firstP = i+1;
                }
                break;
            }
            else if(nums[i] > 0){
                if(i >= 0){
                    firstN = i-1;
                }
                firstP = i;
                break;
            }
        }
        
        if(i == nL){
            //cout << "hrere" << endl;
            firstN = nL-1;
        }
        
        //cout << firstN << " p " << firstP << endl;
        
        while(firstP <= nL-1 || firstN >= 0){
            if(firstP <= nL-1 && firstN >= 0){
                int tempN = nums[firstN] * -1;
                if(tempN <= nums[firstP]){
                    res.push_back(tempN * tempN);
                    firstN--;
                }
                else{
                    res.push_back(nums[firstP]  * nums[firstP]);
                    firstP++;
                }
            }
            else if(firstP > nL-1 && firstN >= 0){
                res.push_back(nums[firstN]  * nums[firstN]);
                firstN--;
            }
            else if(firstP <= nL-1 && firstN < 0){
                res.push_back(nums[firstP]  * nums[firstP]);
                firstP++;
            }
        }
        
        return res;
    }
};