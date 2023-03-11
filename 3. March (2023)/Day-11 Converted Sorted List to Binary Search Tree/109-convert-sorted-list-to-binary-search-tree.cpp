//* https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/description/
//* https://www.youtube.com/watch?v=mbEaJWHtTvQ
//* https://www.geeksforgeeks.org/sorted-linked-list-to-balanced-bst/
//* https://practice.geeksforgeeks.org/problems/sorted-list-to-bst/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
//* https://www.codingninjas.com/codestudio/library/convert-a-sorted-linked-list-to-balanced-bst
//* https://www.codingninjas.com/codestudio/problems/sorted-linked-list-to-balanced-bst_842564


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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* bst(int low, int high, vector<int>& arr){
        if(low > high){
            return NULL;
        }

        int mid = low + (high - low)/2;

        TreeNode *root = new TreeNode(arr[mid]);
        root->left = bst(low, mid - 1, arr);
        root->right = bst(mid + 1, high, arr);

        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> arr;
        
        while(head != NULL){
            arr.push_back(head->val);
            head = head->next;
        }

        int low = 0, high = arr.size() - 1;
        return bst(low, high, arr);
    }
};