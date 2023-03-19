//* https://leetcode.com/problems/check-completeness-of-a-binary-tree/
//* https://www.youtube.com/watch?v=olbiZ-EOSig&t=344s&ab_channel=NeetCodeIO
//* https://www.youtube.com/watch?v=O_EqWFtQ45g&ab_channel=CodeFreaks

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
        bool isCompleteTree(TreeNode* root) {
            queue<TreeNode*> q;
            q.push(root);
            bool f = 0;
    
            while(!q.empty()){
                TreeNode *front = q.front();
                q.pop();
    
                if(front->left){
                    if(f){
                        return false;
                    }
                    q.push(front->left);
                }
                else{
                    f = 1;
                }
    
                if(front->right){
                    if(f){
                        return false;
                    }
                    q.push(front->right);
                }
                else{
                    f = 1;
                }
            }
    
            return true;
        }
    };