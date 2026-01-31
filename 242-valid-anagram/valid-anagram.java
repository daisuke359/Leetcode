class Solution {
    public boolean isAnagram(String s, String t) {
        if(s.length()!=t.length()) return false;

        HashMap<Character, Integer> letter = new HashMap<>();

        for(int i=0;i<s.length();i++) {
            if(letter.get(s.charAt(i))==null) {
                letter.put(s.charAt(i), 1);
            }else {
                letter.put(s.charAt(i), letter.get(s.charAt(i)) + 1);
            }
            
        }

        for(int j=0;j<t.length();j++) {
            if(letter.get(t.charAt(j))==null || letter.get(t.charAt(j))==0) return false;
            letter.put(t.charAt(j), letter.get(t.charAt(j))-1);
        }

        for(Integer v : letter.values()) {
            if(v!=0) return false;
        }

        return true;
    }
}