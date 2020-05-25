/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int doMinimumDifference(struct TreeNode* root, int* pre, int* result){
    if(!root) return 0;
    
    if(root->left) *result = doMinimumDifference(root->left, pre, result);
    
    if(*pre >= 0) *result = fmin(*result, abs(*pre - root->val));
    *pre = root->val;
        
    if(root->right) *result = doMinimumDifference(root->right, pre, result);
    
    return *result;
}

int getMinimumDifference(struct TreeNode* root){
    if(!root) return 0;
    
    int result = INT_MAX, pre = -1;
    
    doMinimumDifference(root, &pre, &result);
        
    return result;
}
