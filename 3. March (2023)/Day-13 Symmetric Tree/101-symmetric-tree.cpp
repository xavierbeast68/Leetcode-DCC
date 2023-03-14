//* https://leetcode.com/problems/symmetric-tree/
//* https://www.youtube.com/watch?v=nKggNAiEpBE&ab_channel=takeUforward
//* https://www.youtube.com/watch?v=Mao9uzxwvmc
//* https://www.youtube.com/watch?v=lGxQfZ1mujc
//* https://www.geeksforgeeks.org/symmetric-tree-tree-which-is-mirror-image-of-itself/


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
    bool dfs(TreeNode* leftSub, TreeNode* rightSub){

        // leftSub == NULL && rightSub == NULL
        if(!leftSub && !rightSub){
            return true;
        }

        // left && right && leftSub->val == rightSub->val
        if((leftSub != NULL && rightSub != NULL) && (leftSub->val == rightSub->val)){
            return (dfs(leftSub->left, rightSub->right) && dfs(leftSub->right, rightSub->left));
        }

        return false;
    }
    bool isSymmetric(TreeNode* root) {
        return dfs(root->left, root->right);
    }
};