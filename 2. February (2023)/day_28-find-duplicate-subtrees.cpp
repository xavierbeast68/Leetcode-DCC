//* https://leetcode.com/problems/find-duplicate-subtrees/description/
//* https://leetcode.com/problems/find-duplicate-subtrees/submissions/906385315/
//* https://www.youtube.com/watch?v=kn0Z5_qPPzY&ab_channel=NeetCodeIO
//* https://www.youtube.com/watch?v=2OBDP3Omi30&ab_channel=CodeFreaks
//* https://www.youtube.com/watch?v=Ya8LifGLUHc&t=141s&ab_channel=DeepCodes

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
    unordered_map<string,int> subTrees;
    vector<TreeNode*> ans;
    string dfs(TreeNode* root){
        if(root == NULL){
            return "";
        }

        string s = to_string(root->val) + "," + dfs(root->left) + "," + dfs(root->right);
        subTrees[s]++;
        if(subTrees[s] == 2){
            ans.push_back(root);
        }

        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        return ans;
    }
};