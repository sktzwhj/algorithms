# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def sumOfLeftLeaves(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        self.left_sum = 0
        self.dfs(root)
        return self.left_sum

    def dfs(self, root):
        if root == None:
            return
        if root.left != None:
            if root.left.left == None and root.left.right == None:
                self.left_sum += root.left.val
            self.dfs(root.left)
        if root.right != None:
            self.dfs(root.right)