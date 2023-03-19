//* https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
//* https://www.youtube.com/watch?v=LgLRTaEMRVc&ab_channel=takeUforward
//* https://www.youtube.com/watch?v=7Z6ivS-TA3k
//* https://www.youtube.com/watch?v=vm63HuIU7kw

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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() == 0 || postorder.size() == 0){
            return NULL;
        }

        TreeNode* root = new TreeNode(postorder.back());
        if(postorder.size() == 1){
            return root;
        }

        int ind = find(begin(inorder), end(inorder), postorder.back()) - inorder.begin();

        vector<int> left_inorder(begin(inorder), begin(inorder) + ind);
        vector<int> right_inorder(begin(inorder) + ind + 1, end(inorder));

        vector<int> left_postorder(begin(postorder), begin(postorder) + ind);
        vector<int> right_postorder(begin(postorder) + ind, end(postorder) - 1);

        root->left = buildTree(left_inorder, left_postorder);
        root->right = buildTree(right_inorder, right_postorder);

        return root;
    }
};