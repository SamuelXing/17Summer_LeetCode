class Solution:
    def exist(self, board, word):
        """
        :type board: List[List[str]]
        :type word: str
        :rtype: bool
        """
        if word == '':
            return True
        if board == []:
            return False
        
        m, n = len(board), len(board[0])
        visited = [[False for j in range(n)] for i in range(m)]
        
        # dfs
        for i in range(m):
            for j in range(n):
                if self.helper(board, word, visited, i, j):
                    return True
        return False
    
    def helper(self, board, word, visited, row, col):
        if word == '':
            return True
        m, n = len(board), len(board[0])
        
        if row < 0 or row >= m or col < 0 or col >= n:
            return False
        if board[row][col] == word[0] and not visited[row][col]:
            visited[row][col] = True
            
            if self.helper(board, word[1:], visited, row-1, col) or self.helper(board, word[1:], visited, row, col-1) or self.helper(board, word[1:], visited, row+1, col) or self.helper(board, word[1:], visited, row, col+1):
                return True
            else:
                visited[row][col] = False
        return False
        