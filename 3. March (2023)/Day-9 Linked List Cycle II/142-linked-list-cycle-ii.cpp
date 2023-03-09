//* https://leetcode.com/problems/linked-list-cycle-ii/
//* https://www.youtube.com/watch?v=owc1yVJOklw
//* https://www.youtube.com/watch?v=zk6e05dmyNw

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast, *slow;
        fast = slow = head;

        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;

            if(fast == slow){
                break;
            }
        }

        if(!fast || !fast->next){
            // fast == NULL || fast->next == NULL
            return NULL;
        }

        fast = head;
        while(fast != slow){
            fast = fast->next;
            slow = slow->next;
        }

        return fast; // return slow;
    }
};