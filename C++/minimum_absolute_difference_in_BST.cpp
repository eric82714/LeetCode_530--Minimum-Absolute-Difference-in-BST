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
    int result = INT_MAX, pre = -1;
    
    int getMinimumDifference(TreeNode* root) {
        if(!root) return 0;
        
        if(root->left) result = getMinimumDifference(root->left);
        
        if(pre >= 0) result = min(result, abs(pre - root->val));
        pre = root->val;
        
        if(root->right) result = getMinimumDifference(root->right);
        
        return result;
    }
};
