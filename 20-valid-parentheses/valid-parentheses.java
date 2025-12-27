class Solution {
    public boolean isValid(String s) {
        Stack<Character> stack = new Stack<>();

        for(int i=0; i<s.length();i++) {
            if(s.charAt(i)=='('){
                stack.push(')');
            }else if(s.charAt(i)=='[') {
                stack.push(']');
            }else if(s.charAt(i)=='{') {
                stack.push('}');
            }else if(s.charAt(i)==')' || s.charAt(i)==']' || s.charAt(i)=='}') {
                if(stack.isEmpty()) {
                    return false;
                }
                if(stack.peek()==s.charAt(i)) {
                    stack.pop();
                }else {
                    return false;
                }
            }
        }

        if(stack.isEmpty()) {
            return true;
        }else {
            return false;
        }
    }
}