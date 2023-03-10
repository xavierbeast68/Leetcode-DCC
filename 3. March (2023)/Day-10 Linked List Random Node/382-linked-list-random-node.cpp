//* https://leetcode.com/problems/linked-list-random-node/description/
//* https://www.youtube.com/watch?v=qQDM1J02Sq4
//* https://www.youtube.com/watch?v=FoHIX3URFaM
//* https://www.geeksforgeeks.org/select-a-random-node-from-a-singly-linked-list/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> vec;
    void pushing(ListNode* head){
        ListNode *temp = head;
        while(temp != NULL){
            vec.push_back(temp->val);
            temp = temp->next;
        }
    }
    Solution(ListNode* head) {
        pushing(head);
    }
    
    int getRandom() {
        int sz = vec.size();
        int random = rand() % sz;

        return vec[random];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */