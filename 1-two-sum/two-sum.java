class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] targetArr = new int[2];
        for(int i=0; i<nums.length; i++) {
            for(int j=i+1;j<nums.length;j++) {
                if(nums[i]+nums[j]==target) {
                    targetArr[0] = i;
                    targetArr[1] = j;
                    break;
                }
            }
        }

        return targetArr;
    }
}