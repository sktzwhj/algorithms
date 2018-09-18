# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def convertBST(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        self.curr_sum = 0
        if root == None:
            return None
        self.traversal(root)
        return root

    def traversal(self, root):
        if root.right != None:
            self.traversal(root.right)
        root.val += self.curr_sum
        self.curr_sum = root.val
        if root.left != None:
            self.traversal(root.left)
