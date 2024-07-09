class Solution {
public:
    int unique(vector<vector<int>> &dp, int i, int j, int m, int n){
        if(i==(m-1)&&j==(n-1)) return 1;

        if(i>=m || j>=n) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        else {
            return dp[i][j] = unique(dp,i+1,j,m,n) + unique(dp,i,j+1,m,n);
        }
    }

    int uniquePaths(int m, int n) {
        int i=0;
        int j=0;
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return unique(dp,i,j,m,n);
    }
};