class Solution {
    public void reverseString(char[] s) {
        int index = 0;
        for(int i=s.length-1;i>=s.length/2;i--) {
            char temp = s[i];
            s[i]=s[index];
            s[index] = temp;
            index++;
        }
    }
}