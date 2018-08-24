"""
# Definition for a Node.
class Node(object):
    def __init__(self, val, children):
        self.val = val
        self.children = children
"""
class Solution(object):
    def preorder(self, root):
        """
        :type root: Node
        :rtype: List[int]
        """
        res = []
        self.traversal(root, res)
        return res

    def traversal(self, root, res):
        if root == None:
            return
        res.append(root.val)
        for child in root.children:
            self.traversal(child, res)
