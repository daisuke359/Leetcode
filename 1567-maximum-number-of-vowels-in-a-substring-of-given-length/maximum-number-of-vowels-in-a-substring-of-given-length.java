class Solution {

    public boolean isVowel(Character c) {
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') {
            return true;
        }else {
            return false;
        }
    }
    public int maxVowels(String s, int k) {
        int count = 0;
        int max = 0;
        int left=0;
        int right=0;
        for(int i=0;i<k;i++) {
            if(isVowel(s.charAt(right))) {
                    count++;
                }
            right++;
        }
        max = count;
        while(right<s.length()) {
            if(isVowel(s.charAt(left))) {
            count--;
            }
            if(isVowel(s.charAt(right))) {
            count++;
            }

            if(count>max) {
                max=count;
            }
            right++;
            left++;
        }

        return max;
    }
}