// https://leetcode.com/problems/merge-k-sorted-lists/description/
// https://leetcode.com/problems/merge-k-sorted-lists/editorial/
// https://www.geeksforgeeks.org/merge-k-sorted-linked-lists-set-2-using-min-heap/
// https://practice.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
// https://www.codingninjas.com/codestudio/library/merge-k-sorted-linked-lists
// https://www.interviewbit.com/problems/merge-k-sorted-lists/
// https://www.youtube.com/watch?v=7wdont5Bgnk
// https://www.youtube.com/watch?v=RYJ3vs8qx10
// https://www.youtube.com/watch?v=q5a5OiGbT6Q

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
    public ListNode merge(ListNode a, ListNode b){
        // O(n)

        // Iterative Approach->
        ListNode mergeLL = new ListNode(-1);
        ListNode temp = mergeLL;

        while(a != null && b != null){
            if(a.val <= b.val){
                temp.next = new ListNode(a.val);
                temp = temp.next;
                a = a.next;
            }
            else{
                temp.next = new ListNode(b.val);
                temp = temp.next;
                b = b.next;
            }
        }

        while(a != null){
            temp.next = new ListNode(a.val);
            temp = temp.next;
            a = a.next;
        }

        while(b != null){
            temp.next = new ListNode(b.val);
            temp = temp.next;
            b = b.next;
        }

        return mergeLL.next;



        //* Recursive Approach->
        // ListNode result = null;

        // if(a == null){
        //     return b;
        // }
        // else if(b == null){
        //     return a;
        // }

        // if(a.val <= b.val){
        //     result = a;
        //     result.next = merge(a.next, b);
        // }
        // else{
        //     result = b;
        //     result.next = merge(a, b.next);
        // }

        // return result;
    }
    public ListNode mergeKLists(ListNode[] lists) {

        // Edge Case->
        if(lists.length == 0){
            return null;
        }

        //* Method-1 -> n/2 passes -> O(n^2)
        // int last = lists.length-1;
        // while(last != 0){
        //     int i = 0;
        //     int j = last;

        //     while(i < j){
        //         lists[i] = merge(lists[i], lists[j]);
        //         ++i;
        //         --j;
        //         if(i >= j){
        //             last = j;
        //         }
        //     }
        // }
        // return lists[0];

        //* Method-2 -> n passes -> O(n^2)
        // for(int i = 1; i < lists.length; ++i){
        //     lists[0] = merge(lists[0], lists[i]);
        // }
        // return lists[0];

        //* Method-3 -> Priority Queue Approach-> O(Nlogk)
        PriorityQueue<ListNode> queue = new PriorityQueue<>(new ListNodeComparator());
        ListNode mergedLL = new ListNode(-1);
        ListNode tail = mergedLL;

        for (int i = 0; i < lists.length; i++) {
            if (lists[i] != null) {
                queue.add(lists[i]);
            }
        }

        if (queue.isEmpty()){
            return null;
        }

        while (!queue.isEmpty()) {
            ListNode temp = queue.poll();

            tail.next = temp;
            tail = tail.next;

            if (temp.next != null) {
                queue.add(temp.next);
            }
        }


        return mergedLL.next;
    }

    class ListNodeComparator implements Comparator<ListNode> {
        public int compare(ListNode a, ListNode b)
        {
            if (a.val > b.val)
                return 1;
            else if (a.val < b.val)
                return -1;
            return 0;
        }
    }
}