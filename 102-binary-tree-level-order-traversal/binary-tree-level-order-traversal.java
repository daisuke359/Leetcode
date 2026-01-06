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
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> result = new ArrayList<>();

        List<TreeNode> queue = new ArrayList<>();

        //put root in a queue
        if(root==null) {
            return new ArrayList<>();
        }
        queue.add(root);

        while(!queue.isEmpty()) {
            List<Integer> level = new ArrayList<>();
            int levelSize = queue.size();

            for(int i=0;i<levelSize;i++) {
                TreeNode node = queue.remove(0);
                level.add(node.val);

                if(node.left!=null) {
                    queue.add(node.left);
                }
                if(node.right!=null) {
                    queue.add(node.right);
                }
            }

            result.add(level);
        }

        return result;
    }
}