class Solution:
    def gameOfLife(self, board):
        """
        :type board: List[List[int]]
        :rtype: void Do not return anything, modify board in-place instead.
        """
        if board is None or len(board) == 0:
            return
        
        m, n = len(board), len(board[0])
        
        for i in range(0, m):
            for j in range(0, n):
                lives = self.liveNeighbors(board, m, n, i, j)
                if board[i][j] == 1 and lives >= 2 and lives <= 3:
                    board[i][j] = 3  # 01 -> 11
                elif board[i][j] == 0 and lives == 3:
                    board[i][j] = 2 # 00 -> 10
        
        for i in range(m):
            for j in range(n):
                board[i][j] >>= 1
        
    def liveNeighbors(self, board, m, n, i, j):
        lives = 0
        for x in range(max(i-1, 0), min(i+1, m-1)+1):
            for y in range(max(j-1, 0), min(j+1, n-1)+1):
                lives += (board[x][y] & 1)
        lives -= (board[i][j] & 1)
        return lives
        