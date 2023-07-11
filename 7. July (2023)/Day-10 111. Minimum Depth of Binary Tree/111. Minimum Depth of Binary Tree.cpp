//* https://leetcode.com/problems/minimum-depth-of-binary-tree/
//* https://leetcode.com/problems/minimum-depth-of-binary-tree/editorial/


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
    bool isLeaf(TreeNode* root){
        return root->left==NULL && root->right==NULL;
    }
    int minDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        if(isLeaf(root)){
            return 1;
        }
        
        //* DFS
        // int lh = 1e8, rh = 1e8;
        // if(root->left) lh = minDepth(root->left);
        // if(root->right) rh = minDepth(root->right);

        // return (1 + min(lh, rh));


        //* BFS
        queue<TreeNode*> q;
        q.push(root);
        int depth = 0;
        while(!q.empty()){
            int k = q.size();
            depth++;
            for(int i = 0; i < k; i++){
                TreeNode* curr = q.front();
                q.pop();

                if(!curr->left && !curr->right){
                    return depth;
                }

                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
            }
        }

        return -1;
    }
};