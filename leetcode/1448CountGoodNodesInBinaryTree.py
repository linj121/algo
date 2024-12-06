from collections import deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:

    def goodNodes(self, root: TreeNode) -> int:
        if root is None: return 0
        goodPath: int = 1
        queue = deque([root])
        maxInfo = {root: root.val}
        while queue:
            node = queue.popleft()
            if node.left: 
                queue.append(node.left)
                maxInfo[node.left] = max(maxInfo[node], node.left.val)
                if maxInfo[node.left] == node.left.val: goodPath += 1 
            if node.right:
                queue.append(node.right)
                maxInfo[node.right] = max(maxInfo[node], node.right.val)
                if maxInfo[node.right] == node.right.val: goodPath += 1 
        print(maxInfo)
        return goodPath
    
    def goodNodes(self, r, ma=-10000):
        return self.goodNodes(r.left, max(ma, r.val)) + self.goodNodes(r.right, max(ma, r.val)) + (r.val >= ma) if r else 0
    
    def goodNodes(self, root: TreeNode) -> int:
        if not root:
            return 0
        
        def dfs(node, curMax):
            if not node:
                return
            if node.val >= curMax:
                count += 1
                curMax = node.val
            dfs(node.left, curMax)
            dfs(node.right, curMax)
        
        count = 0
        dfs(root, root.val)
        
        return count[0]
if __name__ == "__main__":
    root = TreeNode(9)
    root.right = TreeNode(3)
    root.right.left = TreeNode(6)
    sol = Solution()
    print(sol.goodNodes(root))
