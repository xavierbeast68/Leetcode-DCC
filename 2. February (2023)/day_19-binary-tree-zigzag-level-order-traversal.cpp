//* https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
//* https://takeuforward.org/data-structure/zig-zag-traversal-of-binary-tree/
//* https://www.youtube.com/watch?v=3OXWEdlIGl4

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        queue<TreeNode*> q;
        q.push(root);
        bool l2r = true;
        vector<vector<int>> ans;
        while (q.size()) {
            int cnt = q.size();
            vector<int> lv;
            while (cnt--) {
                root = q.front();
                q.pop();
                lv.push_back(root->val);
                if (root->left) q.push(root->left);
                if (root->right) q.push(root->right);
            }
            if (!l2r) reverse(begin(lv), end(lv));
            ans.push_back(lv);
            l2r = !l2r;
        }
        return ans;
    }
};