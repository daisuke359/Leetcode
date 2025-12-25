class Solution {
    public int removeDuplicates(int[] nums) {
        int count = 1;
        int slow = 0;
        int fast = 1;

        while(fast<nums.length) {
            if(nums[slow]!=nums[fast]) {
                slow++;
                nums[slow]= nums[fast];
                count++;
            }
            fast++;
        }

        return count;
    }
}