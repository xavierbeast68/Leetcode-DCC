//* https://leetcode.com/problems/linked-list-random-node/description/
//* https://www.youtube.com/watch?v=FoHIX3URFaM
//* https://www.youtube.com/watch?v=qQDM1J02Sq4
//* https://www.geeksforgeeks.org/select-a-random-node-from-a-singly-linked-list/

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
class Solution {
    ArrayList<Integer> arr = new ArrayList<>();

    void pushing(ListNode head){
        ListNode temp = head;
        while(temp != null){
            arr.add(temp.val);
            temp = temp.next;
        }
    }
    public Solution(ListNode head) {
        pushing(head);
    }
    
    public int getRandom() {
        // int sz = arr.size();
        // int random = (int)(Math.random() * arr.size());
        // return arr.get(random);

        return arr.get((int)(Math.random() * arr.size()));
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */