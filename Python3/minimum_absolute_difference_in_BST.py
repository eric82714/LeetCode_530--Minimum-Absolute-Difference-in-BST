# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getMinimumDifference(self, root: TreeNode) -> int:
        if not root: return 0
        
        stack = []
        
        def dfs(root):
            if not root: return
            stack.append(root.val)
            dfs(root.left)
            dfs(root.right)
        dfs(root)
        
        stack.sort()
        result = stack[1] - stack[0]
        for i in range(1, len(stack)):
            diff = stack[i] - stack[i-1]
            if diff < result:
                result = diff
        
        return result
