//* https://leetcode.com/problems/maximum-depth-of-binary-tree/description/
//* https://leetcode.com/problems/maximum-depth-of-binary-tree/submissions/898943389/
//* https://www.youtube.com/watch?v=eD3tmO66aBA

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
    int maxDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        else{
            int l = maxDepth(root-> left);
            int r = maxDepth(root-> right);

            return 1 + max(l, r);
        }
    }
};