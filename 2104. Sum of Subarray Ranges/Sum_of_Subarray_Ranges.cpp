class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        //using monotonic stack
        //The solution is to count the usage of target number being used as a max number in subarray
        //So the logic is (right subarray count) * (left subarray count) * nums[i]
        
        stack<int> maxStack;
        stack<int> minStack;
        long long maxSum = 0;
        int nL = nums.size();
        int currentNum, topNum;
        int topIndex;
        int rightCount, leftCount;
        int mid;
        //Add this at the end of the array is to let every number remain int the stack to get pop()
        nums.push_back(INT_MAX);
        
        for(int i = 0;  i <= nL; i++){
            currentNum = nums[i];
            //The stack is storing the index of the largest number so far
            if(!maxStack.empty()){
                topIndex = maxStack.top();
                topNum = nums[topIndex];
            }
            
            while(!maxStack.empty() && currentNum >= topNum){
                mid = topIndex;
                maxStack.pop();
                rightCount = i - mid;
                
                topIndex = maxStack.empty() ? -1 : maxStack.top();
                leftCount = mid - topIndex;
                maxSum += (long long)rightCount * (long long)leftCount * (long long)topNum;
                
                if(topIndex >= 0){
                    topNum = nums[topIndex];
                }
            }
            maxStack.push(i);
        }
        
        
        nums.back() = INT_MIN;
        
        for(int i = 0; i <= nL; i++){
            currentNum = nums[i];
            if(!minStack.empty()){
                topIndex = minStack.top();
                topNum = nums[topIndex];
            }
            
            while(!minStack.empty() && currentNum <= topNum){
                mid = topIndex;
                minStack.pop();
                rightCount = i - mid;
                
                topIndex = minStack.empty() ? -1 : minStack.top();
                leftCount = mid - topIndex;
                maxSum -= (long long)rightCount * (long long)leftCount * (long long)topNum;
                
                if(topIndex >= 0){
                    topNum = nums[topIndex];
                }
            }
            minStack.push(i);
        }
        
        
        return maxSum;
        
    }
};