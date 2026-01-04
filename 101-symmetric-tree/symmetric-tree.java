/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public boolean isSymmetric(TreeNode root) {

        if(root==null) {
            return true;
        }


        
        TreeNode left = root.left;
        TreeNode right = root.right;

        return checkSymmetric(left, right);

        
    }

    public boolean checkSymmetric(TreeNode left, TreeNode right) {
        if(left==null && right==null) {
            return true;
        }else if(left==null || right==null) {
            return false;
        }

        if(left.val!=right.val) {
            return false;
        }

        return checkSymmetric(left.left, right.right) && checkSymmetric(left.right, right.left);

    }
}