//* https://leetcode.com/problems/check-completeness-of-a-binary-tree/
//* https://www.youtube.com/watch?v=olbiZ-EOSig&t=344s&ab_channel=NeetCodeIO
//* https://www.youtube.com/watch?v=O_EqWFtQ45g&ab_channel=CodeFreaks

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
    public boolean isCompleteTree(TreeNode root) {
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        boolean f = false;

        while(!q.isEmpty()){
            TreeNode front = q.poll();

            if(front.left != null){
                if(f){
                    return false;
                }
                q.add(front.left);
            }
            else{
                f = true;
            }

            if(front.right != null){
                if(f){
                    return false;
                }
                q.add(front.right);
            }
            else{
                f = true;
            }
        }

        return true;
    }
}