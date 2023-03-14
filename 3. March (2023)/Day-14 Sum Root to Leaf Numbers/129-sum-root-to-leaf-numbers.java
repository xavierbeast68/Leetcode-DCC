//* https://leetcode.com/problems/sum-root-to-leaf-numbers/description/
//* https://www.geeksforgeeks.org/sum-numbers-formed-root-leaf-paths/
//* https://www.youtube.com/watch?v=J0k0xLA8k8c
//* https://www.youtube.com/watch?v=Jk16lZGFWxE

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
    public int dfs(TreeNode root, int sum){
        if(root == null){
            return 0;
        }

        sum = sum*10 + root.val;

        if(root.left == null && root.right == null){
            return sum;
        }

        return dfs(root.left, sum) + dfs(root.right, sum);
    }
    public int sumNumbers(TreeNode root) {
        return dfs(root, 0);
    }
}