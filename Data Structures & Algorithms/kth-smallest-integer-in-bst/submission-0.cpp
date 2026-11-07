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
    int i,ans;
    void traverse(TreeNode* node, int k){
        if(!node || ans>=0){
            return;
        }
        traverse(node->left,k);
        ++i;
        if(i==k){
            ans = node->val;
            return;
        }
        traverse(node->right,k);
        
        return;

    }

    int kthSmallest(TreeNode* root, int k) {
        i=0;
        ans = -1;
        traverse(root, k);
        return ans;       

    }
};
