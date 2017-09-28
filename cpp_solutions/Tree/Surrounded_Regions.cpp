/*
Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O''s into 'X''s in that surrounded region.

Example
X X X X
X O O X
X X O X
X O X X
After capture all regions surrounded by 'X', the board should be:

X X X X
X X X X
X X X X
X O X X

*/

class Solution {
public:
	int m, n;
    /*
     * @param board: board a 2D board containing 'X' and 'O'
     * @return: nothing
     */
    void surroundedRegions(vector<vector<char>> &board) {
        // write your code here
        m = board.size();
        if(m == 0) return;
        n = board[0].size();

        for(int i=0; i<m;i++){
        	bfs(board, i, 0);
        	bfs(board, i, n-1);
        }
        for(int j =0; j<n; j++){
        	bfs(board, 0, j);
        	bfs(board, m-1, j);
        }

        for(int i=0; i<m; i++){
        	for(int j=0; j<n; j++){
        		if(board[i][j] == 'W'){
        			board[i][j] = 'O';
        		}else{
        			board[i][j] = 'X';
        		}
        	}
        }

    }
private:
	void bfs(vector<vector<char>>& board, int sx, int sy){
		if(board[sx][sy]!='O') return;

		int dx[4] = {0, 1, 0, -1};
		int dy[4] = {1, 0, -1, 0};
		
		queue<pair<int, int>> BQ;
		BQ.push({sx, sy});
		board[sx][sy] = 'W';

		while(!BQ.empty()){
			pair<int, int> head = BQ.front();
			BQ.pop();

			for(int i=0; i<4; i++){
				int nx = head.first + dx[i];
				int ny = head.second + dy[i];
				if(0 <= nx && nx < m && 0 <= ny && ny < n
				 && board[nx][ny] == 'O'){
					board[nx][ny] = 'W';
					BQ.push({nx, ny});
				}
			}
		}
	}
};

