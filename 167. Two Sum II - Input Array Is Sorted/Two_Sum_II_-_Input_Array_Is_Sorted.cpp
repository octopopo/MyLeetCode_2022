class Solution {
public:
    int getSum(vector<int>& numbers, int ptr, int ptr2){
        return numbers[ptr] + numbers[ptr2];
    }
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res(2, 0);
        int head = 0;
        int tail = numbers.size()-1;
        
        
        while(head < tail){
            int sum = getSum(numbers, head, tail);
            
            if(sum == target){
                res[0] = head+1;
                res[1] = tail+1;
                break;
            }
            else if(sum > target){
                tail--;
            }
            else if(sum < target){
                head++;
            }
        }
        
        return res;
    }
};