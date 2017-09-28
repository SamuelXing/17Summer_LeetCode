/*

You are given a m x n 2D grid initialized with these three possible values.

-1 - A wall or an obstacle.
0 - A gate.
INF - Infinity means an empty room. We use the value 2^31 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.
Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.

Example
Given the 2D grid:

INF  -1  0  INF
INF INF INF  -1
INF  -1 INF  -1
  0  -1 INF INF
return the result:

  3  -1   0   1
  2   2   1  -1
  1  -1   2  -1
  0  -1   3   4

*/

// Notes: thinking about BFS

class Solution {
public:
    static const int INF = 2147483647;
    int m, n;
    /*
     * @param rooms: m x n 2D grid
     * @return: nothing
     */
    void wallsAndGates(vector<vector<int>> &rooms) {
        // write your code here
        int m = rooms.size();
        if(m == 0) return;

        int n = rooms[0].size();

        int to_X[4] = {0, 1, 0, -1};
        int to_Y[4] = {1, 0, -1, 0};

        queue<pair<int, int>> BFSQueue;

        for(int i=0; i< m; i++){
        	for(int j =0; j< n; j++){
        		if(rooms[i][j] == 0)
        			BFSQueue.push({i,j});
        	}
        }

        while(!BFSQueue.empty()){
        	auto head = BFSQueue.front();
        	BFSQueue.pop();
        	int x_pos = head.first;
        	int y_pos = head.second;

        	for(int i=0; i< 4; i++){
        		int x_now = x_pos+to_X[i];
        		int y_now = y_pos+to_Y[i];

        		if(0<= x_now && x_now < m && y_now>=0 && y_now<n 
        			&& rooms[x_now][y_now] == INF){
        			BFSQueue.push({x_now, y_now});
        			rooms[x_now][y_now] = rooms[x_pos][y_pos] + 1;
        		}
        	}
        }

    }
};








