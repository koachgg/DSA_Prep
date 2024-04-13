class Solution {

private :
        void dfs(int row,int col,vector<vector<char>> &grid,vector<vector<int>> &vis,int row0,int col0){
        int n = grid.size();
        int m = grid[0].size();
        vis[row][col] = 1;
        //     // vec.push_back({row-row0,col-col0})
        // vector<int>delrow{-1,0,1,0};
        // vector<int>delcol{0,1,0,-1};
              int delrow[] = {0,0,1,-1,1,-1,1,-1}; //{-1, 0, +1, 0};  
      int delcol[] = {1,-1,0,0,1,-1,-1,1}; //{0, -1, 0, +1}; 
        for (int i = 0; i < 4; i++) {
        int nrow = row + delrow[i];
        int ncol = col + delcol[i];
        // check for valid unvisited land neighbour coordinates 
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
          !vis[nrow][ncol] && grid[nrow][ncol] == '1') {
          dfs(nrow, ncol,grid, vis,row0, col0);
        }
      }
        }

public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));
        set<vector<pair<int,int>>> st;
        int count = 0;

        for(int i =0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    vector<pair<int,int>> vec;
                    dfs(i,j,grid,vis,i,j);
                    count++;
                }
            }
        }
        return count;
    }
};