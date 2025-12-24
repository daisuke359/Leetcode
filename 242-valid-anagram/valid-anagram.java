class Solution {
    public boolean isAnagram(String s, String t) {

        if(s.length()!=t.length()) {
            return false;
        }
        HashMap<Character,Integer> mapS = new HashMap<>();
        HashMap<Character,Integer> mapT = new HashMap<>();

        for(int i=0;i<s.length(); i++) {
            mapS.put(s.charAt(i), mapS.getOrDefault(s.charAt(i), 0)+1);
            mapT.put(t.charAt(i), mapT.getOrDefault(t.charAt(i), 0)+1);
        }

        for(int j=0; j<s.length(); j++) {
            if(!mapS.get(s.charAt(j)).equals(mapT.get(s.charAt(j)))) {
                return false;
            }
        }

        return true;
    }
}