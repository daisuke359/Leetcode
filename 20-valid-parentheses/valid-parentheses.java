class Solution {
    public boolean isValid(String s) {
        Stack<Character> stack = new Stack<>();
        for(int i=0;i<s.length();i++) {
            char c = s.charAt(i);
            if(s.charAt(i)=='(' || s.charAt(i)=='{' || s.charAt(i)=='[') {
                stack.push(c);
            }
            else {
                if(stack.isEmpty()) {
                    return false;
                }

                char top = stack.pop();

                if(top=='(' && c!=')') {
                    return false;
                }
                else if(top=='{' && c!='}') {
                    return false;
                }
                else if(top=='[' && c!=']') {
                    return false;
                }
                
            }
            
        }

        return stack.isEmpty();
    }
}