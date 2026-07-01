class Solution {
    public int[] twoSum(int[] nums, int target) {
        int second=0;
        int first=second+1;

        while(second<nums.length-1) {
            if(nums[second]+nums[first]==target) {
                return new int[]{second, first}; 
            } else if(first==nums.length-1){
                second++;
                first=second+1;
            } else {
                first++;
            }
        }

        return new int[]{-1, -1};
    }
}