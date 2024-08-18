// class Solution {
// public:
//     int minPathSum(vector<vector<int>>& grid) {
//         int n = grid.size();
//         int m =grid[0].size();

//         vector<vector<int>> dp(n+1,vector<int>(m+1,INT_MAX));

//         dp[0][1] = 0;

//         for(int i=1;i<=n;i++){
//             for(int j=1;j<=m;j++){
//                 dp[i][j] = grid[i-1][j-1] + min(dp[i-1][j],dp[i][j-1]);
//             }
//         }
//         return dp[n][m];
//     }
// };

//   // Recursion Code
//   // int find(int i, int j, vector<vector<int>>& grid) {
//   //   if(i == grid.size()-1 && j == grid[0].size()-1) return grid[i][j];
//   //   int x = INT_MAX, y = INT_MAX;
//   //   if(i+1 < grid.size()) x = find(i+1, j, grid);
//   //   if(j+1 < grid[0].size()) y = find(i, j+1, grid);
//   //   return grid[i][j] + min(x, y);
//   // }
  


class Solution{
    public:    
        void Helper(vector<vector<int>> & grid, vector<vector<int>> & dp, int i, int k){            
            int X = grid.size();            
            int Y = grid[0].size();            
            for(int i = 0; i < X; i++){                
                for(k = 0; k < Y; k++){                    
                    if((i - 1 >= 0) && (k - 1 >= 0)){
                        dp[i][k] = grid[i][k] + min(dp[i - 1][k], dp[i][k - 1]);             
                    }
                    else{
                        if(i - 1 >= 0){
                            dp[i][k] = grid[i][k] + dp[i - 1][k];
                        }                        
                        if(k - 1 >= 0){
                            dp[i][k] = grid[i][k] + dp[i][k - 1];
                        }
                    }
                }
            }   
            
        }    
        int minPathSum(vector<vector<int>>& grid){            
            vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size()));            
            dp[0][0] = grid[0][0];            
            Helper(grid, dp, grid.size() - 1, grid[0].size() - 1);            
            return dp[grid.size() - 1][grid[0].size() - 1];        
        }
};
