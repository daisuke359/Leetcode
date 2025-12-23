class Solution {
    public boolean isPalindrome(String s) {
        //make it lowercase
        //remove all non-alphanumeric characters
        //check 
        String lower = s.toLowerCase();
        StringBuilder cleaned = new StringBuilder();
        // remove non-alphanumeric
        for (int i = 0; i < lower.length(); i++) {
            char c = lower.charAt(i);
            if (Character.isLetterOrDigit(c)) {
                cleaned.append(c);
            }
        }

        // palindrome check (two pointers)
        int left = 0;
        int right = cleaned.length() - 1;

        while (left < right) {
            if (cleaned.charAt(left) != cleaned.charAt(right)) {
                return false;
            }
            left++;
            right--;
        }

        return true;
    }
}