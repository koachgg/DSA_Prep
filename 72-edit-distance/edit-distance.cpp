class Solution {
public:
    
    int dp[501][501];

    int fun(string a, string b, int i, int j)
    {
        if(i<0)
        return j+1; 

        if(j<0)
        return i+1;

        if(dp[i][j]!=-1)
        return dp[i][j];

        if(a[i]==b[j])
        return dp[i][j] = fun(a,b,i-1,j-1);

        else
        return dp[i][j] = 1 + min(fun(a,b,i-1,j), min(fun(a,b,i,j-1),fun(a,b,i-1,j-1))); 
    }

    
    int minDistance(string a, string b) 
    {
        int n = a.size();
        int m = b.size();

        memset(dp,-1,sizeof(dp));
        return fun(a,b,n-1,m-1);   
    }
};