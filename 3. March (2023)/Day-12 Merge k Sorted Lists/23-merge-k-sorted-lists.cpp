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
    ListNode* merge(ListNode *a, ListNode *b){
        // O(n)

        // Iterative Approach->
        // // ListNode *mergeLL = (struct ListNode*) malloc(sizeof(struct ListNode));
        // // mergeLL->val = -1;
        // ListNode *mergeLL = new ListNode(-1);
        // ListNode *temp = mergeLL;

        // while(a != NULL && b != NULL){
        //     if(a->val <= b->val){
        //         temp->next = new ListNode(a->val);
        //         temp = temp->next;
        //         a = a->next;
        //     }
        //     else{
        //         temp->next = new ListNode(b->val);
        //         temp = temp->next;
        //         b = b->next;
        //     }
        // }

        // while(a != NULL){
        //     temp->next = new ListNode(a->val);
        //     temp = temp->next;
        //     a = a->next;
        // }

        // while(b != NULL){
        //     temp->next = new ListNode(b->val);
        //     temp = temp->next;
        //     b = b->next;
        // }

        // return mergeLL->next;



        //* Recursive Approach->
        ListNode *result = NULL;

        if(a == NULL){
            return b;
        }
        else if(b == NULL){
            return a;
        }

        if(a->val <= b->val){
            result = a;
            result->next = merge(a->next, b);
        }
        else{
            result = b;
            result->next = merge(a, b->next);
        }

        return result;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Edge Case->
        if(lists.size() == 0){
            return NULL;
        }

        //* Method-1 -> n/2 passes -> O(n^2)
        // int last = lists.size()-1;
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
        // for(int i = 1; i < lists.size(); ++i){
        //     lists[0] = merge(lists[0], lists[i]);
        // }
        // return lists[0];


        //* Method-3 -> Priority Queue Approach-> O(Nlogk)
        priority_queue<ListNode*, vector<ListNode*>, cmp> queue;
        ListNode *mergedLL = new ListNode(-1);
        ListNode *tail = mergedLL;

        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != NULL) {
                queue.push(lists[i]);
            }
        }

        if (queue.empty()){
            return NULL;
        }

        while (!queue.empty()) {
            ListNode *temp = queue.top();
            queue.pop();

            tail->next = temp;
            tail = tail->next;

            if (temp->next != NULL) {
                queue.push(temp->next);
            }
        }

        return mergedLL->next;
    }

class cmp{
public:
    bool operator() (ListNode* a, ListNode* b){
        return a->val > b->val;
    }
};
};