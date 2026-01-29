class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int highIdx=numbers.length-1;
        int lowIdx=0;

        while(highIdx > lowIdx) {
            int sum = numbers[highIdx] + numbers[lowIdx];
            if(sum==target) {
                return new int[] {lowIdx+1,highIdx+1};
            }else if(sum<target) {
                lowIdx++;
            }else {
                highIdx--;
            }
        }

        return new int[] {0,0};

    }
}