//* https://leetcode.com/problems/symmetric-tree/
//* https://www.youtube.com/watch?v=nKggNAiEpBE&ab_channel=takeUforward
//* https://www.youtube.com/watch?v=Mao9uzxwvmc
//* https://www.youtube.com/watch?v=lGxQfZ1mujc
//* https://www.geeksforgeeks.org/symmetric-tree-tree-which-is-mirror-image-of-itself/

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
    public boolean dfs(TreeNode leftSub, TreeNode rightSub){

        // leftSub == null && rightSub == null
        if(leftSub == null && rightSub == null){
            return true;
        }

        if((leftSub != null && rightSub != null) && (leftSub.val == rightSub.val)){
            return (dfs(leftSub.left, rightSub.right) && dfs(leftSub.right, rightSub.left));
        }

        return false;
    }
    public boolean isSymmetric(TreeNode root) {
        return dfs(root.left, root.right);
    }
}