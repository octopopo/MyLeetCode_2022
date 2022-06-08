class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> recordSet = new HashMap<Integer, Integer>();
        int[] result = new int[2];
        recordSet.put(nums[0], 0);
        for(int i = 1; i < nums.length; i++){
            int remain = target - nums[i];
            if(recordSet.containsKey(remain)){
                result[0] = i;
                result[1] = recordSet.get(remain);
                break;
            }
            recordSet.put(nums[i], i);
        }
        
        return result;
    }
}