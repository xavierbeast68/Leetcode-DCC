//* https://leetcode.com/problems/linked-list-cycle-ii/
//* https://www.youtube.com/watch?v=owc1yVJOklw
//* https://www.youtube.com/watch?v=zk6e05dmyNw

/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode detectCycle(ListNode head) {
        ListNode fast = head;
        ListNode slow = head;

        while(fast != null && fast.next != null){
            fast = fast.next.next;
            slow = slow.next;

            if(slow == fast){
                break;
            }
        }

        if(fast == null || fast.next == null){
            return null;
        }

        fast = head;

        while(fast != slow){
            fast = fast.next;
            slow = slow.next;
        }

        return fast; // return slow;
    }
}