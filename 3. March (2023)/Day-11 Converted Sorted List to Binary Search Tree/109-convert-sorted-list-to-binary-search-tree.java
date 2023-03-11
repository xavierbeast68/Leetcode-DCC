//* https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/description/
//* https://www.youtube.com/watch?v=mbEaJWHtTvQ
//* https://www.geeksforgeeks.org/sorted-linked-list-to-balanced-bst/
//* https://practice.geeksforgeeks.org/problems/sorted-list-to-bst/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
//* https://www.codingninjas.com/codestudio/library/convert-a-sorted-linked-list-to-balanced-bst
//* https://www.codingninjas.com/codestudio/problems/sorted-linked-list-to-balanced-bst_842564


/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
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
    public TreeNode bst(int low, int high, ArrayList<Integer> arr){
        if(low > high){
            return null;
        }

        int mid = low + (high - low)/2;

        TreeNode root = new TreeNode(arr.get(mid));
        root.left = bst(low, mid - 1, arr);
        root.right = bst(mid + 1, high, arr);

        return root;
    }
    public TreeNode sortedListToBST(ListNode head) {
        
        ArrayList<Integer> arr = new ArrayList<>();
        
        while(head != null){
            arr.add(head.val);
            head = head.next;
        }

        int low = 0, high = arr.size() - 1;
        return bst(low, high, arr);
    }
}