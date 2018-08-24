# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def averageOfLevels(self, root):
        """
        :type root: TreeNode
        :rtype: List[float]
        """
        #use bfs
        curr_level = [root]
        res = []
        while len(curr_level) > 0:
            level_sum = 0
            cnt = len(curr_level)
            next_level = []
            for node in curr_level:
                level_sum += node.val
                if node.left != None:
                    next_level.append(node.left)
                if node.right != None:
                    next_level.append(node.right)
            res.append(float(level_sum)/cnt)
            curr_level = next_level
        return res

